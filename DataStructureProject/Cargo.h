#pragma once
#include"UI.h"
#include"Time.h"

class Cargo
{
private:
public:
	Time Pre_Time;
	int Load_Time;
	Type t;
	int Cost;
	int Distance;
	int priority;
public:
	Cargo(Time pt, Time lt,Type t, int c, int d);
	void set_Load_Time(Time t);
	void set_Cost(int c);
	void set_Distance(int d);
	void set_Type(Type t);
	void set_Pre_Time(Time t);
	Time get_Pre_Time();
	int get_Load_Time();
	int get_Cost();
	int get_Distance();
	Type get_Type();
	void LoadFromStreamFile();
	void OutToStreamFile();
	int getPriority(Time& currentTime);
};

