#pragma once
#include "Event.h"
#include "Company.h"
class Promote_Event :
    public Event
{
    int Extra_Money;
    
public:
    Promote_Event(Time T, int id, int extra);
    void set_Extra_Money(int extra);
    int get_Extra_Money();
    void Execute(Company* myComp);
};

