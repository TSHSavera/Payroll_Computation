#pragma once
#include "questions.h"
#include "print.h"
#include <conio.h>

int tryAgain(bool start = false) {
	//Declare
	int a = 0;
	if (start = true) {
		//Ask use what they want to do
		printHead();
		std::cout
			<< "Welcome! What would you like to do?" << std::endl
			<< "[1] Payroll Computation" << std::endl
			<< "[2] Edit Name" << std::endl
			<< "[3] Edit Variables" << std::endl
			<< "[4] Load Employee Data" << std::endl
			<< "[5] Load Config File"
			<< "[6] Save Config and Preferences" << std::endl;
		a = _getch();

		//Check
	}
	else if (start = false) {
		//Ask use what they want to do
		printHead();
		std::cout
			<< generateRandomMessage(3)
			<< " What would you like to do?" << std::endl
			<< "[1] Payroll Computation" << std::endl
			<< "[2] Edit Variables" << std::endl
			<< "[3] Load Employee Data" << std::endl
			<< "[4] Load Config File" << std::endl
			<< "[5] Save Config and Preferences" << std::endl
			<< "[6] Save employee data into a file" << std::endl;
		a = _getch();

		//Check
	}

	return 1;
}
