/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#include "Processor.h"

Processor::Processor(int processor_id)
{
	this->processor_id = processor_id;
	this->processor_idle = 0;
	this->current_job = Job();
}

int Processor::run(int time)
{
	if (this->current_job.job_id == -1)
	{
		this->processor_idle++;
		return 1; // processor idle
	}
	else
	{
		if (this->current_job.isFinished(time)) {
			return 2; // job finished
		}
		else {
			return 3; // job not finished
		}
	}
}

void Processor::execute(Job job, int time)
{
	this->current_job = job;
	this->current_job.execute(this->processor_id, time);
}