// 27-3-2022 Ahmed zahran-ahmed abdelatty-ibrahim tarek

#include<iostream>
#include<Windows.h>
#include"Company.h"
using namespace std;

int main() {
	/*Time t;
	Company* c1 = new Company();
	c1->LoadTrucksAndEventsData("test");
	while (t.get_Day()!=14||t.get_Hour()!=12)
	{
		c1->Execute_Events(t);
		Sleep(100);
		t++;
		c1->printathing();
	}*/
	Time d2(12,3);
	priority_queue<Cargo*>* test = new priority_queue<Cargo*>;
	Cargo* c1 = new Cargo(d2, 500, 4, VIP, 300, 250);
	Cargo* c2 = new Cargo(d2, 550, 1, VIP, 150, 500);
	Cargo* c3 = new Cargo(d2, 520, 3, VIP, 200, 150);

	test->enqueue(c2);
	test->enqueue(c3);
	test->enqueue(c1);

	return 0;
}