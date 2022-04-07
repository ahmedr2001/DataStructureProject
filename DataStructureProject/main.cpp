// 27-3-2022 Ahmed zahran-ahmed abdelatty-ibrahim tarek

#include<iostream>
#include<Windows.h>
#include"Company.h"
using namespace std;

int main() {
	Time t;
	Company* c1 = new Company();
	c1->LoadTrucksAndEventsData("test");
	UI* uiObject = c1->GetUIObject();

	int simMode;
	uiObject->PrintMessage("Which simulation mode would you like?\n");
	uiObject->PrintMessage("1-Interactive Mode 2-Step-By-Step Mode 3-Silent Mode\n");
	uiObject->GetInput(simMode);
	if (simMode == 2) {
		bool done = 0;
		while (!done) {
			done = c1->Execute_Events(t);

			if (t.get_Hour() >= 5 && t.get_Hour() <= 23) {
				c1->Moving_WaitingCargo(VIP, t);
				c1->Moving_WaitingCargo(special, t);
				c1->Moving_WaitingCargo(Normal, t);
			}

			if (t.get_Hour() % 5 == 4) {
				c1->Deliver_MovingCargo(VIP, t);
				c1->Deliver_MovingCargo(special, t);
				c1->Deliver_MovingCargo(Normal, t);
			}

			done &= c1->noCargosLeft();

			c1->PrintToConsole(t);

			t++;
			Sleep(1000);
		}
	}
	if (simMode == 1) {
		char enterKeyPressed;
		bool done = 0;
		while (!done) {
			uiObject->PrintMessage("Press Enter to Continue...\n");
			uiObject->getLine(&enterKeyPressed, 1);

			done = c1->Execute_Events(t);

			if (t.get_Hour() >= 5 && t.get_Hour() <= 23) {
				c1->Moving_WaitingCargo(VIP, t);
				c1->Moving_WaitingCargo(special, t);
				c1->Moving_WaitingCargo(Normal, t);
			}

			if (t.get_Hour() % 5 == 4) {
				c1->Deliver_MovingCargo(VIP, t);
				c1->Deliver_MovingCargo(special, t);
				c1->Deliver_MovingCargo(Normal, t);
			}

			done &= c1->noCargosLeft();

			c1->PrintToConsole(t);

			t++;
		}
	}
	else {
		bool done = 0;
		uiObject->PrintMessage("Silent Mode\nSimulation Starts...\n");
		while (!done) {
			done = c1->Execute_Events(t);

			if (t.get_Hour() >= 5 && t.get_Hour() <= 23) {
				c1->Moving_WaitingCargo(VIP, t);
				c1->Moving_WaitingCargo(special, t);
				c1->Moving_WaitingCargo(Normal, t);
			}

			if (t.get_Hour() % 5 == 4) {
				c1->Deliver_MovingCargo(VIP, t);
				c1->Deliver_MovingCargo(special, t);
				c1->Deliver_MovingCargo(Normal, t);
			}

			done &= c1->noCargosLeft();

			t++;
		}
		cout << "Simulation ends, Output file created\n";
	}
	
	c1->PrintToFile("outtest");	

	return 0;
}