#include "Cargo.h"
Cargo::Cargo(/*char* pt, int lt,*/ Type t, int c, int d) {

}
//void Cargo::set_Load_Time(int t){}
void Cargo::set_Cost(int c){}
void Cargo::set_Distance(int d){}
void Cargo::set_Type(Type t){}
//int Cargo::get_Load_Time(){}
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