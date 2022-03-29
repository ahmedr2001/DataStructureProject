#include "Company.h"
void Company::LoadTrucksAndEventsData(string filename)
{
	ifstream inFile(filename + ".txt", ios::in);

	if (inFile.is_open())
	{
		inFile >> Normal_Truck_Num;
		inFile >> Special_Truck_Num;
		inFile >> Vip_Truck_Num;

		inFile >> Normal_Truck_Speed;
		inFile >> Special_Truck_Speed;
		inFile >> Vip_Truck_Speed;

		inFile >> Normal_Truck_Cap;
		inFile >> Special_Truck_Cap;
		inFile >> Vip_Truck_Cap;

		inFile >> Normal_journey_Num;
		inFile >> Special_journey_Num;
		inFile >> Vip_journey_Num;

		inFile >> AutoP;
		inFile >> MaxW;

		inFile >> Event_Num;
}