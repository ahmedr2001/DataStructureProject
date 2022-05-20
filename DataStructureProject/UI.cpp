#include "UI.h"

template <typename T>
void UI::GetInput(T& input)
{
	cin >> input;
}


void UI::PrintMessage(string message)
{
	cout << message;
}

void UI::getLine(char* input, int size)
{
	cin.getline(input, size);
}

template void UI::GetInput<int>(int& input);
template void UI::GetInput<double>(double& input);