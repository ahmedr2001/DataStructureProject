#include "Cargo.h"
#define costWeight 1
#define distanceWeight 1
#define prepTimeWeight 1
 
Cargo::Cargo(Time pt, Time lt, Type t, int c, int d) {
	set_Cost(c);
	set_Type(t);
	set_Distance(d);
}
void Cargo::set_Pre_Time(){}
void Cargo::set_Load_Time(){}

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
Type Cargo::get_Type(){
	return t;
}
void Cargo::LoadFromStreamFile(){}
void Cargo::OutToStreamFile(){}

int Cargo::getPriority(Time& currentTime)
{
	priority = costWeight * Cost + distanceWeight * Distance + prepTimeWeight * (currentTime - Pre_Time);
	return priority;
}