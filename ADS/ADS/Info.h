/*
** (C) Copyright 2023 Ma Jialiang All Rights Reserved.
** Description：Mage project
** Author：Ma Jialiang
** Date: 
** Modify Record:
*/	

#pragma once

#include <vector>
#include <iostream>

class Info {
public:
	int sensor_id;
	int sensor_time;

	Info();
	Info(int sensor_id, int sensor_time);

	void update (int sensor_id, int sensor_time);
};