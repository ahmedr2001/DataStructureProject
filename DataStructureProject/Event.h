#pragma once
#include"Time.h"
#include"UI.h"
class Event
{
	Time Event_Time;
	int Cargo_ID;
public:
	Event(Time T, int id);
	virtual void Execute() = 0;
	void set_Time(Time t);
	void set_Cargo_ID(int id);
	Time get_Time() const;
	int get_Cargo_ID() const;
};

