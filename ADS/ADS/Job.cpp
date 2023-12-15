/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#include "Job.h"

Job::Job()
{
	this->task_id = -1;
	this->job_id = -1;
	this->priority = -1;
	this->execution_time = -1;
	this->release_time = -1;
	this->execute_time = -1;
	this->finish_time = -1;
	this->processor_id = -1;
}

Job::Job(int task_id, int job_id, int priority, int execution_time, int release_time, std::vector<Info> infos)
{
	this->task_id = task_id;
	this->job_id = job_id;
	this->priority = priority;
	this->execution_time = execution_time;
	this->release_time = release_time;
	this->execute_time = -1;
	this->finish_time = -1;
	this->processor_id = -1;

	this->infos = infos;
}

void Job::execute(int processor_id, int execute_time)
{
	this->processor_id = processor_id;
	this->execute_time = execute_time;
}

bool Job::isFinished(int time)
{
	if (time >= (this->execute_time + this->execution_time)) {
		this->finish_time = time;
		return true;
	}
	else
	{
		return false;
	}
}
