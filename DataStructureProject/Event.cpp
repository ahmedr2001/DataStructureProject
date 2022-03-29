#include "Event.h"
Event::Event(Time T, int id) {
	set_Time(T);
	set_Cargo_ID(id);
}
void Event::set_Time(Time t) {
	Event_Time = t;
}
void Event::set_Cargo_ID(int id){
	Cargo_ID = id;
}
Time Event::get_Time() const {
	return Event_Time;
}
int Event::get_Cargo_ID() const {
	return Cargo_ID;
}