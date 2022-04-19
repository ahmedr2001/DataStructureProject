#include "Cancel_Event.h"

Cancel_Event::Cancel_Event(Time T, int id) : Event(T,id){
}

void Cancel_Event::Execute(Company* myComp)
{
	Cargo* cargoToDelete = myComp->Remove_Normal_Wating_Cargo(Event::Cargo_ID);
	delete cargoToDelete;
}
