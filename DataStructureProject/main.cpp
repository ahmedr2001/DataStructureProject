// 27-3-2022 Ahmed zahran-ahmed abdelatty-ibrahim tarek

#include<iostream>
#include<Windows.h>
#include"Company.h"
using namespace std;

int main() {
	Time t;
	Company* c1 = new Company();
	c1->LoadTrucksAndEventsData("test");

	/*while (t.get_Day()!=14||t.get_Hour()!=12)
	{
		c1->Execute_Events(t);
		Sleep(10);
		t++;
	}*/
	/*c1->Moving_WaitingCargo(Normal);
	c1->Deliver_MovingCargo(Normal);*/
	bool done = 0;
	while (!done) {		
		done = c1->Execute_Events(t);
		
		c1->Moving_WaitingCargo(VIP);
		c1->Moving_WaitingCargo(special);
		c1->Moving_WaitingCargo(Normal);
		
		if (t.get_Hour() % 5 == 4) {
			c1->Deliver_MovingCargo(VIP);
			c1->Deliver_MovingCargo(special);
			c1->Deliver_MovingCargo(Normal);
		}
		
		done &= c1->noCargosLeft();
		
		t++;
	}
	/*Time t(2,22);
	Time t2(9, 3);
	Time t3(11,6);
	priority_queue<Cargo*>* test = new priority_queue<Cargo*>;
	Cargo* c1 = new Cargo(t, 3, 4, VIP, 400, 90);
	Cargo* c2 = new Cargo(t2, 1, 2, VIP, 613, 25);
	Cargo* c3 = new Cargo(t3, 3, 6, VIP, 1006, 19);
	test->enqueue(c1);
	test->enqueue(c2);
	test->enqueue(c3);*/
	c1->PrintToFile("outtest");
	

	return 0;
}