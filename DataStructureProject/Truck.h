#pragma once
#include "Cargo.h"
#include "stack.h"
#include "linkedlist.h"

class Truck
{
private:
	linkedlist<Cargo>* cargolist; //list of cargo pointers
	int Capacity; // truck capacity
	int loaded; // cargos count
	int check_time; //maintenance time
	int num_of_journey; // truck needs to perform maintainance after finishing n delivery journeys
	int speed; // speed in km/h
	int DI; // delivery interval
	int active_time;
	int utilization;
	Type trucktype; // truck type (vip-normal-special)
public:
	Truck(Type t,int cap,int ct,int s); // set type-capacity-check time-speed of truck
	void add_Cargo(Cargo* c); // add cargo to cargolist
	void set_Capacity(int cap); // set max capacity of truck
	void set_Type(Type t); // set type of truck (vip-normal-special)
	void set_Check_Time(int ct); // set maintainance time
	void set_Speed(int s); // set truck speed in km/h
	void set_DI(); // set delivery interval
	
	int get_Capacity(); // get max capacity of truck
	Type get_Type(); // get type of truck (vip-normal-special)
	int get_Check_Time(); // get maintainance time
	int get_Speed(); // get truck speed in km/h
	int get_DI(); // get delivery interval

	void LoadFromStreamFile(); // load from .txt file
	void OutToStreamFile(); // output to console
};