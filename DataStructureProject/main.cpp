// 27-3-2022 Ahmed zahran-ahmed abdelatty-ibrahim tarek

#include<iostream>
#include<Windows.h>
#include"Company.h"
using namespace std;

int main() {
	Time t;
	Company* c1 = new Company();
	c1->LoadTrucksAndEventsData("test");
	while (t.get_Day()!=14||t.get_Hour()!=12)
	{
		c1->Execute_Events(t);
		Sleep(10);
		t++;
		c1->printathing();
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

	return 0;
}