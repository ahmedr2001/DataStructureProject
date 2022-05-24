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

	Truck_vipMovingList = new linkedlist<Truck>;
	Truck_normalMovingList = new linkedlist<Truck>;
	Truck_specialMovingList = new linkedlist<Truck>;

	//MovingTrucks = new linkedlist<Truck>;

	Truck_normalMaintenanceList = new queue<Truck>;
	Truck_specialMaintenanceList = new queue<Truck>;
	Truck_VIPMaintenanceList = new queue<Truck>;
	Truck_vipLoadingList = nullptr;
	Truck_normalLoadingList = nullptr;
	Truck_specialLoadingList = nullptr;

}

void Company::PrintToConsole(Time t)
{
	string message = "";
	
	message += ("Current Time (Day:Hour):" + to_string(t.get_Day()) + ":" + to_string(t.get_Hour()) + "\n");
	//waiting cargo
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


	
	//loading trucks
	
	int loadingCount = 0;
	if (Truck_vipLoadingList)
	{
		loadingCount++;
	}
	if (Truck_normalLoadingList)
	{
		loadingCount++;
	}
	if (Truck_specialLoadingList)
	{
		loadingCount++;
	}

	message += (to_string(loadingCount) + " Loading Trucks: ");

	
	int sizeNormalloadArr = 0;
	int sizeSpecialloadArr = 0;
	int sizeVIPloadArr = 0;
	node<Cargo>* NormalloadArr =nullptr;
	node<Cargo>* SpecialloadArr = nullptr;
	node<Cargo>* VIPloadArr = nullptr;

	message += to_string(Truck_normalLoadingList?Truck_normalLoadingList->getID():0);
	message += "[";
	if (Truck_normalLoadingList)
	{
		NormalloadArr = Truck_normalLoadingList->getnumofcargos(sizeNormalloadArr);
	}

	for (int i = 0; i < sizeNormalloadArr; i++) {
			message += (to_string(NormalloadArr[i].getdata()->get_ID()));
			if (i != sizeNormalloadArr - 1) {
				message += ",";
			}
	}
	message += "] ";

	message += to_string(Truck_specialLoadingList ? Truck_specialLoadingList->getID() : 0);
	message += "(";
	if (Truck_specialLoadingList)
	{
		SpecialloadArr = Truck_specialLoadingList->getnumofcargos(sizeSpecialloadArr);
	}
	for (int i = 0; i < sizeSpecialloadArr; i++) {
		message += (to_string(SpecialloadArr[i].getdata()->get_ID()));
		if (i != sizeSpecialloadArr - 1) {
			message += ",";
		}
	}
	message += ") ";

	message += to_string(Truck_vipLoadingList ? Truck_vipLoadingList->getID() : 0);
	message += "{";
	if (Truck_vipLoadingList)
	{
		VIPloadArr = Truck_vipLoadingList->getnumofcargos(sizeVIPloadArr);
	}
	for (int i = 0; i < sizeVIPloadArr; i++) {
		message += (to_string(VIPloadArr[i].getdata()->get_ID()));
		if (i != sizeVIPloadArr - 1) {
			message += ",";
		}
	}
	message += "} \n";

	message += "------------------------------------------------------------------------\n";

	
	//Empty Trucks
	
	int EmptytrucksCount = Truck_vipWaitingList->getSize()
		+ Truck_normalWaitingList->getSize()
		+ Truck_specialWaitingList->getSize();

	message += (to_string(EmptytrucksCount) + " Empty Trucks: ");
	message += "[";

	int sizeNormalEmptyTruckArr = 0;
	node<Truck>* normalEmptyTruckArr = Truck_normalWaitingList->GetAllNodes(sizeNormalEmptyTruckArr);
	for (int i = 0; i < sizeNormalEmptyTruckArr; i++) {
		message += (to_string(normalEmptyTruckArr[i].getdata()->getID()));
		if (i != sizeNormalEmptyTruckArr - 1) {
			message += ",";
		}
	}
	message += "] ";

	message += "(";

	int sizeSpecialEmptyTruckArr = 0;
	node<Truck>* SpecialEmptyTruckArr = Truck_specialWaitingList->GetAllNodes(sizeSpecialEmptyTruckArr);
	for (int i = 0; i < sizeSpecialEmptyTruckArr; i++) {
		message += (to_string(SpecialEmptyTruckArr[i].getdata()->getID()));
		if (i != sizeSpecialEmptyTruckArr - 1) {
			message += ",";
		}
	}
	message += ") ";

	message += "{";

	int sizeVIPEmptyTruckArr = 0;
	node<Truck>* VIPEmptyTruckArr = Truck_vipWaitingList->GetAllNodes(sizeVIPEmptyTruckArr);
	for (int i = 0; i < sizeVIPEmptyTruckArr; i++) {
		message += (to_string(VIPEmptyTruckArr[i].getdata()->getID()));
		if (i != sizeVIPEmptyTruckArr - 1) {
			message += ",";
		}
	}
	message += "} ";

	message += "\n";
	message += "----------------------------------------------------------------------\n";

	//moving cargo

	int sizeNormalmoveArr = 0;
	int sizeSpecialmoveArr = 0;
	int sizeVIPmoveArr = 0;
	node<Truck>* NormalmoveArr = nullptr;
	node<Truck>* SpecialmoveArr = nullptr;
	node<Truck>* VIPmoveArr = nullptr;
	int n = 0;

	if (Truck_normalMovingList)
	{
		NormalmoveArr = Truck_normalMovingList->GetAllNodes(sizeNormalmoveArr);
		n += sizeNormalmoveArr;
	}
	if (Truck_specialMovingList)
	{
		SpecialmoveArr = Truck_specialMovingList->GetAllNodes(sizeSpecialmoveArr);
		n += sizeSpecialmoveArr;
	}
	if (Truck_vipMovingList)
	{
		VIPmoveArr = Truck_vipMovingList->GetAllNodes(sizeVIPmoveArr);
		n += sizeVIPmoveArr;
	}
	message += (to_string(n) + " Moving Cargos: ");
	for (int i = 0; i < sizeNormalmoveArr; i++)
	{
		int csizeNormalmoveArr = 0;
		node<Cargo>* cNormalmoveArr = NormalmoveArr[i].getdata()->getnumofcargos(csizeNormalmoveArr);
		message += to_string(NormalmoveArr[i].getdata()->getID());
		message += "[";
		for (size_t i = 0; i < csizeNormalmoveArr; i++)
		{
			message += to_string(cNormalmoveArr[i].getdata()->get_ID());
			if (i != csizeNormalmoveArr - 1) {
				message += ",";
			}
		}
		message += "] ";
	}

	for (int i = 0; i < sizeSpecialmoveArr; i++)
	{
		int csizeSpecialmoveArr = 0;
		node<Cargo>* cSpecialmoveArr = SpecialmoveArr[i].getdata()->getnumofcargos(csizeSpecialmoveArr);
		message += to_string(SpecialmoveArr[i].getdata()->getID());
		message += "(";
		for (size_t i = 0; i < csizeSpecialmoveArr; i++)
		{
			message += to_string(cSpecialmoveArr[i].getdata()->get_ID());
			if (i != csizeSpecialmoveArr - 1) {
				message += ",";
			}
		}
		message += ") ";
	}

	for (int i = 0; i < sizeVIPmoveArr; i++)
	{
		int csizeVIPmoveArr = 0;
		node<Cargo>* cVIPmoveArr = VIPmoveArr[i].getdata()->getnumofcargos(csizeVIPmoveArr);
		message += to_string(VIPmoveArr[i].getdata()->getID());
		message += "{";
		for (size_t i = 0; i < csizeVIPmoveArr; i++)
		{
			message += to_string(cVIPmoveArr[i].getdata()->get_ID());
			if (i != csizeVIPmoveArr - 1) {
				message += ",";
			}
		}
		message += "} ";
	}
	message += "\n";
	message += "------------------------------------------------------------------------\n";
	//in-checkup trucks

	int incheckupCount = Truck_normalMaintenanceList->getSize()+ Truck_specialMaintenanceList->getSize()+ Truck_VIPMaintenanceList->getSize();

	message += (to_string(incheckupCount) + " In-Checkup Trucks: ");

	message += "[";
	int sizeNormalmainArr = 0;
	int sizeSpecialmainArr = 0;
	int sizeVIPmainArr = 0;
	node<Truck>* NormalmainArr = Truck_normalMaintenanceList->GetAllNodes(sizeNormalmainArr);
	node<Truck>* SpecialmainArr = Truck_specialMaintenanceList->GetAllNodes(sizeSpecialmainArr);
	node<Truck>* VIPmainArr = Truck_VIPMaintenanceList->GetAllNodes(sizeVIPmainArr);
	
	for (int i = 0; i < sizeNormalmainArr; i++) {
			message += (to_string(NormalmainArr[i].getdata()->getID()));
			if (i != sizeNormalmainArr - 1) {
				message += ",";
			}
	}
	message += "] ";
	
	message += "(";
	for (int i = 0; i < sizeSpecialmainArr; i++) {
		message += (to_string(SpecialmainArr[i].getdata()->getID()));
		if (i != sizeSpecialmainArr - 1) {
			message += ",";
		}
	}
	message += ") ";

	message += "{";
	for (int i = 0; i < sizeVIPmainArr; i++) {
		message += (to_string(VIPmainArr[i].getdata()->getID()));
		if (i != sizeVIPmainArr - 1) {
			message += ",";
		}
	}
	message += "} \n";

	message += "------------------------------------------------------------------------\n";

	//delivered cargo
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
			add_truck(special, i+1+Normal_Truck_Num);
		}
		for (int i = 0; i < Vip_Truck_Num; i++)
		{
			add_truck(VIP, i+1+Normal_Truck_Num+Special_Truck_Num);
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
		bool check = 0;
		bool loaded = 0;
		if (!Truck_normalWaitingList->isempty()) {
			node<Cargo>* headPtr = Cargo_normalWaitingList->gethead();
			while (!done) {
				if (headPtr) {
					node<Cargo>* cargoNode = headPtr;
					Cargo* c = cargoNode->getdata();
					c->set_Move_Time(T);
					c->set_Waiting_Time();
					if (c->get_Waiting_Time().TimeToHours() >= MaxW) {
						CargosToLoad->add(c);
						//Cargo_normalWaitingList->deletenode(cargoNode);
						headPtr = headPtr->getnext();
						check = 1;
					}
					else done = 1;
				}
				else done = 1;
			}
			if (!Truck_normalLoadingList) {
				int cnt = CargosToLoad->getSize();
				while (!CargosToLoad->isempty()) {
					node<Cargo>* cargoNode = CargosToLoad->gethead();
					Cargo* c = cargoNode->getdata();
					c->setTID(Truck_normalWaitingList->peek()->getdata()->getID());
					Truck_normalWaitingList->peek()->getdata()->add_Cargo(c);
					CargosToLoad->deletenode(cargoNode);
					loaded = 1;
				}
				if (loaded) {
					Truck* truck = Truck_normalWaitingList->peek()->getdata();
					//MovingTrucks->add(truck);
					Truck_normalLoadingList = truck;
					truck->increaseActiveTime(T);
					truck->increaseCargosDelivered(cnt);
					Truck_normalWaitingList->dequeue();	
					for (int i = 0; i < cnt; i++) {
						Cargo_normalWaitingList->deletenode(Cargo_normalWaitingList->gethead());
					}
				}
			}
		}
		if (!loaded && !Truck_specialWaitingList->isempty()) {
			if (!check) {
				bool done2 = 0;
				node<Cargo>* headPtr = Cargo_normalWaitingList->gethead();
				while (!done2) {
					if (headPtr) {
						node<Cargo>* cargoNode = headPtr;
						Cargo* c = cargoNode->getdata();
						c->set_Move_Time(T);
						c->set_Waiting_Time();
						if (c->get_Waiting_Time().TimeToHours() >= MaxW) {
							CargosToLoad->add(c);
							headPtr = headPtr->getnext();
						}
						else done2 = 1;
					}
					else done2 = 1;
				}
			}
			if (!Truck_specialLoadingList) {
				bool loaded2 = 0;
				int cnt = CargosToLoad->getSize();
				while (!CargosToLoad->isempty()) {
					node<Cargo>* cargoNode = CargosToLoad->gethead();
					Cargo* c = cargoNode->getdata();
					c->setTID(Truck_specialWaitingList->peek()->getdata()->getID());
					Truck_specialWaitingList->peek()->getdata()->add_Cargo(c);
					CargosToLoad->deletenode(cargoNode);
					loaded2 = 1;
				}
				if (loaded2) {
					Truck* truck = Truck_specialWaitingList->peek()->getdata();
					Truck_specialLoadingList = truck;
					truck->increaseActiveTime(T);
					truck->increaseCargosDelivered(cnt);
					Truck_specialWaitingList->dequeue();
					for (int i = 0; i < cnt; i++) {
						Cargo_normalWaitingList->deletenode(Cargo_normalWaitingList->gethead());
					}
				}
			}
		}
		else {

		}
	}
	else if (t == special) {
		if (!Truck_specialWaitingList->isempty()) {
			node<Cargo>* headPtr = Cargo_specialWaitingList->peek();
			while (!done) {
				if (headPtr) {
					Cargo* c = headPtr->getdata();
					c->set_Move_Time(T);
					c->set_Waiting_Time();
					if (c->get_Waiting_Time().TimeToHours() >= MaxW) {
						CargosToLoad->add(c);
						headPtr = headPtr->getnext();
					}
					else done = 1;
				}
				else done = 1;
			}
			if (!Truck_specialLoadingList) {
				bool loaded = 0;
				int cnt = CargosToLoad->getSize();
				while (!CargosToLoad->isempty()) {
					node<Cargo>* cargoNode = CargosToLoad->gethead();
					Cargo* c = cargoNode->getdata();
					c->setTID(Truck_specialWaitingList->peek()->getdata()->getID());
					Truck_specialWaitingList->peek()->getdata()->add_Cargo(c);
					CargosToLoad->deletenode(cargoNode);
					loaded = 1;
				}
				if (loaded) {
					Truck* truck = Truck_specialWaitingList->peek()->getdata();
					Truck_specialLoadingList = truck;
					truck->increaseActiveTime(T);
					truck->increaseCargosDelivered(cnt);
					Truck_specialWaitingList->dequeue();
					for (int i = 0; i < cnt; i++) {
						Cargo_specialWaitingList->dequeue();
					}
				}
			}
		}
	}
}

void Company::MoveTrucksToCheckup(Time t)
{
	bool done = 0;
	bool done2 = 0;
	bool done3 = 0;
	node<Truck>* headSpecial = Truck_specialMovingList->gethead();
	node<Truck>* headVIP = Truck_vipMovingList->gethead();
	node<Truck>* head = Truck_normalMovingList->gethead();
	while (head && !done) {
		Truck* TruckToCheck = head->getdata();
		if (TruckToCheck->getFT() < t || TruckToCheck->getFT() == t) {
			TruckToCheck->incrementJ();
			int j = TruckToCheck->getJ();
			if (j % J) {
				Truck_normalWaitingList->enqueue(TruckToCheck);
			}
			else {
				Truck_normalMaintenanceList->enqueue(TruckToCheck);
				TruckToCheck->setCT(t, normal_check_time);
			}
			node<Truck>* del = head;
			head = head->getnext();
			Truck_normalMovingList->deletenode(del);
		}
		else done = 1;
	}
	while (headSpecial && !done2) {
		Truck* TruckToCheck = headSpecial->getdata();
		if (TruckToCheck->getFT() < t || TruckToCheck->getFT() == t) {
			TruckToCheck->incrementJ();
			int j = TruckToCheck->getJ();
			if (j % J) {
				Truck_specialWaitingList->enqueue(TruckToCheck);
			}
			else {
				Truck_specialMaintenanceList->enqueue(TruckToCheck);
				TruckToCheck->setCT(t, special_check_time);
			}
			node<Truck>* del = headSpecial;
			headSpecial = headSpecial->getnext();
			Truck_specialMovingList->deletenode(del);
		}
		else done2 = 1;
	}
	while (headVIP && !done3) {
		Truck* TruckToCheck = headVIP->getdata();
		if (TruckToCheck->getFT() < t || TruckToCheck->getFT() == t) {
			TruckToCheck->incrementJ();
			int j = TruckToCheck->getJ();
			if (j % J) {
				Truck_vipWaitingList->enqueue(TruckToCheck);
			}
			else {
				Truck_VIPMaintenanceList->enqueue(TruckToCheck);
				TruckToCheck->setCT(t, vip_check_time);
			}
			node<Truck>* del = headVIP;
			headVIP = headVIP->getnext();
			Truck_vipMovingList->deletenode(del);
		}
		else done3 = 1;
	}
}

void Company::MoveCheckupToAvail(Time t)
{
	node<Truck>* normalTruck = Truck_normalMaintenanceList->peek();
	while (normalTruck) {
		Truck* normalTruckData = normalTruck->getdata();
		if (normalTruckData->getCT() < t || normalTruckData->getCT() == t){
			Truck_normalWaitingList->enqueue(normalTruckData);
			normalTruck = normalTruck->getnext();
			Truck_normalMaintenanceList->dequeue();
		}
		else {
			break;
		}
	}
	node<Truck>* specialTruck = Truck_specialMaintenanceList->peek();
	while (specialTruck) {
		Truck* specialTruckData = specialTruck->getdata();
		if (specialTruckData->getCT() < t || specialTruckData->getCT() == t) {
			Truck_specialWaitingList->enqueue(specialTruckData);
			specialTruck = specialTruck->getnext();
			Truck_specialMaintenanceList->dequeue();
		}
		else {
			break;
		}
	}
	node<Truck>* vipTruck = Truck_VIPMaintenanceList->peek();
	while (vipTruck) {
		Truck* vipTruckData = vipTruck->getdata();
		if (vipTruckData->getCT() < t || vipTruckData->getCT() == t) {
			Truck_vipWaitingList->enqueue(vipTruckData);
			vipTruck = vipTruck->getnext();
			Truck_VIPMaintenanceList->dequeue();
		}
		else {
			break;
		}
	}
}

//void Company::Moving_WaitingCargo(Type t, Time MT){
//	node<Cargo>* temp = new node<Cargo>;
//	Time avgWait;
//	switch (t)
//	{
//	case Normal:
//		if (!Cargo_normalWaitingList->isempty()) {
//			if (1) {
//				temp->setdata(Cargo_normalWaitingList->gethead()->getdata());
//				temp->getdata()->set_Move_Time(MT);
//				temp->getdata()->setDTPhaseOne(MT);
//				temp->getdata()->set_Waiting_Time();
//				if (temp->getdata()->get_Waiting_Time().TimeToHours() > AutoP) {
//					AutoPromote(Normal, MT);
//					return Moving_WaitingCargo(VIP, MT);
//				}
//				Cargo_DeliveredList->enqueue(temp->getdata());
//				Cargo_normalWaitingList->deletenode(Cargo_normalWaitingList->gethead());
//				Normal_timer.set_Hour(0);
//				Normal_timer.set_Day(0);
//			}
//		}
//		break;
//	case special:
//		if (!Cargo_specialWaitingList->isempty()) {
//			if (1) {
//				temp->setdata(Cargo_specialWaitingList->peek()->getdata());
//				temp->getdata()->set_Move_Time(MT);
//				temp->getdata()->setDTPhaseOne(MT);
//				temp->getdata()->set_Waiting_Time();
//				Cargo_DeliveredList->enqueue(temp->getdata());
//				Cargo_specialWaitingList->dequeue();
//				Special_timer.set_Hour(0);
//				Special_timer.set_Day(0);
//			}
//		}
//		break;
//	case VIP:
//		if (!Cargo_vipWaitingList->isempty()) {
//			if (/*Vip_timer.get_Hour() >= 5*/1) {
//				temp->setdata(Cargo_vipWaitingList->peek()->getdata());
//				temp->getdata()->set_Move_Time(MT);
//				temp->getdata()->setDTPhaseOne(MT);
//				temp->getdata()->set_Waiting_Time();
//				Cargo_DeliveredList->enqueue(temp->getdata());
//				Cargo_vipWaitingList->dequeue();
//				Vip_timer.set_Hour(0);
//				Vip_timer.set_Day(0);
//			}
//		}
//		break;
//	default:
//		break;
//	}
//
//	delete temp;
//}

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

void Company::Deliver_MovingCargo(Type t, Time DT) {
	node<Cargo>* temp;
	node<Truck>* ptr;
	int num = 0;
	switch (t)
	{
	case Normal:
		num = Truck_normalMovingList->getSize();
		ptr = Truck_normalMovingList->gethead();
		while (ptr) {
			if (!ptr->getdata()->Truckisempty()) {
				linkedlist<Cargo>* tempoCargo = ptr->getdata()->getCargolist();
				int num2 = tempoCargo->getSize();
				node<Cargo>* tcargo = tempoCargo->gethead();
				while (tcargo) {
					if (tcargo->getdata()->get_Delivery_Time() < DT || tcargo->getdata()->get_Delivery_Time() == DT) {
						/*temp = new node<Cargo>;
						temp->setdata(tcargo->getdata());*/
						node<Cargo>* del = tcargo;
						Cargo_DeliveredList->enqueue(tcargo->getdata());
						tcargo = tcargo->getnext();
						tempoCargo->deletenode(del);
					}
					else tcargo = tcargo->getnext();
				}
			}
			ptr = ptr->getnext();
		}
		break;
	case special:
		num = Truck_specialMovingList->getSize();
		ptr = Truck_specialMovingList->gethead();
		while (ptr) {
			if (!ptr->getdata()->Truckisempty()) {
				linkedlist<Cargo>* tempoCargo = ptr->getdata()->getCargolist();
				int num2 = tempoCargo->getSize();
				node<Cargo>* tcargo = tempoCargo->gethead();
				while (tcargo) {
					if (tcargo->getdata()->get_Delivery_Time() < DT || tcargo->getdata()->get_Delivery_Time() == DT) {
						/*temp = new node<Cargo>;
						temp->setdata(tcargo->getdata());*/
						node<Cargo>* del = tcargo;
						Cargo_DeliveredList->enqueue(tcargo->getdata());
						tcargo = tcargo->getnext();
						tempoCargo->deletenode(del);
					}
					else tcargo = tcargo->getnext();
				}
			}
			ptr = ptr->getnext();
		}
		break;
	case VIP:
		num = Truck_vipMovingList->getSize();
		ptr = Truck_vipMovingList->gethead();
		while (ptr) {
			if (!ptr->getdata()->Truckisempty()) {
				linkedlist<Cargo>* tempoCargo = ptr->getdata()->getCargolist();
				int num2 = tempoCargo->getSize();
				node<Cargo>* tcargo = tempoCargo->gethead();
				while (tcargo) {
					if (tcargo->getdata()->get_Delivery_Time() < DT || tcargo->getdata()->get_Delivery_Time() == DT) {
						/*temp = new node<Cargo>;
						temp->setdata(tcargo->getdata());*/
						node<Cargo>* del = tcargo;
						Cargo_DeliveredList->enqueue(tcargo->getdata());
						tcargo = tcargo->getnext();
						tempoCargo->deletenode(del);
					}
					else tcargo = tcargo->getnext();
				}
			}
			ptr = ptr->getnext();
		}
		break;
	default:
		break;
	}
}



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
		int totalTime = t.TimeToHours();
		int totalUtil = 0;
		while (!Truck_normalWaitingList->isempty()) {
			Truck* truck = Truck_normalWaitingList->peek()->getdata();
			totalActiveTime += truck->getActiveTime();
			if (truck->getJ()) {
				int tDC = truck->getCargosDelivered();
				int TC = truck->get_Capacity();
				int N = truck->getJ();
				int tAT = truck->getActiveTime();
				int util = (int)round(((double)tDC / (TC * N)) * ((double)tAT / totalTime) * 100);
				truck->setUtil(util);
				totalUtil += util;
			}
			else truck->setUtil(0);
			Truck_normalWaitingList->dequeue();
		}
		while (!Truck_specialWaitingList->isempty()) {
			Truck* truck = Truck_specialWaitingList->peek()->getdata();
			totalActiveTime += truck->getActiveTime();
			if (truck->getJ()) {
				int tDC = truck->getCargosDelivered();
				int TC = truck->get_Capacity();
				int N = truck->getJ();
				int tAT = truck->getActiveTime();
				int util = (int)round(((double)tDC / (TC * N)) * ((double)tAT / totalTime) * 100);
				truck->setUtil(util);
				totalUtil += util;
			}
			else truck->setUtil(0);
			Truck_specialWaitingList->dequeue();
		}
		while (!Truck_vipWaitingList->isempty()) {
			Truck* truck = Truck_vipWaitingList->peek()->getdata();
			totalActiveTime += truck->getActiveTime();
			if (truck->getJ()) {
				int tDC = truck->getCargosDelivered();
				int TC = truck->get_Capacity();
				int N = truck->getJ();
				int tAT = truck->getActiveTime();
				int util = (int)round(((double)tDC / (TC * N)) * ((double)tAT / totalTime) * 100);
				truck->setUtil(util);
				totalUtil += util;
			}
			else truck->setUtil(0);
			Truck_vipWaitingList->dequeue();
		}
		int avgActiveTime = (int)(round((double)totalActiveTime/((Normal_Truck_Num+Special_Truck_Num+Vip_Truck_Num)*totalTime))*100);
		outFile << "Avg Active Time = " << avgActiveTime << "%\n";
		int avgUtil = (int)round((double)totalUtil / (Normal_Truck_Num + Special_Truck_Num + Vip_Truck_Num));
		outFile << "Avg utilization = " << avgUtil << "%\n";
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
		&& noVIPCargosLeft())&&
		Truck_normalMaintenanceList->isempty() &&
		Truck_specialMaintenanceList->isempty() &&
		Truck_VIPMaintenanceList->isempty() &&
		Truck_normalMovingList->isempty() &&
		Truck_specialMovingList->isempty() &&
		Truck_vipMovingList->isempty() &&
		!Truck_normalLoadingList &&
		!Truck_specialLoadingList &&
		!Truck_vipLoadingList;
}

UI* Company::GetUIObject()
{
	return uiObject;
}

void Company::Truck_Loading_Moving(Time t)
{
	if (Truck_vipLoadingList)
	{
		if (Truck_vipLoadingList->getMT() < t || t == Truck_vipLoadingList->getMT())
		{
			Truck_vipLoadingList->setFT();
			Truck_vipMovingList->addWithPriority(Truck_vipLoadingList, 0, 0, 0);
			Truck_vipLoadingList = nullptr;
		}
	}
	if (Truck_specialLoadingList)
	{
		if (Truck_specialLoadingList->getMT() < t || t == Truck_specialLoadingList->getMT())
		{
			Truck_specialLoadingList->setFT();
			Truck_specialMovingList->addWithPriority(Truck_specialLoadingList,0,0,0);
			Truck_specialLoadingList = nullptr;
		}
	}
	if (Truck_normalLoadingList)
	{
		if (Truck_normalLoadingList->getMT() < t || t == Truck_normalLoadingList->getMT())
		{
			Truck_normalLoadingList->setFT();
			Truck_normalMovingList->addWithPriority(Truck_normalLoadingList,0,0,0);
			Truck_normalLoadingList = nullptr;
		}
	}
}
void Company::loadcargo(Truck* tk, Time t,Type typ)
{
	if (tk) {
		if (tk->get_Type() == Normal)
		{
			for (int i = 0; i < tk->get_Capacity(); i++)
			{
				if (!Cargo_normalWaitingList->isempty()) {
					Cargo_normalLoadingList->enqueue(Cargo_normalWaitingList->gethead()->getdata());
					Cargo_normalWaitingList->gethead()->getdata()->setTID(tk->getID());
					Cargo_normalWaitingList->gethead()->getdata()->set_Move_Time(t);
					Cargo_normalWaitingList->gethead()->getdata()->set_Delivery_Time(tk->get_Speed());
					tk->add_Cargo(Cargo_normalWaitingList->gethead()->getdata());
					Cargo_normalWaitingList->deletenode(Cargo_normalWaitingList->gethead());

				}
			}
			tk->setMT(t);
			tk->LoadAuxiliary();
		}
		if (tk->get_Type() == special)
		{
			for (int i = 0; i < tk->get_Capacity(); i++)
			{
				if (!Cargo_specialWaitingList->isempty()) {
					Cargo_specialLoadingList->enqueue(Cargo_specialWaitingList->peek()->getdata());
					Cargo_specialWaitingList->peek()->getdata()->setTID(tk->getID());
					Cargo_specialWaitingList->peek()->getdata()->set_Move_Time(t);
					Cargo_specialWaitingList->peek()->getdata()->set_Delivery_Time(tk->get_Speed());
					tk->add_Cargo(Cargo_specialWaitingList->peek()->getdata());
					Cargo_specialWaitingList->dequeue();
				}
			}
			tk->setMT(t);
			tk->LoadAuxiliary();
		}
		if (tk->get_Type() == VIP)
		{
			for (int i = 0; i < tk->get_Capacity(); i++)
			{
				if (!Cargo_vipWaitingList->isempty()) {
					Cargo_vipLoadingList->enqueue(Cargo_vipWaitingList->peek()->getdata());
					Cargo_vipWaitingList->peek()->getdata()->setTID(tk->getID());
					Cargo_vipWaitingList->peek()->getdata()->set_Move_Time(t);
					Cargo_vipWaitingList->peek()->getdata()->set_Delivery_Time(tk->get_Speed());
					tk->add_Cargo(Cargo_vipWaitingList->peek()->getdata());
					Cargo_vipWaitingList->dequeue();
				}
			}
			tk->setMT(t);
			tk->LoadAuxiliary();
		}
	}
}

void Company::Truck_Waiting_Loading(Truck* tk)
{
	if (tk)
	{
		if (tk->get_Type() == Normal)
		{
			Truck_normalLoadingList=tk;
			Truck_normalWaitingList->dequeue();
		}
		if (tk->get_Type() == special)
		{
			Truck_specialLoadingList = tk;
			Truck_specialWaitingList->dequeue();
		}
		if (tk->get_Type() == VIP)
		{
			Truck_vipLoadingList = tk;
			Truck_vipWaitingList->dequeue();
		}
	}
}

bool Company::no_Wating_CargosLeft() {
	return(Cargo_normalWaitingList->isempty() &&
		Cargo_specialWaitingList->isempty() &&
		Cargo_vipWaitingList->isempty());
}

void Company::LoadVIP(Time t)
{
	
	node<Truck>* vipHead = Truck_vipWaitingList->peek();
	node<Truck>* normalHead = Truck_normalWaitingList->peek();
	node<Truck>* specialHead = Truck_specialWaitingList->peek();
	bool loaded = 0;
	if (vipHead && !Truck_vipLoadingList) {
		if (Cargo_vipWaitingList->getSize() >= vipHead->getdata()->get_Capacity()) {
			loadcargo(vipHead->getdata(), t, VIP);
			Truck_Waiting_Loading(vipHead->getdata());
			loaded = 1;
		}
	}
	if (!loaded && normalHead && !Truck_normalLoadingList) {
		if (Cargo_vipWaitingList->getSize() >= normalHead->getdata()->get_Capacity()) {
			loadcargo(normalHead->getdata(), t, VIP);
			Truck_Waiting_Loading(normalHead->getdata());
			loaded = 1;
		}
	}
	if (!loaded && specialHead && Truck_specialLoadingList) {
		if (Cargo_vipWaitingList->getSize() >= specialHead->getdata()->get_Capacity()) {
			loadcargo(specialHead->getdata(), t, VIP);
			Truck_Waiting_Loading(specialHead->getdata());
			loaded = 1;
		}
	}
}

void Company::LoadSpecial(Time t)
{
	if(!Truck_specialLoadingList) {
		node<Truck>* specialHead = Truck_specialWaitingList->peek();
		if (specialHead) {
			if (Cargo_specialWaitingList->getSize() >= specialHead->getdata()->get_Capacity()) {
				loadcargo(specialHead->getdata(), t, special);
				Truck_Waiting_Loading(specialHead->getdata());
			}
		}
	}
}

void Company::LoadNormal(Time t)
{
	
	node<Truck>* normalHead = Truck_normalWaitingList->peek();
	node<Truck>* specialHead = Truck_specialWaitingList->peek();
	bool loaded = 0;
	if (normalHead && !Truck_normalLoadingList) {
		if (Cargo_normalWaitingList->getSize() >= normalHead->getdata()->get_Capacity()) {
			loadcargo(normalHead->getdata(), t, Normal);
			Truck_Waiting_Loading(normalHead->getdata());
			loaded = 1;
		}
	}
	if (!loaded && specialHead && !Truck_specialLoadingList) {
		if (Cargo_normalWaitingList->getSize() >= specialHead->getdata()->get_Capacity()) {
			loadcargo(specialHead->getdata(), t, Normal);
			Truck_Waiting_Loading(specialHead->getdata());
			loaded = 1;
		}
	}
}

void Company::Load(Time t)
{
	LoadVIP(t);
	LoadSpecial(t);
	LoadNormal(t);
}
