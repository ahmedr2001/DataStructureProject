// 27-3-2022 Ahmed zahran-ahmed abdelatty-ibrahim tarek

#include<iostream>
#include"Company.h"
#include"Prepare_Event.h"
using namespace std;

int main() {
	//Time d1;              //Test_v1
	//cin >> d1;
	Time d2(4, 15);
	//Cargo* c1=new Cargo(d1,d2,VIP,1050,5);
	//Cargo* c2 = new Cargo(d1, d2, VIP, 1088, 5);
	//priority_queue<Cargo*>* Q = new priority_queue<Cargo*>;
	//Q->enqueue(c1);
	//Q->enqueue(c2);
	//cout<< Q->peek()->getdata()->get_Cost();
//	Prepare_Event* p = new Prepare_Event(d2, Normal,5, 50, 6, 1500);
	Company* c1 = new Company();
	c1->LoadTrucksAndEventsData("test");
	c1->Execute_Events(d2);
	c1->printathing();

	return 0;
}