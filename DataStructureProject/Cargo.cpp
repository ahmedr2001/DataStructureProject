#include "Cargo.h"
#define costWeight 1
#define distanceWeight 1
#define prepTimeWeight 1
 
Cargo::Cargo(Time pt, int lt, int ID, Type t, int c, int d) {
	set_Pre_Time(pt);
	set_Load_Time(lt);
	set_Cost(c);
	set_Type(t);
	set_Distance(d);
}

void Cargo::set_ID(int id) {
	ID = id;
}

void Cargo::set_Pre_Time(Time t){
	Pre_Time = t;
}
void Cargo::set_Load_Time(int t){
	Load_Time = t;
}

void Cargo::set_Move_Time(Time t)
{
	Move_Time = t;
}

void Cargo::set_Delivery_Time(int speed)
{
	Delivery_Time = Move_Time + (int)round((double)Distance / speed) + Load_Time;
}
Time Cargo::get_Delivery_Time()
{
	return Delivery_Time;
}

Time Cargo::get_Move_Time()
{
	return Move_Time;
}

void Cargo::set_Waiting_Time()
{
	Waiting_Time = Move_Time - Pre_Time;
}

Time Cargo::get_Pre_Time(){
	return Pre_Time;
}
int Cargo::get_Load_Time(){
	return Load_Time;
}
void Cargo::set_Cost(int c){
	Cost = (c >= 0) ? c : 0;
}
void Cargo::set_Distance(int d){
	Distance = (d >= 0) ? d : 0;
}
void Cargo::set_Type(Type t){
	this->t = t;
}
int Cargo::get_Cost(){
	return Cost;
}
int Cargo::get_Distance(){
	return Distance;
}
int Cargo::get_ID() {
	return ID;
}
Type Cargo::get_Type(){
	return t;
}
Time Cargo::get_Waiting_Time() {
	return Waiting_Time;
}
void Cargo::LoadFromStreamFile(){}
void Cargo::OutToStreamFile(){}

int Cargo::getPriority(Time& currentTime)
{
	Time waitedTime = currentTime - Pre_Time;
	priority = costWeight * Cost + distanceWeight * Distance + prepTimeWeight * waitedTime.TimeToHours();
	return priority;
}