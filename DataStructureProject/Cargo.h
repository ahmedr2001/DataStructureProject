#pragma once
#include"UI.h"
class Cargo
{
private:
	// Pre_Time;
	// Load_Time;
	Type t;
	int Cost;
	int Distance;
public:
	Cargo(/*char* pt, int lt,*/ Type t, int c, int d);
	//void set_Load_Time(int t);
	void set_Cost(int c);
	void set_Distance(int d);
	void set_Type(Type t);
	int get_Load_Time();
	int get_Cost();
	int get_Distance();
	Type get_Type();
	void LoadFromStreamFile();
	void OutToStreamFile();
};

