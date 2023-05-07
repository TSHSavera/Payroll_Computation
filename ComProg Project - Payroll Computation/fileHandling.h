#pragma once
#include <fstream>

void createEmployeeFile(char calcuType = ' ', std::string name = " ", char employeeCode = ' ', double customEmployeeRate = -1, int presentDays = -1, char shiftType = ' ', char dependencyStatus = ' ', int numberOfPresentOnHoliday = -1, int numberOfPresentOnRestDay = -1, int numberOfPresentOnRestHoliDay = -1, int numberOfOvertimeHours = -1, int numberOfSpecialOvertimeHours = -1) {
	//Create
	std::ofstream employeeFile("test.empf");

	//Write employeeData
	

}