#pragma once
#include "Event.h"
class Promote_Event :
    public Event
{
    int Extra_Money;
    int ID;
public:
    Promote_Event(Time T, int id, int extra);
    void set_Extra_Money(int extra);
    void set_ID(int id);
    int get_ID();
    int get_Extra_Money();
    void Execute(Company* myComp);
};

