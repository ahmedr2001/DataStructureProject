#include "Company.h"
Company::Company()
{
	normalTruckList = new queue<Truck*>;
	eventList=new queue<Event*>;
	normalWaitingList=new queue<Cargo*>;
	specialWaitingList=new queue<Cargo*>;
	vipWaitingList = new priority_queue<Cargo*>;
	normalMovingList = new queue<Cargo*>;
	specialMovingList = new queue<Cargo*>;
	vipMovingList = new queue<Cargo*>;
	normalDeliveredList = new queue<Cargo*>;
	specialDeliveredList = new queue<Cargo*>;
	vipDeliveredList = new queue<Cargo*>;
	vipTruckList = new queue<Truck*>;
	normalTruckList = new queue<Truck*>;
	specialTruckList = new queue<Truck*>;
}
void Company::printathing()
{
	cout << Normal_Truck_Cap << endl;
}
void Company::add_truck(Type t)
{
	Truck* tk1;
	Truck* tk2;
	Truck* tk3;
	switch(t)
	{
	case Normal:
		tk1 = new Truck(t, Normal_Truck_Cap, Truck_Check_Time, Normal_Truck_Speed);
		normalTruckList->enqueue(tk1);
		break;
	case special:
		tk2 = new Truck(t, Special_Truck_Cap, Truck_Check_Time, Special_Truck_Speed);
		specialTruckList->enqueue(tk2);
		break;
	case VIP:
		tk3 = new Truck(t, Vip_Truck_Cap, Truck_Check_Time, Vip_Truck_Speed);
		vipTruckList->enqueue(tk3);
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
				char type;
				inFile >> type;
				if (type=='N')
				{
					Cargo_Type = Normal;
				}
				else if (type == 'S')
				{
					Cargo_Type = special;
				}
				else if (type == 'V')
				{
					Cargo_Type = VIP;
				}
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