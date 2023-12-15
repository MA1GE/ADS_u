/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#include "Info.h"

Info::Info()
{
	this->sensor_id = -1;
	this->sensor_time = -1;
}

Info::Info(int sensor_id, int sensor_time)
{
	this->sensor_id = sensor_id;
	this->sensor_time = sensor_time;
}

void Info::update(int sensor_id, int sensor_time)
{
this->sensor_id = sensor_id;
	this->sensor_time = sensor_time;
}


