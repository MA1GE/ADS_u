/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#include "Task.h"

Task::Task()
{
	task_id = -1;
}

Task::Task(int task_id, int priority, int execution_time, int period, std::vector<std::vector<bool>> dag, int sensor_num)
{
	this->task_id = task_id;
	this->job_num = 0;
	this->priority = priority;
	this->execution_time = execution_time;
	this->period = period;
	this->isSensor = false;

	for (int i = 0; i < dag.size(); i++)
	{
		if (dag[i][task_id])
		{
			this->parents.push_back(i);
		}
		if (dag[task_id][i])
		{
			this->children.push_back(i);
		}
	}
	if (this->parents.size() == 0) {
		this->isSensor = true;
		this->isTrigger = true;
		for (int i = 0; i < sensor_num; i++) {
			if(i==task_id)
				Info newInfo = Info::Info(i, 0);
			else
				Info newInfo = Info::Info(i, -1);
		}
	}else{
		for (int i = 0; i < sensor_num; i++) {
			Info newInfo = Info::Info(i, -1);
		}
		for (int i = 0; i < this->parents.size(); i++) {
			this->predecessor.push_back(false);
		}
	}
}

void Task::updateInfo(std::vector<Info> infos, int pretask_id)
{
	for (int i = 0; i < infos.size(); i++) {
		if (infos[i].sensor_time > this->infos[i].sensor_time) {
			this->infos[i] = infos[i];
		}
	}
	for (int i = 0; i < this->parents.size(); i++) {
		if (this->parents[i] == pretask_id) {
			this->predecessor[i] = true;
		}
	}
}

bool Task::isReady(int time)
{
	if (!this->isSensor) {
		for (int i = 0; i < this->predecessor.size(); i++) {
			if (!this->predecessor[i]) {
				this->isTrigger = false;
			}
		}
		this->isTrigger = true;
	}
	if (this->isTrigger && this->period >= 0) {
		if (this->period > 0) {
			if (time == 0) {
				if (this->isSensor) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				if (time - this->last_release_time == this->period) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}

Job Task::releaseJob(int time)
{
	if (this->isSensor) {
		this->infos[this->task_id].sensor_time = time;
	}

	Job job(this->task_id, this->job_num, this->priority, this->execution_time, time, this->infos);
	this->job_num++;
	this->last_release_time = time;
	this->isTrigger = false;
	for (int i = 0; i < this->predecessor.size(); i++) {
		this->predecessor[i] = false;
	}

	return job;
}

void Task::adjustPriority(int priority)
{
	this->priority = priority;
}

void Task::adjustPeriod(int period)
{
	this->period = period;
}

void Task::adjustExecutionTime(int execution_time)
{
	this->execution_time = execution_time;
}
