#pragma once
#include "Time.h"
#include "Truck.h"
#include "Event.h"
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
	int AutoP;
	int MaxW;
	int Event_Num;
	queue<Event*>* eventList;
	queue<Cargo*>* normalWaitingList;
	queue<Cargo*>* specialWaitingList;
	queue<Cargo*>* vipWaitingList;
	queue<Cargo*>* normalMovingList;
	queue<Cargo*>* specialMovingList;
	queue<Cargo*>* vipMovingList;
	queue<Cargo*>* normalDeliveredList;
	queue<Cargo*>* specialDeliveredList;
	queue<Cargo*>* vipDeliveredList;
	queue<Truck*>* vipTruckList;
	queue<Truck*>* normalTruckList;
	queue<Truck*>* specialTruckList;
public:

	void LoadTrucksAndEventsData(string filename);
};

