#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Time
{
	int day;
	int hour;
public:
	Time();
	Time(int d, int h);
	void set_Day(int d);
	void set_Hour(int h);
	int get_Day();
	int get_Hour();
	Time operator+(int intervalInHours);
	Time& operator-(Time nextTime);
	void operator++();
	//Time& operator=(Time& t);
	int TimeToHours();
	bool operator==(Time otherTime);
};
ifstream& operator>>(ifstream& stream, Time& t);
