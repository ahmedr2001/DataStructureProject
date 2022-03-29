// 27-3-2022 Ahmed zahran-ahmed abdelatty-ibrahim tarek

#include<iostream>
#include"Cargo.h"
#include"priority_queue.h"
using namespace std;

int main() {
	Time d1(1, 12);
	Time d2(0, 5);
	Cargo* c1=new Cargo(d1,d2,VIP,1050,5);
	Cargo* c2 = new Cargo(d1, d2, VIP, 1088, 5);
	priority_queue<Cargo*>* Q = new priority_queue<Cargo*>;
	Q->enqueue(c1);
	Q->enqueue(c2);
	cout<< Q->peek()->getdata()->Cost;
	return 0;
}