#pragma once
#include <iostream>
using namespace std;
enum Type
{
	VIP,
	Normal,
	special
};
class UI
{
public:

	UI() {}

	void PrintMessage(string message);
};

