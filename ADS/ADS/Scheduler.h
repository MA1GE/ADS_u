/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#pragma once

#include "Processor.h"

class Scheduler {
public:
	int time;
	std::vector<Processor> processors;
	std::vector<Task> tasks;
	std::vector<Task> finishedTasks;
	std::vector<std::vector<bool>> dag;
	std::vector<Job> ready_queue;
	std::vector<std::vector<Info>> info_list;
	std::vector<double> drop_rate;

	Scheduler();
	Scheduler(std::vector<Processor> processors, std::vector<Task> tasks, std::vector<std::vector<bool>> dag);

	void run();

};