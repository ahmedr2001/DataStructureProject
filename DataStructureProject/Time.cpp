#include "Time.h"
#include <string>

ifstream& operator>>(ifstream& stream, Time& t)
{
	string days = ""; 
	string hours = "";
	string input;
	stream >> input;
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
	return stream;
}

ofstream& operator<<(ofstream& stream, Time& t)
{
	stream << t.get_Day() << ":" << t.get_Hour();
	return stream;
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
	hour = (intervalInHours % 24 + hour) % 24;
	day = intervalInHours / 24 + day;
	if (hour == 0)day++;
	return Time();
}

Time& Time::operator-(Time nextTime)
{
	if (nextTime.get_Hour() > hour) {
		day = day - nextTime.get_Day() - 1;
		hour = hour - nextTime.get_Hour() + 24;
	}
	else { day = day - nextTime.get_Day(); 
	hour = hour - nextTime.get_Hour();
	}

	return *this;
}

void Time::operator++(int)
{
	set_Hour((hour + 1) % 24);
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

bool Time::operator==(Time otherTime)
{
	return (day == otherTime.get_Day() && hour == otherTime.get_Hour());
}

bool Time::operator<(Time otherTime)
{
	return day < otherTime.get_Day();
	if (day == otherTime.get_Day())return hour < otherTime.get_Hour();
}

void Time::operator+=(Time otherTime)
{
	if (hour + otherTime.get_Hour() > 23)day++;
	hour = (hour + otherTime.get_Hour()) % 24;
	day = day + otherTime.get_Day();
}

void Time::operator/=(int n)
{
	int thisTimeInHours = TimeToHours();

	int resInHours = (int)round((double)thisTimeInHours / n);
	day = resInHours / 24;
	hour = resInHours % 24;
}