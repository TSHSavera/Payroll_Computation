#pragma once
#include "print.h"
#include <conio.h>

int tryAgain() {
	//Declare
	int a = 0;
	//Ask use what they want to do
	printHead();
	std::cout
		<< "Welcome! What would you like to do?" << std::endl
		<< "[1] Payroll Computation" << std::endl
		<< "[2] Edit Variables" << std::endl
		<< "[3] Import Employee Data" << std::endl
		<< "[4] ";
	a = _getch();

	//Check

	return 1;
}
