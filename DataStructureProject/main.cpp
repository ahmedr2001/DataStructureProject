// 27-3-2022 Ahmed zahran-ahmed abdelatty-ibrahim tarek

#include<iostream>
#include<Windows.h>
#include"Company.h"
#include"Prepare_Event.h"
using namespace std;

int main() {
	Time t;
	Company* c1 = new Company();
	c1->LoadTrucksAndEventsData("test");
	while (t.get_Day()!=14&&t.get_Hour()!=12)
	{
		c1->Execute_Events(t);
		Sleep(1000);
		t++;
		c1->printathing();
	}
	return 0;
}