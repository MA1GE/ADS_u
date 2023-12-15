/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#pragma once

#include "Task.h"

class Processor {
public:
	int time;
	int processor_id;
	int processor_idle;
	Job current_job;

	Processor(int processor_id);
	int run(int time);
	void execute(Job job, int time);

};
