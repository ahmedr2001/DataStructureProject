#pragma once
class Time
{
	int day;
	int hour;
public:
	Time();
	Time(int d, int h);
	Time operator+(int intervalInHours);
	int operator-(Time nextTime);
	Time operator++();
};