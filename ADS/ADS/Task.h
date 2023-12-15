/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#pragma once

#include "Job.h"

class Task {
public:
	int task_id;
	int job_num;
	int priority;
	int execution_time;
	int period;
	int last_release_time;

	bool isSensor;
	bool isTrigger;
	std::vector<Info> infos;

	std::vector<int> parents;
	std::vector<int> children;
	std::vector<bool> predecessor;

	Task();
	Task(int task_id, int priority, int execution_time, int period, std::vector<std::vector<bool>> dag, int sensor_num);

	void updateInfo(std::vector<Info> infos, int pretask_id);
	bool isReady(int time);
	Job releaseJob(int time);

	void adjustPriority(int priority);
	void adjustPeriod(int period);
	void adjustExecutionTime(int execution_time);

};