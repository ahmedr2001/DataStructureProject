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
	template <typename T>
	void GetInput(T& input);
	void PrintMessage(string message);
	void getLine(char* input, int size);
};