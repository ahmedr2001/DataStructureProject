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

int Time::get_Day()
{
	return day;
}

int Time::get_Hour()
{
	return hour;
}

Time Time::operator+(int intervalInHours)
{
	return Time();
}

Time Time::operator-(Time nextTime)
{
	return Time();
}

void Time::operator++()
{
	hour = (hour + 1) % 24;
	if (hour == 0) day++;
}

// Time& Time::operator=(Time& t)
// {
// 	day = t.get_Day();
// 	hour = t.get_Hour();
// 	return *this;
// }

int Time::TimeToHours()
{
	int hoursElapsed;
	hoursElapsed = 24 * day + hour;
	return hoursElapsed;
}