#pragma once
#include "Event.h"
#include"Company.h"

class Prepare_Event :
    public Event
{
	Type t;
	int Cargo_Dist;
	int Load_Time;
	int Cargo_cost;
public:
	Prepare_Event(Time T, Type t,int id, int D, int Load_Time, int c);
    void Execute(Company* myComp);
	void set_Cargo_Dist(int d);
	void set_Load_Time(int h);
	void set_Cargo_cost(int c);
	void set_pre_Time(Time t);
	void set_Type(Type t);

	Time get_pre_Time();
	Type get_Cargo_Type();
	int get_Cargo_Dist() const;
	int get_Load_Time()const;
	int get_Cargo_cost() const;
};

