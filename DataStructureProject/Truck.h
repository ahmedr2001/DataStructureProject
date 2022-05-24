#pragma once
#include "Cargo.h"
#include "stack.h"
#include "linkedlist.h"
#include"priority_queue.h"
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
	int ID;
	int cargosDelivered;
	Time DeliverTime;
	Type trucktype; // truck type (vip-normal-special)
	Time finishTime;
	Time moveTime;
	Time checkupEnd;
public:
	Truck(Type t,int cap,int ct,int s, int id); // set type-capacity-check time-speed of truck
	void add_Cargo(Cargo* c); // add cargo to cargolist
	void set_Capacity(int cap); // set max capacity of truck
	void set_Type(Type t); // set type of truck (vip-normal-special)
	void set_Check_Time(int ct); // set maintainance time
	void set_Speed(int s); // set truck speed in km/h
	void set_DI(); // set delivery interval
	void setFT();
	void setMT(Time t);
	void setCT(Time t, int i);
	void incrementJ();
	void increaseActiveTime(Time t);
	void increaseCargosDelivered(int c);
	void setUtil(int util);

	node<Cargo>* HeadCargo();
	int getUtil();
	int getCargosDelivered();
	int getActiveTime();
	Time getCT();
	int getJ();
	int get_Capacity(); // get max capacity of truck
	Type get_Type(); // get type of truck (vip-normal-special)
	int get_Check_Time(); // get maintainance time
	int get_Speed(); // get truck speed in km/h
	int get_DI(); // get delivery interval
	Time getFT() const;
	Time getMT() const;
	int getID();
	int getPriority(int a, int b, int c);
	Time getDeliverTimeOfAllCargos();
	node<Cargo>* getnumofcargos(int& cnt);
	void removeHeadCargo();
	bool Truckisempty();
	linkedlist<Cargo>* getCargolist();
	void LoadFromStreamFile(); // load from .txt file
	void OutToStreamFile(); // output to console


	void LoadAuxiliary();
};