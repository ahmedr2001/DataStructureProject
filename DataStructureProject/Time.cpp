#include "Time.h"
#include <string>
istream& operator>>(istream& in, Time& t)
{
	string days = ""; 
	string hours = "";
	string input;
	in >> input;
	int i;
	for (i = 0; i < input.length(); i++) {
		if (input[i] == ':')
			break;
		days += input[i];
	}
	i++;
	for (; i < input.length(); i++) {
		hours += input[i];
	}
	t.set_Day(stoi(days));
	t.set_Hour(stoi(hours));
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

void Time::set_Day(int d)
{
	day = d;
}

void Time::set_Hour(int h)
{
	hour = h;
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