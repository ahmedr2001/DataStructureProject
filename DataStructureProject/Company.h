#pragma once
#include "Time.h"
#include "Truck.h"
#include "Event.h"
#include "priority_queue.h"

class Company
{
protected:
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

