#pragma once
#include "Time.h"
#include "Truck.h"
#include "Cancel_Event.h"
#include "Prepare_Event.h"
#include "Promote_Event.h"
#include "priority_queue.h"
#include <fstream>

class Company
{
protected:
	int Normal_Truck_Num;
	int Special_Truck_Num;
	int Vip_Truck_Num;

	int Normal_Truck_Speed;
	int Special_Truck_Speed;
	int Vip_Truck_Speed;

	int Normal_Truck_Cap;
	int Special_Truck_Cap;
	int Vip_Truck_Cap;

	int Normal_journey_Num;
	int Special_journey_Num;
	int Vip_journey_Num;

	int Truck_Check_Time;

	int AutoP;
	int MaxW;

	int Event_Num;
	char Event_Type;
	Type Cargo_Type;
	Time Event_Time;
	int Cargo_ID;
	int Cargo_Dist;
	int Load_Time;
	int Cargo_cost;
	int Extra_Money;

	queue<Event*>* eventList;

	queue<Cargo*>* Cargo_normalWaitingList;
	queue<Cargo*>* Cargo_specialWaitingList;
	priority_queue<Cargo*>* Cargo_vipWaitingList;

	queue<Cargo*>* Cargo_normalMovingList;
	queue<Cargo*>* Cargo_specialMovingList;
	queue<Cargo*>* Cargo_vipMovingList;

	queue<Cargo*>* Cargo_normalDeliveredList;
	queue<Cargo*>* Cargo_specialDeliveredList;
	queue<Cargo*>* Cargo_vipDeliveredList;

	queue<Truck*>* Truck_vipWaitingList;
	queue<Truck*>* Truck_normalWaitingList;
	queue<Truck*>* Truck_specialWaitingList;

	queue<Truck*>* Truck_vipMovingList;
	queue<Truck*>* Truck_normalMovingList;
	queue<Truck*>* Truck_specialMovingList;
public:
	Company(); //Company constructor
	void printathing();
	void add_truck(Type t);
	void LoadTrucksAndEventsData(string filename);
	void PrintStatistics(string filename);
	void Add_New_Cargo(Time pt, int lt, int id, Type t, int cost, int dis);// find suitable queue to store cargo
	void Remove_Normal_Wating_Cargo(int id);
	void Ship_Cargo(Truck* T);// find suitable truck to ship cargo
	void Execute_Events(Time T);//Execute the events that should be executed at that hour
	void Collect_statistics();// to create output file
};
