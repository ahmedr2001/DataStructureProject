#include "Truck.h"
#include<iostream>
Truck::Truck(Type t, int cap, int ct, int s, int id)
{
	cargolist = new linkedlist<Cargo>;
	fail = false;
	loaded = 0;
	num_of_journey = 0;
	ID = id;
	active_time = 0;
	cargosDelivered = 0;
	DI = 0;
	utilization = 0;
	DeliverTime = Time();
	finishTime = Time();
	moveTime = Time();
	checkupEnd = Time();
	set_Type(t);
	set_Capacity(cap);
	set_Check_Time(ct);
	set_Speed(s);
}

// setters and getters

void Truck::increaseActiveTime(Time t)
{
	setMT(t);
	setFT();
	int maxDistance = 0;
	node<Cargo>* cargo = cargolist->gethead();
	while (cargo) {
		maxDistance = max(maxDistance, cargo->getdata()->get_Distance());
		cargo = cargo->getnext();
	}
	active_time += (finishTime - t).TimeToHours() + (int)round((double)maxDistance / speed);
}

int Truck::getActiveTime()
{
	return active_time;
}

void Truck::incrementJ()
{
	num_of_journey++;
}

void Truck::add_Cargo(Cargo* c)
{	
	cargolist->addWithPriority(c,1,0,0);
	loaded++;	
}

void Truck::set_Capacity(int cap)
{
	Capacity = (cap <= 0) ? 1 : cap;
}

void Truck::set_Type(Type t)
{
	trucktype = t;
}

void Truck::set_Check_Time(int ct)
{
	check_time = ct;
}

void Truck::set_Speed(int s)
{
	speed = s;
}

void Truck::set_DI()
{
	// derive DI from equation given in the document
	int maxDistance = 0;
	int unloadTimes = 0;
	node<Cargo>* cargoHead = cargolist->gethead();
	while (cargoHead) {
		maxDistance = max(maxDistance, cargoHead->getdata()->get_Distance());
		unloadTimes += cargoHead->getdata()->get_Load_Time();
		cargoHead = cargoHead->getnext();
	}
	DI = ceil(double(2*maxDistance) / speed) + unloadTimes;
}

void Truck::setMT(Time t)
{
	int unloadTimes = 0;
	node<Cargo>* cargoHead = cargolist->gethead();
	while (cargoHead) {
		unloadTimes += cargoHead->getdata()->get_Load_Time();
		cargoHead = cargoHead->getnext();
	}
	moveTime = t + unloadTimes;
}

void Truck::setFT()
{
	node<Cargo>* cargoHead = cargolist->gethead();
	Time maxFT;
	while (cargoHead) {
		if (maxFT < cargoHead->getdata()->get_Delivery_Time()) {
			maxFT.set_Day(cargoHead->getdata()->get_Delivery_Time().get_Day());
			maxFT.set_Hour(cargoHead->getdata()->get_Delivery_Time().get_Hour());
		}
		cargoHead = cargoHead->getnext();
	}
	finishTime = maxFT;
}

void Truck::setCT(Time t, int i)
{
	checkupEnd = t + i;
}

void Truck::increaseCargosDelivered(int c)
{
	cargosDelivered += c;
}

void Truck::setUtil(int util)
{
	utilization = util;
}

int Truck::getUtil()
{
	return utilization;
}

int Truck::getCargosDelivered()
{
	return cargosDelivered;
}

Time Truck::getCT()
{
	return checkupEnd;
}

int Truck::getJ()
{
	return num_of_journey;
}

int Truck::getPriority(int a, int b, int c) 
{
	return -1 * finishTime.TimeToHours();
}

node<Cargo>* Truck::getnumofcargos(int & cnt)
{
	node<Cargo>* trav = cargolist->GetAllNodes(cnt);
	return trav;
}

int Truck::get_Capacity()
{
	return Capacity;
}

Type Truck::get_Type()
{
	return trucktype;
}

int Truck::getID()
{
	return ID;
}

int Truck::get_Check_Time()
{
	return check_time;
}

int Truck::get_Speed()
{
	return speed;
}

int Truck::get_DI()
{
	return DI;
}

Time Truck::getFT() const
{
	return finishTime;
}

Time Truck::getMT() const
{
	return moveTime;
}
Time Truck::getDeliverTimeOfAllCargos() {

	return DeliverTime;
}

bool Truck::Truckisempty() {
	return cargolist->isempty();
}

node<Cargo>* Truck::HeadCargo() {
	return cargolist->gethead();
}

void Truck::removeHeadCargo() {
	cargolist->deletenode(cargolist->gethead());
}
linkedlist<Cargo>* Truck::getCargolist() {
	return cargolist;
}

void Truck::LoadAuxiliary()
{
	node<Cargo>* cgo = cargolist->gethead();
	while (cgo) {
		cgo->getdata()->set_Move_Time(moveTime);
		cgo->getdata()->set_Delivery_Time(speed);
		cgo->getdata()->set_Waiting_Time();
		cgo = cgo->getnext();
	}
}

bool Truck::failed() {
	int chance = 90;
	if (rand()%100 == chance) {
		this->fail = true;
		cout << "Truck "<< this->getID() << " failed to deliver ";
	}
	else {
		this->fail = false;
	}
	return this->fail;
}

bool Truck::getfail(){

	return fail;
}

void Truck::setNightWorker(bool value) {
	nightworker = value;
}

bool Truck::getNightWorker(){
	return nightworker;
}