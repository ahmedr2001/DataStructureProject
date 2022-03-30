#include "Truck.h"

Truck::Truck(Type t, int cap, int ct, int s)
{
	cargolist = new linkedlist<Cargo*>;
	loaded = 0;
	set_Type(t);
	set_Capacity(cap);
	set_Check_Time(ct);
	set_Speed(s);
}

// setters and getters

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
	// derive DI from equation given in the document
	int maxDistance = 0;
	int unloadTimes = 0;
	node<Cargo*>* cargoHead = cargolist->gethead();
	while (cargoHead) {
		maxDistance = max(maxDistance, cargoHead->getdata()->get_Distance());
		unloadTimes += cargoHead->getdata()->get_Load_Time();
	}
	DI = 2 * int(round(double(maxDistance)) / speed) + unloadTimes;
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

// Leave for now

void Truck::LoadFromStreamFile()
{
}

void Truck::OutToStreamFile()
{
}
