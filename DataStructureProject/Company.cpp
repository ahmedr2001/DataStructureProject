#include "Company.h"

Company::Company()
{
	eventList=new queue<Event>;

	Cargo_normalWaitingList=new linkedlist<Cargo>;
	Cargo_specialWaitingList=new queue<Cargo>;
	Cargo_vipWaitingList = new priority_queue<Cargo>;

	Cargo_DeliveredList = new queue<Cargo>;

	Cargo_normalLoadingList = new queue<Cargo>;
	Cargo_specialLoadingList = new queue<Cargo>;
	Cargo_vipLoadingList = new queue<Cargo>;

	Truck_vipWaitingList = new queue<Truck>;
	Truck_normalWaitingList = new queue<Truck>;
	Truck_specialWaitingList = new queue<Truck>;

	//Truck_vipMovingList = new linkedlist<Truck>;
	//Truck_normalMovingList = new linkedlist<Truck>;
	//Truck_specialMovingList = new linkedlist<Truck>;

	MovingTrucks = new priority_queue<Truck>;

	Truck_normalMaintenanceList = new queue<Truck>;
	Truck_specialMaintenanceList = new queue<Truck>;
	Truck_VIPMaintenanceList = new queue<Truck>;
	//Truck_vipLoadingList = new queue<Truck>;
	//Truck_normalLoadingList = new queue<Truck>;
	//Truck_specialLoadingList = new queue<Truck>;

	//Truck_vipMovingList = new linkedlist<Truck>;
	//Truck_normalMovingList = new linkedlist<Truck>;
	//Truck_specialMovingList = new linkedlist<Truck>;
}
void Company::PrintToConsole(Time t)
{
	string message = "";
	
	message += ("Current Time (Day:Hour):" + to_string(t.get_Day()) + ":" + to_string(t.get_Hour()) + "\n");
	
	int waitingCargosCount = Cargo_normalWaitingList->getSize()
		+ Cargo_specialWaitingList->getSize()
		+ Cargo_vipWaitingList->getSize();

	message += (to_string(waitingCargosCount) + " Waiting Cargos: ");
	message += "[";
	
	int sizeNormalWaitingCargoArr = 0;
	node<Cargo>* normalWaitingCargoArr = Cargo_normalWaitingList->GetAllNodes(sizeNormalWaitingCargoArr);
	for (int i = 0; i < sizeNormalWaitingCargoArr; i++) {
		message += (to_string(normalWaitingCargoArr[i].getdata()->get_ID()));
		if (i != sizeNormalWaitingCargoArr - 1) {
			message += ",";
		}
	}
	message += "] ";
	
	message += "(";
	int sizeSpecialWaitingCargoArr = 0;
	node<Cargo>* specialWaitingCargoArr = Cargo_specialWaitingList->GetAllNodes(sizeSpecialWaitingCargoArr);
	for (int i = 0; i < sizeSpecialWaitingCargoArr; i++) {
		message += (to_string(specialWaitingCargoArr[i].getdata()->get_ID()));
		if (i != sizeSpecialWaitingCargoArr - 1) {
			message += ",";
		}
	}
	message += ") ";

	message += "{";
	int sizeVIPWaitingCargoArr = 0;
	node<Cargo>* VIPWaitingCargoArr = Cargo_vipWaitingList->GetAllNodes(sizeVIPWaitingCargoArr);
	for (int i = 0; i < sizeVIPWaitingCargoArr; i++) {
		message += (to_string(VIPWaitingCargoArr[i].getdata()->get_ID()));
		if (i != sizeVIPWaitingCargoArr - 1) {
			message += ",";
		}
	}
	message += "} ";

	message += "\n";
	message += "----------------------------------------------------------------------\n";

	/*int movingCargosCount = Cargo_normalMovingList->getSize()
		+ Cargo_specialMovingList->getSize()
		+ Cargo_vipMovingList->getSize();*/

	/*message += (to_string(movingCargosCount) + " Moving Cargos: ");
	
	message += "[";
	int sizeNormalMovingCargoArr = 0;
	node<Cargo>* normalMovingCargoArr = Cargo_normalMovingList->GetAllNodes(sizeNormalMovingCargoArr);
	for (int i = 0; i < sizeNormalMovingCargoArr; i++) {
		message += (to_string(normalMovingCargoArr[i].getdata()->get_ID()));
		if (i != sizeNormalMovingCargoArr - 1) {
			message += ",";
		}
	}
	message += "] ";
	
	message += "(";
	int sizeSpecialMovingCargoArr = 0;
	node<Cargo>* specialMovingCargoArr = Cargo_specialMovingList->GetAllNodes(sizeSpecialMovingCargoArr);
	for (int i = 0; i < sizeSpecialMovingCargoArr; i++) {
		message += (to_string(specialMovingCargoArr[i].getdata()->get_ID()));
		if (i != sizeSpecialMovingCargoArr - 1) {
			message += ",";
		}
	}
	message += ") ";

	message += "{";
	int sizeVIPMovingCargoArr = 0;
	node<Cargo>* VIPMovingCargoArr = Cargo_vipMovingList->GetAllNodes(sizeVIPMovingCargoArr);
	for (int i = 0; i < sizeVIPMovingCargoArr; i++) {
		message += (to_string(VIPMovingCargoArr[i].getdata()->get_ID()));
		if (i != sizeVIPMovingCargoArr - 1) {
			message += ",";
		}
	}
	message += "} ";
	
	message += "\n";
	message += "----------------------------------------------------------------------\n";*/

	int deliveredCargosCount = Cargo_DeliveredList->getSize();

	message += (to_string(deliveredCargosCount) + " Delivered Cargos: ");

	message += "[";
	int sizeDeliveredCargoArr = 0;
	node<Cargo>* deliveredCargoArr = Cargo_DeliveredList->GetAllNodes(sizeDeliveredCargoArr);
	int normalIndex = 0, specialIndex = 0, vipIndex = 0;
	node<Cargo>* deliveredNormalArr = new node<Cargo>[sizeDeliveredCargoArr];
	node<Cargo>* deliveredSpecialArr = new node<Cargo>[sizeDeliveredCargoArr];
	node<Cargo>* deliveredVIPArr = new node<Cargo>[sizeDeliveredCargoArr];
	for (int i = 0; i < sizeDeliveredCargoArr; i++) {
		if (deliveredCargoArr[i].getdata()->get_Type() == Normal) {
			deliveredNormalArr[normalIndex++] = deliveredCargoArr[i];
		}
		if (deliveredCargoArr[i].getdata()->get_Type() == special) {
			deliveredSpecialArr[specialIndex++] = deliveredCargoArr[i];
		}
		if (deliveredCargoArr[i].getdata()->get_Type() == VIP) {
			deliveredVIPArr[vipIndex++] = deliveredCargoArr[i];
		}
	}
	for (int i = 0; i < normalIndex; i++) {
		message += (to_string(deliveredNormalArr[i].getdata()->get_ID()));
		if (i != normalIndex - 1) {
			message += ",";
		}		
	}
	message += "] ";
	
	message += "(";
	for (int i = 0; i < specialIndex; i++) {
		message += (to_string(deliveredSpecialArr[i].getdata()->get_ID()));
		if (i != specialIndex - 1) {
			message += ",";
		}
	}
	message += ") ";

	message += "{";
	for (int i = 0; i < vipIndex; i++) {
		message += (to_string(deliveredVIPArr[i].getdata()->get_ID()));
		if (i != vipIndex - 1) {
			message += ",";
		}
	}
	message += "} \n";

	message += "------------------------------------------------------------------------\n\n";

	uiObject->PrintMessage(message);
}
void Company::add_truck(Type t, int id)
{
	Truck *tk1;
	Truck *tk2;
	Truck *tk3;
	switch(t)
	{
	case Normal:
		tk1 = new Truck(t, Normal_Truck_Cap, normal_check_time, Normal_Truck_Speed, id);
		Truck_normalWaitingList->enqueue(tk1);
		break;
	case special:
		tk2 = new Truck(t, Special_Truck_Cap, special_check_time, Special_Truck_Speed, id);
		Truck_specialWaitingList->enqueue(tk2);
		break;
	case VIP:
		tk3 = new Truck(t, Vip_Truck_Cap, vip_check_time, Vip_Truck_Speed, id);
		Truck_vipWaitingList->enqueue(tk3);
		break;
	default:
		break;
	}
}
void Company::LoadTrucksAndEventsData(string filename)
{
	int load;
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

		inFile >> J;
		inFile >> normal_check_time;
		inFile >> special_check_time;
		inFile >> vip_check_time;

		for (int i = 0; i < Normal_Truck_Num; i++)
		{
			add_truck(Normal, i+1);
		}
		for (int i = 0; i < Special_Truck_Num; i++)
		{
			add_truck(special, i+1);
		}
		for (int i = 0; i < Vip_Truck_Num; i++)
		{
			add_truck(VIP, i+1);
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
				inFile >> load;
				inFile >> Cargo_cost;
			
				e = new Prepare_Event(Event_Time, Cargo_Type,Cargo_ID,Cargo_Dist,load,Cargo_cost);
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
		Cargo_normalWaitingList->add(newCargoN);
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
	Cargo* temp = new Cargo;
	temp->set_ID(id);
	node<Cargo>* tempToBeDeleted = Cargo_normalWaitingList->getpointerto(temp);
	delete temp;
	if (tempToBeDeleted)
	{
		node<Cargo>* x = Cargo_normalWaitingList->deletenode(tempToBeDeleted);
		if (x)
		{
		return x->getdata();
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}

bool Company::Execute_Events(Time T) {
	Event* p;
	Prepare_Event* Q;
	if (!eventList->isempty())
	{
		p = eventList->peek()->getdata();
		if (p->get_Time()==T)
		{
			if (Q = dynamic_cast<Prepare_Event*>(p)) {
				if (Cargo_normalWaitingList->isempty()&&Q->get_Cargo_Type()==Normal) {
					Normal_timer.set_Hour(0);
					Normal_timer.set_Day(0);
				}
				if (Cargo_specialWaitingList->isempty() && Q->get_Cargo_Type() == special) {
					Special_timer.set_Hour(0);
					Special_timer.set_Day(0);
				}
				if (Cargo_vipWaitingList->isempty() && Q->get_Cargo_Type() == VIP) {
					Vip_timer.set_Hour(0);
					Vip_timer.set_Day(0);
				}
			}

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

void Company::Increase_Timers() {
	if (!Cargo_normalWaitingList->isempty()) {
		Normal_timer++;
	}
	if (!Cargo_specialWaitingList->isempty()) {
		Special_timer++;
	}
	if (!Cargo_vipWaitingList->isempty()) {
		Vip_timer++;
	}
}

void Company::AutoPromote(Type t, Time MT)
{
	node<Cargo>* temp = new node<Cargo>;
	if (!Cargo_normalWaitingList->isempty()) {
		temp->setdata(Cargo_normalWaitingList->gethead()->getdata());
		temp->getdata()->set_Move_Time(MT);
		temp->getdata()->setDTPhaseOne(MT);
		temp->getdata()->set_Waiting_Time();
		if (temp->getdata()->get_Waiting_Time().TimeToHours() > AutoP) {
			temp->getdata()->setAutoP(true);
			temp->getdata()->set_Type(VIP);
			Cargo_normalWaitingList->deletenode(Cargo_normalWaitingList->gethead());
			Cargo_vipWaitingList->enqueue(temp->getdata());
		}
	}
}

void Company::MaxWait(Type t, Time T)
{
	bool done = 0;
	linkedlist<Cargo>* CargosToLoad = new linkedlist<Cargo>;
	if (t == Normal) {
		if (!Truck_normalWaitingList->isempty()) {
			while (!done) {
				if (!Cargo_normalWaitingList->isempty()) {
					Cargo* c = Cargo_normalWaitingList->gethead()->getdata();
					node<Cargo>* cargoNode = new node<Cargo>(c);
					c->set_Move_Time(T);
					if (c->get_Waiting_Time().TimeToHours() >= MaxW) {
						CargosToLoad->add(c);
						Cargo_normalWaitingList->deletenode(cargoNode);
					}
					else done = 1;
				}
				else done = 1;
			}
			bool loaded = 0;
			while (!CargosToLoad->isempty()) {
				Cargo* c = CargosToLoad->gethead()->getdata();
				node<Cargo>* cargoNode = new node<Cargo>(c);
				Truck_normalWaitingList->peek()->getdata()->add_Cargo(c);
				c->setTID(Truck_normalWaitingList->peek()->getdata()->getID());
				CargosToLoad->deletenode(cargoNode);
				loaded = 1;
			}
			if (loaded) {
				Truck* truck = Truck_normalWaitingList->peek()->getdata();
				Truck_normalWaitingList->dequeue();
				MovingTrucks->enqueue(truck, 0, 0, 0);
				truck->increaseActiveTime(T);
			}
		}
		else if (!Truck_specialWaitingList->isempty()) {
			while (!done) {
				if (!Cargo_specialWaitingList->isempty()) {
					Cargo* c = Cargo_specialWaitingList->peek()->getdata();
					node<Cargo>* cargoNode = new node<Cargo>(c);
					c->set_Move_Time(T);
					if (c->get_Waiting_Time().TimeToHours() >= MaxW) {
						CargosToLoad->add(c);
						Cargo_specialWaitingList->dequeue();
					}
					else done = 1;
				}
				else done = 1;
			}
			bool loaded = 0;
			while (!CargosToLoad->isempty()) {
				Cargo* c = CargosToLoad->gethead()->getdata();
				node<Cargo>* cargoNode = new node<Cargo>(c);
				Truck_specialWaitingList->peek()->getdata()->add_Cargo(c);
				c->setTID(Truck_specialWaitingList->peek()->getdata()->getID());
				CargosToLoad->deletenode(cargoNode);
				loaded = 1;
			}
			if (loaded) {
				Truck* truck = Truck_specialWaitingList->peek()->getdata();
				Truck_specialWaitingList->dequeue();
				MovingTrucks->enqueue(truck, 0, 0, 0);
				truck->increaseActiveTime(T);
			}
		}
		else {

		}
	}
	else if (t == special) {
		if (!Truck_specialWaitingList->isempty()) {
			while (!done) {
				if (!Cargo_specialWaitingList->isempty()) {
					Cargo* c = Cargo_specialWaitingList->peek()->getdata();
					node<Cargo>* cargoNode = new node<Cargo>(c);
					c->set_Move_Time(T);
					if (c->get_Waiting_Time().TimeToHours() >= MaxW) {
						CargosToLoad->add(c);
						Cargo_specialWaitingList->dequeue();
					}
					else done = 1;
				}
				else done = 1;
			}
			bool loaded = 0;
			while (!CargosToLoad->isempty()) {
				Cargo* c = CargosToLoad->gethead()->getdata();
				node<Cargo>* cargoNode = new node<Cargo>(c);
				Truck_specialWaitingList->peek()->getdata()->add_Cargo(c);
				c->setTID(Truck_specialWaitingList->peek()->getdata()->getID());
				CargosToLoad->deletenode(cargoNode);
				loaded = 1;
			}
			if (loaded) {
				Truck* truck = Truck_specialWaitingList->peek()->getdata();
				Truck_specialWaitingList->dequeue();
				MovingTrucks->enqueue(truck, 0, 0, 0);
				truck->increaseActiveTime(T);
			}
		}
	}
}

void Company::MoveTrucksToCheckup(Time t)
{
	bool done = 0;
	node<Truck>* head = MovingTrucks->peek();
	while (head && !done) {
		Truck* TruckToCheck = head->getdata();
		if (TruckToCheck->getFT() < t || TruckToCheck->getFT() == t) {
			TruckToCheck->incrementJ();
			int j = TruckToCheck->getJ();
			if (j % J) {
				Type truckType = TruckToCheck->get_Type();
				switch (truckType) {
				case Normal:
					Truck_normalWaitingList->enqueue(TruckToCheck);
					break;
				case special:
					Truck_specialWaitingList->enqueue(TruckToCheck);
					break;
				case VIP:
					Truck_vipWaitingList->enqueue(TruckToCheck);
					break;
				default:
					break;
				}
				MovingTrucks->dequeue();
			}
			else {
				Type truckType = TruckToCheck->get_Type();
				switch (truckType) {
				case Normal:
					Truck_normalMaintenanceList->enqueue(TruckToCheck);
					TruckToCheck->setCT(t, normal_check_time);
					break;
				case special:
					Truck_specialMaintenanceList->enqueue(TruckToCheck);
					TruckToCheck->setCT(t, special_check_time);
					break;
				case VIP:
					Truck_VIPMaintenanceList->enqueue(TruckToCheck);
					TruckToCheck->setCT(t, vip_check_time);
					break;
				default:
					break;
				}
				MovingTrucks->dequeue();
			}
		}
		else done = 1;

		head = head->getnext();
	}
}

void Company::MoveCheckupToAvail(Time t)
{
	node<Truck>* normalTruck = Truck_normalMaintenanceList->peek();
	while (normalTruck) {
		Truck* normalTruckData = normalTruck->getdata();
		if (normalTruckData->getCT() < t || normalTruckData->getCT() == t){
			Truck_normalWaitingList->enqueue(normalTruckData);
			Truck_normalMaintenanceList->dequeue();
		}
		else {
			break;
		}
		normalTruck = normalTruck->getnext();
	}
	node<Truck>* specialTruck = Truck_specialMaintenanceList->peek();
	while (specialTruck) {
		Truck* specialTruckData = specialTruck->getdata();
		if (specialTruckData->getCT() < t || specialTruckData->getCT() == t) {
			Truck_specialWaitingList->enqueue(specialTruckData);
			Truck_specialMaintenanceList->dequeue();
		}
		else {
			break;
		}
		specialTruck = specialTruck->getnext();
	}
	node<Truck>* vipTruck = Truck_VIPMaintenanceList->peek();
	while (vipTruck) {
		Truck* vipTruckData = vipTruck->getdata();
		if (vipTruckData->getCT() < t || vipTruckData->getCT() == t) {
			Truck_vipWaitingList->enqueue(vipTruckData);
			Truck_VIPMaintenanceList->dequeue();
		}
		else {
			break;
		}
		vipTruck = vipTruck->getnext();
	}
}

void Company::Moving_WaitingCargo(Type t, Time MT){
	node<Cargo>* temp = new node<Cargo>;
	Time avgWait;
	switch (t)
	{
	case Normal:
		if (!Cargo_normalWaitingList->isempty()) {
			if (/*Normal_timer.get_Hour() >= 5*/1) {
				temp->setdata(Cargo_normalWaitingList->gethead()->getdata());
				temp->getdata()->set_Move_Time(MT);
				temp->getdata()->setDTPhaseOne(MT);
				temp->getdata()->set_Waiting_Time();
				if (temp->getdata()->get_Waiting_Time().TimeToHours() > AutoP) {
					AutoPromote(Normal, MT);
					return Moving_WaitingCargo(VIP, MT);
				}
				Cargo_DeliveredList->enqueue(temp->getdata());
				Cargo_normalWaitingList->deletenode(Cargo_normalWaitingList->gethead());
				Normal_timer.set_Hour(0);
				Normal_timer.set_Day(0);
			}
		}
		break;
	case special:
		if (!Cargo_specialWaitingList->isempty()) {
			if (/*Special_timer.get_Hour() >= 5*/1) {
				temp->setdata(Cargo_specialWaitingList->peek()->getdata());
				temp->getdata()->set_Move_Time(MT);
				temp->getdata()->setDTPhaseOne(MT);
				temp->getdata()->set_Waiting_Time();
				Cargo_DeliveredList->enqueue(temp->getdata());
				Cargo_specialWaitingList->dequeue();
				Special_timer.set_Hour(0);
				Special_timer.set_Day(0);
			}
		}
		break;
	case VIP:
		if (!Cargo_vipWaitingList->isempty()) {
			if (/*Vip_timer.get_Hour() >= 5*/1) {
				temp->setdata(Cargo_vipWaitingList->peek()->getdata());
				temp->getdata()->set_Move_Time(MT);
				temp->getdata()->setDTPhaseOne(MT);
				temp->getdata()->set_Waiting_Time();
				Cargo_DeliveredList->enqueue(temp->getdata());
				Cargo_vipWaitingList->dequeue();
				Vip_timer.set_Hour(0);
				Vip_timer.set_Day(0);
			}
		}
		break;
	default:
		break;
	}

	delete temp;
}

//void Company::Deliver_Timers() {
//	if (!Cargo_normalMovingList->isempty()) {
//		D_N_timer++;
//	}
//	if (!Cargo_specialMovingList->isempty()) {
//		D_S_timer++;
//	}
//	if (!Cargo_vipMovingList->isempty()) {
//		D_V_timer++;
//	}
//}

//void Company::Deliver_MovingCargo(Type t, Time DT){
//	node<Cargo>* temp = new node<Cargo>;
//	switch (t)
//	{
//	case Normal:
//		if (!Cargo_normalMovingList->isempty()  && D_N_timer.get_Hour() == 5 ) {
//			temp->setdata(Cargo_normalMovingList->peek()->getdata());
//			temp->getdata()->setDTPhaseOne(DT);
//			Cargo_DeliveredList->enqueue(temp->getdata());
//			Cargo_normalMovingList->dequeue();
//			D_N_timer.set_Hour(0);
//			D_N_timer.set_Day(0);
//		}
//		break;
//	case special:
//		if (!Cargo_specialMovingList->isempty()  && D_S_timer.get_Hour() == 5 ) {
//			temp->setdata(Cargo_specialMovingList->peek()->getdata());
//			temp->getdata()->setDTPhaseOne(DT);
//			Cargo_DeliveredList->enqueue(temp->getdata());
//			Cargo_specialMovingList->dequeue();
//			D_S_timer.set_Hour(0);
//			D_S_timer.set_Day(0);
//		}
//		break;
//	case VIP:
//		if (!Cargo_vipMovingList->isempty() && D_S_timer.get_Hour() == 5 ) {
//			temp->setdata(Cargo_vipMovingList->peek()->getdata());
//			temp->getdata()->setDTPhaseOne(DT);
//			Cargo_DeliveredList->enqueue(temp->getdata());
//			Cargo_vipMovingList->dequeue();
//			D_V_timer.set_Hour(0);
//			D_V_timer.set_Day(0);
//		}
//		break;
//	default:
//		break;
//	}
//
//	delete temp;
//}

void Company::PrintToFile(string filename, Time t)
{
	ofstream outFile(filename + ".txt", ios::out);
	if (outFile.is_open())
	{
		Time avgWait;
		int cargon = 0;
		int ncargon = 0;
		int scargon = 0;
		int vcargon = 0;
		int autoPCount = 0;
		outFile << "CDT" << setw(7) << "CID" << setw(8) << "PT" << setw(7) << "WT" << setw(8) << "TID" << endl;
		while (!Cargo_DeliveredList->isempty())
		{
			cargon++;
			switch (Cargo_DeliveredList->peek()->getdata()->get_Type())
			{
			case Normal:
				ncargon++;
				break;
			case special:
				scargon++;
				break;
			case VIP:
				vcargon++;
				break;
			}
			Time cdt = Cargo_DeliveredList->peek()->getdata()->getDTPhaseOne();
			outFile << cdt ;
			int id = Cargo_DeliveredList->peek()->getdata()->get_ID();
			outFile << setw(5) << id ;
			Time pt = Cargo_DeliveredList->peek()->getdata()->get_Pre_Time();
			outFile << "     ";
			outFile << pt;
			Time wt = Cargo_DeliveredList->peek()->getdata()->get_Waiting_Time();
			outFile << "     ";
			outFile << wt;
			avgWait += wt;
			bool autoP = Cargo_DeliveredList->peek()->getdata()->getAutoP();
			if (autoP)autoPCount++;
			int tid = Cargo_DeliveredList->peek()->getdata()->getTID();
			outFile << "     ";
			outFile << tid;
			Cargo_DeliveredList->dequeue();
			outFile << endl;
		}
		avgWait /= cargon;
		outFile << "-----------------------------------------------" << endl;
		outFile << "-----------------------------------------------" << endl;
		outFile << "Cargos: " << cargon << " [n: " << ncargon << ", S: " << scargon << ", V: " << vcargon << "]" << endl;
		outFile << "Cargo Avg Wait = ";
		outFile << avgWait << endl;
		int autoPPercentage = (int)round(((double)autoPCount / (ncargon + autoPCount)) * 100);
		outFile << "Auto-promoted Cargos: ";
		outFile << autoPPercentage << "%" << endl;
		outFile << "Trucks: " << Normal_Truck_Num + Special_Truck_Num + Vip_Truck_Num << " [N: " << Normal_Truck_Num
			<< ", S: " << Special_Truck_Num << ", V: " << Vip_Truck_Num << "]\n";
		int totalActiveTime = 0;
		while (!Truck_normalWaitingList->isempty()) {
			Truck* truck = Truck_normalWaitingList->peek()->getdata();
			totalActiveTime += truck->getActiveTime();
			Truck_normalWaitingList->dequeue();
		}
		while (!Truck_specialWaitingList->isempty()) {
			Truck* truck = Truck_specialWaitingList->peek()->getdata();
			totalActiveTime += truck->getActiveTime();
			Truck_specialWaitingList->dequeue();
		}
		while (!Truck_vipWaitingList->isempty()) {
			Truck* truck = Truck_vipWaitingList->peek()->getdata();
			totalActiveTime += truck->getActiveTime();
			Truck_vipWaitingList->dequeue();
		}
		int totalTime = t.TimeToHours();
		int avgActiveTime = (int)(round((double)totalActiveTime/((Normal_Truck_Num+Special_Truck_Num+Vip_Truck_Num)*totalTime))*100);
		outFile << "Avg Active Time = " << avgActiveTime << "%\n";
	}
}

void Company::addToVIPWaiting(Cargo* myCargo)
{
	Cargo_vipWaitingList->enqueue(myCargo);
}

bool Company::noNormalCargosLeft()
{
	return (Cargo_normalWaitingList->isempty()
		/*&& Cargo_normalMovingList->isempty()*/ );
}

bool Company::noSpecialCargosLeft()
{
	return (Cargo_specialWaitingList->isempty()
		/*&& Cargo_specialMovingList->isempty()*/ );
}

bool Company::noVIPCargosLeft()
{
	return (Cargo_vipWaitingList->isempty()
		/*&& Cargo_vipMovingList->isempty()*/ );
}

bool Company::noCargosLeft()
{
	return (noNormalCargosLeft()
		&& noSpecialCargosLeft()
		&& noVIPCargosLeft());
}

UI* Company::GetUIObject()
{
	return uiObject;
}

bool Company::no_Wating_CargosLeft() {
	return(Cargo_normalWaitingList->isempty() &&
		Cargo_specialWaitingList->isempty() &&
		Cargo_vipWaitingList->isempty()) &&
		Truck_normalMaintenanceList->isempty() &&
		Truck_specialMaintenanceList->isempty() &&
		Truck_VIPMaintenanceList->isempty() && 
		MovingTrucks->isempty();
}

//void Company::Simulate()
//{
//	Time t;
//	Company* c1 = new Company();
//	c1->LoadTrucksAndEventsData("megatest++");
//	UI* uiObject = c1->GetUIObject();
//
//	int simMode;
//	uiObject->PrintMessage("Which simulation mode would you like?\n");
//	uiObject->PrintMessage("1-Interactive Mode 2-Step-By-Step Mode 3-Silent Mode\n");
//	uiObject->GetInput(simMode);
//	if (simMode == 2) {
//		bool done = 0;
//		while (!done) {
//			done = c1->Execute_Events(t);
//
//			c1->MaxWait(Normal, t);
//			c1->MaxWait(special, t);
//			c1->AutoPromote(Normal, t);
//			c1->MoveTrucksToCheckup(t);
//			if (t.get_Hour() >= 5 && t.get_Hour() <= 23) {
//				if (t.get_Hour() % 5 == 4) {
//					c1->Moving_WaitingCargo(VIP, t);
//					c1->Moving_WaitingCargo(special, t);
//					c1->Moving_WaitingCargo(Normal, t);
//					//c1->Increase_Timers();
//				}
//			}
//			//if (t.get_Hour() % 5 == 4) {
//			//	c1->Deliver_MovingCargo(VIP, t);
//			//	c1->Deliver_MovingCargo(special, t);
//			//	c1->Deliver_MovingCargo(Normal, t);
//			//	c1->Deliver_Timers();
//			//}
//			//c1->Deliver_Timers();
//
//			done &= c1->noCargosLeft();
//
//			c1->PrintToConsole(t);
//
//			t++;
//			Sleep(10);
//		}
//	}
//	else if (simMode == 1) {
//		char enterKeyPressed;
//		bool done = 0;
//		Time counter(0, 0);
//		bool shipping = false;
//		while (!done) {
//			uiObject->PrintMessage("Press Enter to Continue...\n");
//			uiObject->getLine(&enterKeyPressed, 1);
//
//			done = c1->Execute_Events(t);
//
//			c1->MaxWait(Normal, t);
//			c1->MaxWait(special, t);
//			c1->AutoPromote(Normal, t);
//			c1->MoveTrucksToCheckup(t);
//			if (t.get_Hour() % 5 == 4 && t.get_Hour() >= 5 && t.get_Hour() <= 23) {
//				c1->Moving_WaitingCargo(VIP, t);
//				c1->Moving_WaitingCargo(special, t);
//				c1->Moving_WaitingCargo(Normal, t);
//				//c1->Increase_Timers();
//			}
//			//if (t.get_Hour() % 5 == 4) {
//			//	c1->Deliver_MovingCargo(VIP, t);
//			//	c1->Deliver_MovingCargo(special, t);
//			//	c1->Deliver_MovingCargo(Normal, t);
//			//	c1->Deliver_Timers();
//			//}
//			//c1->Deliver_Timers();
//
//			done &= c1->noCargosLeft();
//
//			c1->PrintToConsole(t);
//
//			t++;
//		}
//	}
//	else {
//		bool done = 0;
//		uiObject->PrintMessage("Silent Mode\nSimulation Starts...\n");
//		while (!done) {
//			done = c1->Execute_Events(t);
//
//			c1->MaxWait(Normal, t);
//			c1->MaxWait(special, t);
//			c1->AutoPromote(Normal, t);
//			c1->MoveTrucksToCheckup(t);
//			if (t.get_Hour() % 5 == 4 && t.get_Hour() >= 5 && t.get_Hour() <= 23) {
//				c1->Moving_WaitingCargo(VIP, t);
//				c1->Moving_WaitingCargo(special, t);
//				c1->Moving_WaitingCargo(Normal, t);
//				//c1->Increase_Timers();
//			}
//			//if (t.get_Hour() % 5 == 4) {
//			//	c1->Deliver_MovingCargo(VIP, t);
//			//	c1->Deliver_MovingCargo(special, t);
//			//	c1->Deliver_MovingCargo(Normal, t);
//			//	c1->Deliver_Timers();
//			//}
//			//c1->Deliver_Timers();
//
//			done &= c1->noCargosLeft();
//
//			t++;
//		}
//		cout << "Simulation ends, Output file created\n";
//	}
//
//	c1->PrintToFile("outtest");
//
//}