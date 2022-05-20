#include "SilentMode.h"

void SilentMode::Simulate(Company* c1, Time t, UI* uiObject)
{
	bool done = 0;
	uiObject->PrintMessage("Silent Mode\nSimulation Starts...\n");
	while (!done) {
		done = c1->Execute_Events(t);
		c1->MaxWait(Normal, t);
		c1->MaxWait(special, t);
		c1->AutoPromote(Normal, t);
		c1->MoveTrucksToCheckup(t);
		c1->MoveCheckupToAvail(t);
		if (t.get_Hour() % 5 == 4 && t.get_Hour() >= 5 && t.get_Hour() <= 23) {
			c1->Moving_WaitingCargo(VIP, t);
			c1->Moving_WaitingCargo(special, t);
			c1->Moving_WaitingCargo(Normal, t);
			//c1->Increase_Timers();
		}
		//if (t.get_Hour() % 5 == 4) {
		//	c1->Deliver_MovingCargo(VIP, t);
		//	c1->Deliver_MovingCargo(special, t);
		//	c1->Deliver_MovingCargo(Normal, t);
		//	c1->Deliver_Timers();
		//}
		//c1->Deliver_Timers();

		done &= c1->noCargosLeft();

		t++;
	}
	cout << "Simulation ends, Output file created\n";
}
