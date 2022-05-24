#include "InteractiveMode.h"

void InteractiveMode::Simulate(Company* c1, Time& t, UI* uiObject) {
	char enterKeyPressed;
	bool done = 0;
	Time counter(0, 0);
	bool shipping = false;
	while (!done) {
		uiObject->PrintMessage("Press Enter to Continue...\n");
		uiObject->getLine(&enterKeyPressed, 1);

		done = c1->Execute_Events(t);
		if (t.get_Hour() >= 5 && t.get_Hour() <= 23) {
			c1->AutoPromote(Normal, t);
			c1->MaxWait(Normal, t);
			c1->MaxWait(special, t);
			c1->MaxWait(VIP, t);
			c1->Load(t);
			c1->Truck_Loading_Moving(t);
		}
			c1->Deliver_MovingCargo(VIP, t);
			c1->Deliver_MovingCargo(special, t);
			c1->Deliver_MovingCargo(Normal, t);
			c1->MoveTrucksToCheckup(t);
			c1->MoveCheckupToAvail(t);
		//if (t.get_Hour() >= 5 && t.get_Hour() <= 23) {
		//	if (t.get_Hour() % 5 == 4) {
		//		c1->Moving_WaitingCargo(VIP, t);
		//		c1->Moving_WaitingCargo(special, t);
		//		c1->Moving_WaitingCargo(Normal, t);
		//		//c1->Increase_Timers();
		//	}
		//}
		//if (t.get_Hour() % 5 == 4) {
		//	c1->Deliver_MovingCargo(VIP, t);
		//	c1->Deliver_MovingCargo(special, t);
		//	c1->Deliver_MovingCargo(Normal, t);
		//	c1->Deliver_Timers();
		//}
		//c1->Deliver_Timers();

		done &= c1->noCargosLeft();

		c1->PrintToConsole(t);

		t++;
	}
}