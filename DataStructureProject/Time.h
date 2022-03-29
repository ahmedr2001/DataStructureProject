#pragma once
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
	Time operator+(int intervalInHours);
	int operator-(Time nextTime);
	Time operator++();
};
istream& operator>>(istream& in, Time& t);
