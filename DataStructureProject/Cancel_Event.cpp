#include "Cancel_Event.h"
void Cancel_Event::set_ID(int id)
{
	cargo_ID = id;
}
void Cancel_Event::set_Time(Time T)
{
	Cancel_time = T;
}
int Cancel_Event::get_ID()
{
	return cargo_ID;
}
Time Cancel_Event::get_Time()
{
	return Cancel_time;
}
Cancel_Event::Cancel_Event(Time T, int id) : Event(T,id){
	set_ID(id);
	set_Time(T);
}

void Cancel_Event::Execute(Company* myComp)
{
	myComp->Remove_Normal_Wating_Cargo(cargo_ID);
}
