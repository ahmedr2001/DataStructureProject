#include "Time.h"
istream& operator>>(istream& in, Time t)
{
	return in;
}

Time::Time()
	:day(0), hour(0)
{
}

Time::Time(int d, int h)
	: day(d), hour(h)
{
}

Time Time::operator+(int intervalInHours)
{
	return Time();
}

int Time::operator-(Time nextTime)
{
	return 0;
}

Time Time::operator++()
{
	return Time();
}