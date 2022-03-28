#pragma once
#include "Cargo.h"
#include "stack.h"

class Truck
{
private:
	stack<Cargo*>* cargolist; //list of cargo pointers
	int TC; // truck capacity
	int check_time; //maintenance time
	int num_of_journey; // truck needs to perform maintainance after finishing n delivery journeys
	int speed; // speed in km/h
	int DI; // delivery interval
	trucktype tt;
public:

};

