/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#include "Scheduler.h"

Scheduler::Scheduler()
{
	this->time = -1;
}

Scheduler::Scheduler(std::vector<Processor> processors, std::vector<Task> tasks, std::vector<std::vector<bool>> dag)
{
	this->time = 0;
	this->processors = processors;
	this->tasks = tasks;
	this->dag = dag;
	this->ready_queue = std::vector<Job>();
}



int scheduling_PF(std::vector<Job> ready_queue) {
	int scheduling_id = -1;
	
	//现根据priority大小排序,在其中找到release_time最早的赋值到scheduling_id
	for (int i = 0; i < ready_queue.size(); i++) {
		if (ready_queue[i].priority > ready_queue[scheduling_id].priority) {
			scheduling_id = i;
		}
		else if (ready_queue[i].priority == ready_queue[scheduling_id].priority) {
			if (ready_queue[i].release_time < ready_queue[scheduling_id].release_time) {
				scheduling_id = i;
			}
		}
	}
	return scheduling_id;
}

int scheduling_opt(std::vector<Job> ready_queue, std::vector<Task> Task_modes) {
	int scheduling_id = -1;

	return scheduling_id;
}

int scheduling_mid(std::vector<Job> ready_queue, std::vector<Task> Task_modes_old, std::vector<Task> Task_modes_new) {
	int scheduling_id = -1;

	return scheduling_id;
}

void Scheduler::run()
{
	// update ready queue
	for (int i = 0; i < this->tasks.size(); i++)
	{
		if (this->tasks[i].isReady(this->time))
		{
			Job job = this->tasks[i].releaseJob(this->time);
			if (ready_queue.size() > 0) {
				for (int j = 0; j < ready_queue.size(); j++) {
					if (ready_queue[j].task_id == job.task_id) {
						ready_queue[j] = job;
						break;
					}
					if (j == ready_queue.size() - 1) {
						ready_queue.push_back(job);
					}
				}
			}
		}
	}

	// run the processors
	for (int i = 0; i < this->processors.size(); i++)
	{
		int status = this->processors[i].run(this->time);
		if (status == 1) { // processor is idle
			int task_id = scheduling_PF(this->ready_queue);

			if (task_id > -1) {
				Job job = this->ready_queue[task_id];
				this->processors[i].execute(job, this->time);
				// 删除ready_queue中的job
				this->ready_queue.erase(this->ready_queue.begin() + task_id);
			}
		}
		if (status == 2) { // processor has finished the job
			Job job = this->processors[i].current_job;
			this->processors[i].current_job = Job();
			for (int j = 0; j < this->dag[job.task_id].size(); j++)
			{
				if (this->dag[job.task_id][j])
				{
					this->tasks[j].updateInfo(job.infos, this->time);
				}
			}
			if (this->tasks[job.task_id].children.size() == 0) { // task is a sink
				this->info_list.push_back(job.infos);
			}
		}
		if (status == 3) { // processor is running
			// do nothing
		}
	}
	this->time++;
	//end
}

