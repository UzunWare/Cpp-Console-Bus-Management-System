#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Bus_info
{
	Bus_info();
	~Bus_info();
public:
	static void check_Bus_times();
	static void check_departure();
	static int check_available_seats();
	static void check_arrival();
};

