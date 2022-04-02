// 27-3-2022 Ahmed zahran-ahmed abdelatty-ibrahim tarek

#include<iostream>
#include<Windows.h>
#include"Company.h"
#include"Prepare_Event.h"
using namespace std;

int main() {
	Time t(1,3);
	Time t2(13,3);
	Time t3(13,23);
	Company* c1 = new Company();
	c1->LoadTrucksAndEventsData("test");
	while (t.get_Day()!=14||t.get_Hour()!=12)
	{
		c1->Execute_Events(t);
		Sleep(5);
		t++;
		c1->printathing();
	}
	priority_queue<Cargo*>* test = new priority_queue<Cargo*>;
	Cargo* c1 = new Cargo(t, 12, 1, VIP, 12, 12);
	Cargo* c2 = new Cargo(t2, 12, 3, Normal, 120, 120);
	Cargo* c3 = new Cargo(t3, 12, 2, VIP, 100, 100);
	Cargo* c4 = new Cargo(t3, 12, 4, VIP, 1050, 1005);
	test->enqueue(c1);
	test->enqueue(c4);
	test->enqueue(c2);
	test->enqueue(c3);
	return 0;
}