#pragma once
#include "Time.h"
#include "Truck.h"
#include "Cancel_Event.h"
#include "Prepare_Event.h"
#include "Promote_Event.h"
#include "priority_queue.h"
#include "UI.h"
#include <fstream>
#include <string>
#include <iomanip>

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

	int Cargo_cost;
	int Extra_Money;

	Time Normal_timer;//Load Time resets when a new cargo comes & when old cargo moves
	Time Special_timer;//for loading
	Time Vip_timer;//for loading

	Time D_N_timer;//Load Time resets when a new cargo comes & old cargo delivered
	Time D_S_timer;//for loading
	Time D_V_timer;//for loading

	queue<Event*>* eventList;

	linkedlist<Cargo*>* Cargo_normalWaitingList;
	queue<Cargo*>* Cargo_specialWaitingList;
	priority_queue<Cargo*>* Cargo_vipWaitingList;

	queue<Cargo*>* Cargo_normalMovingList;
	queue<Cargo*>* Cargo_specialMovingList;
	queue<Cargo*>* Cargo_vipMovingList;

	queue<Cargo*>* Cargo_DeliveredList;

	queue<Truck*>* Truck_vipWaitingList;
	queue<Truck*>* Truck_normalWaitingList;
	queue<Truck*>* Truck_specialWaitingList;

	queue<Truck*>* Truck_vipMovingList;
	queue<Truck*>* Truck_normalMovingList;
	queue<Truck*>* Truck_specialMovingList;

	bool noNormalCargosLeft();
	bool noSpecialCargosLeft();
	bool noVIPCargosLeft();

	UI* uiObject;
	
public:
	Company(); //Company constructor
	
	void add_truck(Type t);
	void LoadTrucksAndEventsData(string filename);
	void Add_New_Cargo(Time pt, int lt, int id, Type t, int cost, int dis);// find suitable queue to store cargo
	void Moving_WaitingCargo(Type t, Time MT);
	void Deliver_MovingCargo(Type t, Time DT);
	void Ship_Cargo(Time Company_Time);// find suitable truck to ship cargo
	void addToVIPWaiting(Cargo* myCargo);
	bool noCargosLeft();
	bool no_Wating_CargosLeft();
	Cargo* Remove_Normal_Wating_Cargo(int id);
	
	void Collect_statistics();// to create output file
	
	bool Execute_Events(Time T);//Execute the events that should be executed at that hour
	
	void PrintToConsole(Time t);
	void PrintToFile(string filename);

	void Increase_Timers();
	void Deliver_Timers();

	UI* GetUIObject();
};
