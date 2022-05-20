#pragma once
#include"Company.h"
#include"Time.h"
#include"UI.h"
#include"InteractiveMode.h"
#include"StepbystepMode.h"
#include"SilentMode.h"


class InterfaceOutput
{
public:
	void Simulate(Company* c1,Time t);
};

