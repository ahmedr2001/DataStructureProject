#include "Prepare_Event.h"
Prepare_Event::Prepare_Event(Time T, int id, int d, int h, int c):Event(T,id) {
	set_Cargo_Dist(d);
	set_Cargo_cost(c);
	set_Load_Time(h);
}

void Prepare_Event::Execute(Company* myComp)
{
}
void Prepare_Event::set_Cargo_Dist(int d) {
	Cargo_Dist = (d >= 0) ? d : 0;
}
void Prepare_Event::set_Load_Time(int h) {
	Load_Time = (h >= 0) ? h : 0;
}
void Prepare_Event::set_Cargo_cost(int c) {
	Cargo_cost = (c >= 0) ? c : 0;
}
int Prepare_Event::get_Cargo_Dist() const {
	return Cargo_Dist;
}
int Prepare_Event::get_Load_Time()const {
	return Load_Time;
}
int Prepare_Event::get_Cargo_cost() const {

	return Cargo_cost;
}
