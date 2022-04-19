#include "Company.h"
Company::Company()
{
	eventList=new queue<Event>;

	Cargo_normalWaitingList=new linkedlist<Cargo>;
	Cargo_specialWaitingList=new queue<Cargo>;
	Cargo_vipWaitingList = new priority_queue<Cargo>;

	Cargo_DeliveredList = new queue<Cargo>;

	Cargo_normalMovingList = new queue<Cargo>;
	Cargo_specialMovingList = new queue<Cargo>;
	Cargo_vipMovingList = new queue<Cargo>;

	Truck_vipWaitingList = new queue<Truck>;
	Truck_normalWaitingList = new queue<Truck>;
	Truck_specialWaitingList = new queue<Truck>;

	queue<Truck>* Truck_vipMovingList = new queue<Truck>;
	queue<Truck>* Truck_normalMovingList = new queue<Truck>;
	queue<Truck>* Truck_specialMovingList = new queue<Truck>;
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

	int movingCargosCount = Cargo_normalMovingList->getSize()
		+ Cargo_specialMovingList->getSize()
		+ Cargo_vipMovingList->getSize();

	message += (to_string(movingCargosCount) + " Moving Cargos: ");
	
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
	message += "----------------------------------------------------------------------\n";

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
void Company::add_truck(Type t)
{
	Truck *tk1;
	Truck *tk2;
	Truck *tk3;
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
	node<Cargo>* tempToBeDeleted = Cargo_normalWaitingList->getpointerto(temp);
	return tempToBeDeleted->getdata();
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

void Company::Moving_WaitingCargo(Type t, Time MT){
	node<Cargo>* temp = new node<Cargo>;
	Time avgWait;
	switch (t)
	{
	case Normal:
		if (!Cargo_normalWaitingList->isempty()) {
			if (/*Normal_timer.get_Hour() >= */1) {
				temp->setdata(Cargo_normalWaitingList->gethead()->getdata());
				temp->getdata()->set_Move_Time(MT);
				temp->getdata()->set_Waiting_Time();
				if (temp->getdata()->get_Waiting_Time().TimeToHours() > AutoP) {
					temp->getdata()->setAutoP(true);
					temp->getdata()->set_Type(VIP);
					Cargo_normalWaitingList->deletenode(Cargo_normalWaitingList->gethead());
					Cargo_vipWaitingList->enqueue(temp->getdata());
					return Moving_WaitingCargo(VIP, MT);
				}
				Cargo_normalMovingList->enqueue(temp->getdata());
				Cargo_normalWaitingList->deletenode(Cargo_normalWaitingList->gethead());
				/*Normal_timer.set_Hour(0);
				Normal_timer.set_Day(0);*/
			}
		}
		break;
	case special:
		if (!Cargo_specialWaitingList->isempty()) {
			if (/*Special_timer.get_Hour() >=*/ 1) {
				temp->setdata(Cargo_specialWaitingList->peek()->getdata());
				temp->getdata()->set_Move_Time(MT);
				temp->getdata()->set_Waiting_Time();
				Cargo_specialMovingList->enqueue(temp->getdata());
				Cargo_specialWaitingList->dequeue();
				/*Special_timer.set_Hour(0);
				Special_timer.set_Day(0);*/
			}
		}
		break;
	case VIP:
		if (!Cargo_vipWaitingList->isempty()) {
			if (/*Vip_timer.get_Hour() >=*/ 1) {
				temp->setdata(Cargo_vipWaitingList->peek()->getdata());
				temp->getdata()->set_Move_Time(MT);
				temp->getdata()->set_Waiting_Time();
				Cargo_vipMovingList->enqueue(temp->getdata());
				Cargo_vipWaitingList->dequeue();
				/*Vip_timer.set_Hour(0);
				Vip_timer.set_Day(0);*/
			}
		}
		break;
	default:
		break;
	}

	delete temp;
}

void Company::Deliver_Timers() {
	if (!Cargo_normalMovingList->isempty()) {
		D_N_timer++;
	}
	if (!Cargo_specialMovingList->isempty()) {
		D_S_timer++;
	}
	if (!Cargo_vipMovingList->isempty()) {
		D_V_timer++;
	}
}

void Company::Deliver_MovingCargo(Type t, Time DT){
	node<Cargo>* temp = new node<Cargo>;
	switch (t)
	{
	case Normal:
		if (!Cargo_normalMovingList->isempty() /* && D_S_timer.get_Hour() == 5 */) {
			temp->setdata(Cargo_normalMovingList->peek()->getdata());
			temp->getdata()->setDTPhaseOne(DT);
			Cargo_DeliveredList->enqueue(temp->getdata());
			Cargo_normalMovingList->dequeue();
			/*D_N_timer.set_Hour(0);
			D_N_timer.set_Day(0);*/
		}
		break;
	case special:
		if (!Cargo_specialMovingList->isempty() /* && D_S_timer.get_Hour() == 5 */ ) {
			temp->setdata(Cargo_specialMovingList->peek()->getdata());
			temp->getdata()->setDTPhaseOne(DT);
			Cargo_DeliveredList->enqueue(temp->getdata());
			Cargo_specialMovingList->dequeue();
			/*D_S_timer.set_Hour(0);
			D_S_timer.set_Day(0);*/
		}
		break;
	case VIP:
		if (!Cargo_vipMovingList->isempty() /* && D_S_timer.get_Hour() == 5 */) {
			temp->setdata(Cargo_vipMovingList->peek()->getdata());
			temp->getdata()->setDTPhaseOne(DT);
			Cargo_DeliveredList->enqueue(temp->getdata());
			Cargo_vipMovingList->dequeue();
			/*D_V_timer.set_Hour(0);
			D_V_timer.set_Day(0);*/
		}
		break;
	default:
		break;
	}

	delete temp;
}

void Company::PrintToFile(string filename)
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
		outFile << "CDT" << setw(5) << "CID" << setw(5) << "PT" << setw(5) << "WT" << endl;
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

UI* Company::GetUIObject()
{
	return uiObject;
}

bool Company::no_Wating_CargosLeft() {
	return(Cargo_normalWaitingList->isempty() &&
		Cargo_specialWaitingList->isempty() &&
		Cargo_vipWaitingList->isempty());
}