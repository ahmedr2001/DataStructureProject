#include "Truck.h"

Truck::Truck(Type t, int cap, int ct, int s)
{
	loaded = 0;
	set_Type(t);
	set_Capacity(cap);
	set_Check_Time(ct);
	set_Speed(s);
}

void Truck::add_Cargo(Cargo* c)
{
	if (loaded<Capacity)
	{
		cargolist->add(c);
		loaded++;
	}
}

void Truck::set_Capacity(int cap)
{
	Capacity = cap;
}

void Truck::set_Type(Type t)
{
	trucktype = t;
}

void Truck::set_Check_Time(int ct)
{
	check_time = ct;
}

void Truck::set_Speed(int s)
{
	speed = s;
}

void Truck::set_DI()
{
	// write eq here
}

int Truck::get_Capacity()
{
	return Capacity;
}

Type Truck::get_Type()
{
	return trucktype;
}

int Truck::get_Check_Time()
{
	return check_time;
}

int Truck::get_Speed()
{
	return speed;
}

int Truck::get_DI()
{
	return DI;
}

void Truck::LoadFromStreamFile()
{
}

void Truck::OutToStreamFile()
{
}
