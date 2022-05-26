// 27-3-2022 Ahmed Zahran-Ahmed Abdelatty-Ibrahim Tarek 26-5-2022 

#include<iostream>
#include<Windows.h>
#include"Company.h"
#include"InterfaceOutput.h"

using namespace std;

int main() 
{
	Company* c1 = new Company;
	Time t;
	InterfaceOutput* io=new InterfaceOutput;
	io->Simulate(c1,t);
	return 0;
}
