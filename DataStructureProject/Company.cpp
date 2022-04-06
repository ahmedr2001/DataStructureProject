#include "Company.h"
Company::Company()
{
	eventList=new queue<Event*>;

	Cargo_normalWaitingList=new queue<Cargo*>;
	Cargo_specialWaitingList=new queue<Cargo*>;
	Cargo_vipWaitingList = new priority_queue<Cargo*>;

	Cargo_DeliveredList = new queue<Cargo*>;

	Cargo_normalMovingList = new queue<Cargo*>;
	Cargo_specialMovingList = new queue<Cargo*>;
	Cargo_vipMovingList = new queue<Cargo*>;

	Truck_vipWaitingList = new queue<Truck*>;
	Truck_normalWaitingList = new queue<Truck*>;
	Truck_specialWaitingList = new queue<Truck*>;

	queue<Truck*>* Truck_vipMovingList = new queue<Truck*>;
	queue<Truck*>* Truck_normalMovingList = new queue<Truck*>;
	queue<Truck*>* Truck_specialMovingList = new queue<Truck*>;
}
void Company::PrintToConsole(Time t)
{
	string message = "";
	message += ("Current Time (Day:Hour):" + to_string(t.get_Day()) + ":" + to_string(t.get_Hour()) + "\n");
	message += (to_string(Cargo_normalWaitingList->getSize()) + " Waiting Cargos: ");
	message += "[";
	node<Cargo*>** cargoArr = Cargo_normalWaitingList->GetAllNodes();
	int sizeCargoArr = sizeof(cargoArr) / sizeof(cargoArr[0]);
	for (int i = 0; i < sizeCargoArr; i++) {
		message += (to_string(cargoArr[i]->getdata()->get_ID()));
		if (i != sizeCargoArr - 1) {
			message += ",";
		}
	}
	message += "]";
	uiObject->PrintMessage(message);
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
		Truck_normalWaitingList->enqueue(tk1);
		break;
	case special:
		tk2 = new Truck(t, Special_Truck_Cap, Truck_Check_Time, Special_Truck_Speed);
		Truck_specialWaitingList->enqueue(tk2);
		break;
	case VIP:
		tk3 = new Truck(t, Vip_Truck_Cap, Truck_Check_Time, Vip_Truck_Speed);
		Truck_vipWaitingList->enqueue(tk3);
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
			
				e = new Prepare_Event(Event_Time, Cargo_Type,Cargo_ID,Cargo_Dist,Load_Time,Cargo_cost);
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
void Company::Add_New_Cargo(Time pt, int lt,int id, Type t, int cost, int dis) {
	Cargo* newCargoN ;
	Cargo* newCargoS ;
	Cargo* newCargoV ;
	switch (t)
	{
	case Normal:
		newCargoN = new Cargo(pt, lt, id, t, cost, dis);
		Cargo_normalWaitingList->enqueue(newCargoN);
		break;
	case special:
		newCargoS = new Cargo(pt, lt, id, t, cost, dis);
		Cargo_specialWaitingList->enqueue(newCargoS);
		break;
	case VIP:
		newCargoV = new Cargo(pt, lt, id, t, cost, dis);
		Cargo_vipWaitingList->enqueue(newCargoV);
		break;
	default:
		break;
	}
}
Cargo* Company::Remove_Normal_Wating_Cargo(int id)
{
	queue<Cargo*>* templist = new queue<Cargo*>;
	node<Cargo*>* temp = new node<Cargo*>;
	node<Cargo*> tempToBeDeleted;
	while (!Cargo_normalWaitingList->isempty())
	{
		temp->setdata(Cargo_normalWaitingList->peek()->getdata());
		Cargo_normalWaitingList->dequeue();
		if (temp->getdata()->get_ID() == id)
		{
			tempToBeDeleted = *temp;
		}
		else
		{
			templist->enqueue(temp->getdata());
		}
	}
	while (!templist->isempty())
	{
		temp->setdata(templist->peek()->getdata());
		templist->dequeue();
		Cargo_normalWaitingList->enqueue(temp->getdata());
	}
	delete templist;
	return tempToBeDeleted.getdata();
}

bool Company::Execute_Events(Time T) {
	Event* p;
	if (!eventList->isempty())
	{
		p = eventList->peek()->getdata();
		if (p->get_Time()==T)
		{
			p->Execute(this);
			eventList->dequeue();
		}
		if (eventList->peek())
		{
			if (eventList->peek()->getdata()->get_Time() == T)
			{
				Execute_Events(T);
			}
		}
		return false;
	}
	return true;
}

void Company::Moving_WaitingCargo(Type t){
	node<Cargo*>* temp = new node<Cargo*>;
	switch (t)
	{
	case Normal:
		if (!Cargo_normalWaitingList->isempty()) {
			temp->setdata(Cargo_normalWaitingList->peek()->getdata());
			Cargo_normalMovingList->enqueue(temp->getdata());
			Cargo_normalWaitingList->dequeue();
		}
		break;
	case special:
		if (!Cargo_specialWaitingList->isempty()) {
			temp->setdata(Cargo_specialWaitingList->peek()->getdata());
			Cargo_specialMovingList->enqueue(temp->getdata());
			Cargo_specialWaitingList->dequeue();
		}
		break;
	case VIP:
		if (!Cargo_vipWaitingList->isempty()) {
			temp->setdata(Cargo_vipWaitingList->peek()->getdata());
			Cargo_vipMovingList->enqueue(temp->getdata());
			Cargo_vipWaitingList->dequeue();
		}
		break;
	default:
		break;
	}

	delete temp;
}
void Company::Deliver_MovingCargo(Type t){
	node<Cargo*>* temp = new node<Cargo*>;
	switch (t)
	{
	case Normal:
		if (!Cargo_normalMovingList->isempty()) {
			temp->setdata(Cargo_normalMovingList->peek()->getdata());
			Cargo_DeliveredList->enqueue(temp->getdata());
			Cargo_normalMovingList->dequeue();
		}
		break;
	case special:
		if (!Cargo_specialMovingList->isempty()) {
			temp->setdata(Cargo_specialMovingList->peek()->getdata());
			Cargo_DeliveredList->enqueue(temp->getdata());
			Cargo_specialMovingList->dequeue();
		}
		break;
	case VIP:
		if (!Cargo_vipMovingList->isempty()) {
			temp->setdata(Cargo_vipMovingList->peek()->getdata());
			Cargo_DeliveredList->enqueue(temp->getdata());
			Cargo_vipMovingList->dequeue();
		}
		break;
	default:
		break;
	}

	delete temp;
}

void Company::PrintToFile(string filename)
{
	ofstream outFile(filename + ".txt", ios::app);
	if (outFile.is_open())
	{
		outFile <<setw(5) << "CDT" << setw(5) << "CID" << setw(5) << "PT" << setw(5) << "WT" << setw(5) << "TID"<<endl;
		while (Cargo_DeliveredList)
		{

		}
	}
}

void Company::addToVIPWaiting(Cargo* myCargo)
{
	Cargo_vipWaitingList->enqueue(myCargo);
}

bool Company::noNormalCargosLeft()
{
	return (Cargo_normalWaitingList->isempty()
		&& Cargo_normalMovingList->isempty());	
}

bool Company::noSpecialCargosLeft()
{
	return (Cargo_specialWaitingList->isempty()
		&& Cargo_specialMovingList->isempty());
}

bool Company::noVIPCargosLeft()
{
	return (Cargo_vipWaitingList->isempty()
		&& Cargo_vipMovingList->isempty());
}

bool Company::noCargosLeft()
{
	return (noNormalCargosLeft()
		&& noSpecialCargosLeft()
		&& noVIPCargosLeft());
}