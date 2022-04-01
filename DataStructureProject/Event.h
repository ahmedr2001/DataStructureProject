#pragma once
#include"Time.h"
#include"UI.h"
class Company;
class Event
{
protected:
	Time Event_Time;
	int Cargo_ID;
public:
	Event(Time T, int id);
	virtual void Execute(Company* myComp)=0;
	void set_Time(Time t);
	void set_Cargo_ID(int id);
	Time get_Time() const;
	int get_Cargo_ID() const;
};

