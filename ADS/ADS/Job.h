/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#pragma once

#include "Info.h"

class Job {
public:
	int task_id;
	int job_id;
	int priority;
	int execution_time;

	int release_time;
	int execute_time;
	int finish_time;
	int processor_id;


	std::vector<Info> infos;

	Job();
	Job(int task_id, int job_id, int priority, int execution_time, int release_time, std::vector<Info> infos);

	void execute(int processor_id, int execute_time);
	bool isFinished(int time);
};