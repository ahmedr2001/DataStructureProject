#pragma once
#include"UI.h"
#include"Time.h"

class Cargo
{
protected:
	Time Pre_Time;
	int Load_Time;
	Time Move_Time;
	Time Waiting_Time;
	Time Delivery_Time;
	Type t;
	int Cost;
	int Distance;
	int priority;
public:
	Cargo(Time pt, Time lt,Type t, int c, int d);

	void set_Load_Time(int t);
	void set_Cost(int c);
	void set_Distance(int d);
	void set_Type(Type t);
	void set_Pre_Time(Time t);
	void set_Move_Time(Time t);
	void set_Waiting_Time();
	void set_Delivery_Time(int speed);

	Time get_Delivery_Time();
	int get_Load_Time();
	int get_Cost();
	int get_Distance();
	int getPriority(Time& currentTime);
	Time get_Pre_Time();
	Type get_Type();
	Time get_Move_Time();
	Time get_Waiting_Time();

	void LoadFromStreamFile();
	void OutToStreamFile();

};

