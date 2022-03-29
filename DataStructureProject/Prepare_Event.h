#pragma once
#include "Event.h"
#include"Company.h"
class Prepare_Event :
    public Event
{
	int Cargo_Dist;
	int Load_Time;
	int Cargo_cost;
public:
	Prepare_Event(Time T, int id, int D, int Load_Time, int c);
    void Execute(Company* myComp);
	void set_Cargo_Dist(int d);
	void set_Load_Time(int h);
	void set_Cargo_cost(int c);
	int get_Cargo_Dist() const;
	int get_Load_Time()const;
	int get_Cargo_cost() const;
};

