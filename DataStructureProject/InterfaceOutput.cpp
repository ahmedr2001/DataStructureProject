#include "InterfaceOutput.h"

void InterfaceOutput::Simulate(Company* c1,Time t)
{
	c1->LoadTrucksAndEventsData("test4");
	UI* uiObject = c1->GetUIObject();

	int simMode;
	uiObject->PrintMessage("Which simulation mode would you like?\n");
	uiObject->PrintMessage("1-Interactive Mode 2-Step-By-Step Mode 3-Silent Mode\n");
	uiObject->GetInput(simMode);
	if (simMode == 2) {
		StepbystepMode::Simulate(c1, t);
	}
	else if (simMode == 1) {
		InteractiveMode::Simulate(c1, t, uiObject);
	}
	else {
		SilentMode::Simulate(c1, t, uiObject);
	}
	c1->PrintToFile("outtest", t);
}