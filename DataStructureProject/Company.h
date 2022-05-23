#pragma once
#include "Time.h"
#include "Truck.h"
#include "Cancel_Event.h"
#include "Prepare_Event.h"
#include "Promote_Event.h"
#include "priority_queue.h"
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

	int J;
	int normal_check_time;
	int special_check_time;

	int vip_check_time;

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

	queue<Event>* eventList;

	linkedlist<Cargo>* Cargo_normalWaitingList;
	queue<Cargo>* Cargo_specialWaitingList;
	priority_queue<Cargo>* Cargo_vipWaitingList;

	queue<Cargo>* Cargo_normalLoadingList;
	queue<Cargo>* Cargo_specialLoadingList;
	queue<Cargo>* Cargo_vipLoadingList;

	queue<Cargo>* Cargo_DeliveredList;

	queue<Truck>* Truck_vipWaitingList;
	queue<Truck>* Truck_specialWaitingList;
	queue<Truck>* Truck_normalWaitingList;


	Truck* Truck_vipLoadingList;
	Truck* Truck_normalLoadingList;
	Truck* Truck_specialLoadingList;

	linkedlist<Truck>* Truck_vipMovingList;
	linkedlist<Truck>* Truck_normalMovingList;
	linkedlist<Truck>* Truck_specialMovingList;

	//linkedlist<Truck>* MovingTrucks;

	queue<Truck>* Truck_normalMaintenanceList;
	queue<Truck>* Truck_specialMaintenanceList;
	queue<Truck>* Truck_VIPMaintenanceList;

	bool noNormalCargosLeft();
	bool noSpecialCargosLeft();
	bool noVIPCargosLeft();

	UI* uiObject;
	
public:
	Company(); //Company constructor
	
	void add_truck(Type t, int id);
	void LoadTrucksAndEventsData(string filename);
	void Add_New_Cargo(Time pt, int lt, int id, Type t, int cost, int dis);// find suitable queue to store cargo
	void MaxWait(Type t, Time T);
	void MoveTrucksToCheckup(Time t);
	void MoveCheckupToAvail(Time t);
	void Moving_WaitingCargo(Type t, Time MT);
	void Deliver_MovingCargo(Type t, Time DT);
	void Ship_Cargo(Time Company_Time);// find suitable truck to ship cargo
	void addToVIPWaiting(Cargo* myCargo);
	bool noCargosLeft();
	bool no_Wating_CargosLeft();
	Cargo* Remove_Normal_Wating_Cargo(int id);
	
	void Collect_statistics();// to create output file
	
	bool Execute_Events(Time T);//Execute the events that should be executed at that hour
	void AutoPromote(Type t, Time MT);
	void PrintToConsole(Time t);
	void PrintToFile(string filename, Time t);

	void Increase_Timers();
	void Deliver_Timers();

	UI* GetUIObject();

	void LoadVIP(Time t);
	void LoadSpecial(Time t);
	void LoadNormal(Time t);

	void Truck_Loading_Moving(Time t);

	void loadcargo(Truck* tk,Time t);

	void Truck_Waiting_Loading(Truck* tk);
};
