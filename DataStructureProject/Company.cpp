#include "Company.h"
void Company::add_truck(Type t)
{
	Truck* tk = new Truck(t, Normal_Truck_Cap, Truck_Check_Time, Normal_Truck_Speed);
	switch(t)
	{
	case Normal:
		normalTruckList->enqueue(tk);
		break;
	case special:
		specialTruckList->enqueue(tk);
		break;
	case VIP:
		vipTruckList->enqueue(tk);
		break;
	default:
		break;
	}
}
void Company::LoadTrucksAndEventsData(string filename)
{
	ifstream inFile(filename + ".txt", ios::in);

	if (inFile.is_open())
	{
		inFile >> Normal_Truck_Num;
		inFile >> Special_Truck_Num;
		inFile >> Vip_Truck_Num;

		inFile >> Normal_Truck_Speed;
		inFile >> Special_Truck_Speed;
		inFile >> Vip_Truck_Speed;

		inFile >> Normal_Truck_Cap;
		inFile >> Special_Truck_Cap;
		inFile >> Vip_Truck_Cap;

		inFile >> Normal_journey_Num;
		inFile >> Special_journey_Num;
		inFile >> Vip_journey_Num;
		inFile >> Truck_Check_Time;

		for (int i = 0; i < Normal_Truck_Num; i++)
		{
			add_truck(Normal);
		}
		for (int i = 0; i < Special_Truck_Num; i++)
		{
			add_truck(special);
		}
		for (int i = 0; i < Vip_Truck_Num; i++)
		{
			add_truck(VIP);
		}

		inFile >> AutoP;
		inFile >> MaxW;

		inFile >> Event_Num;

		Event* e=nullptr;
		for (int i = 0; i < Event_Num; i++)
		{
			inFile >> Event_Type;
			if (Event_Type == 'R')
			{
				int type;
				inFile >> type;
				Cargo_Type = (Type)type;
				inFile >> Event_Time;
				inFile >> Cargo_ID;
				inFile >> Cargo_Dist;
				inFile >> Load_Time;
				inFile >> Cargo_cost;
				e = new Prepare_Event(Event_Time,Cargo_ID,Cargo_Dist,Load_Time,Cargo_cost);
			}
			else if (Event_Type == 'X')
			{
				inFile >> Event_Time;
				inFile >> Cargo_ID;
				e = new Cancel_Event(Event_Time, Cargo_ID);
			}
			else if (Event_Type == 'P')
			{
				inFile >> Event_Time;
				inFile >> Cargo_ID;
				inFile >> Extra_Money;
				e = new Promote_Event(Event_Time,Cargo_ID,Extra_Money);
			}
			eventList->enqueue(e);
		}
	}
}
void Company::PrintStatistics(string filename)
{
	
}