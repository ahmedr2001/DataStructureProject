#pragma once
#include "Event.h"
#include"Company.h"
class Cancel_Event :
    public Event
{
private:
    Time Cancel_time;
    int cargo_ID;
public:
    Cancel_Event(Time T, int id);
    void set_ID(int id);
    void set_Time(Time T);
    int get_ID();
    Time get_Time();
    void Execute(Company* myComp);
};

