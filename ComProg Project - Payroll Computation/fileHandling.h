#pragma once
#include "questions.h";
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>

int randomizer() {
	//RNG
	srand((unsigned)time(NULL));
	int rng = 100000 + rand() % 99999;
	return rng;
}

void createEmployeeFile(char calcuType = ' ', std::string fname = " ", std::string mname = " ", std::string lname = " ", double customEmployeeRate = -1, int presentDays = -1, char shiftType = ' ', char dependencyStatus = ' ', int numberOfPresentOnHoliday = -1, int numberOfPresentOnRestDay = -1, int numberOfPresentOnRestHoliDay = -1, int numberOfOvertimeHours = -1, int numberOfSpecialOvertimeHours = -1, double computedGrosspay = 0.0, double computedTax = 0.0, double computedNetPay = 0.0) {
	//Create
	std::string b = std::to_string(randomizer());
	std::string a = b + ".empf";
	std::ofstream employeeFile(a);

	//Write employeeData
	employeeFile
		<< "$" << calcuType
		<< "$" << fname
		<< "$" << mname
		<< "$" << lname
		<< "$" << customEmployeeRate
		<< "$" << presentDays
		<< "$" << shiftType
		<< "$" << dependencyStatus
		<< "$" << numberOfPresentOnHoliday
		<< "$" << numberOfPresentOnRestDay
		<< "$" << numberOfPresentOnRestHoliDay
		<< "$" << numberOfOvertimeHours
		<< "$" << numberOfSpecialOvertimeHours
		<< "$" << computedGrosspay
		<< "$" << computedTax
		<< "$" << computedNetPay
		;
	
	std::cout << "File successfully created with a name of: " << a;
	employeeFile.close();
}

void loadEmployeeFile(std::string id) {
	std::string a = id + ".empf";
	std::string content = " ";
	std::ifstream employeeFile(a);
	std::string P;
	
	while (std::getline(employeeFile, content)) {
		std::stringstream T(content);
		while (std::getline(T, P, '$')) {
			std::cout << P << std::endl;
		}
	}

	employeeFile.close();
}