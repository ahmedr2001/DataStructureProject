#pragma once
#include "Event.h"
#include"Company.h"
class Cancel_Event :
    public Event
{
private:
    Time Cancel_time;
public:
    Cancel_Event(Time T, int id);
    void Execute(Company* myComp);
};

