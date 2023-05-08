#pragma once
#include "questions.h";
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

int loadEditEmployeeData(std::string, char, std::string, std::string, std::string, double, int, char, char, int, int, int, int, int, double, double, double);

int randomizer() {
	//RNG
	srand((unsigned)time(NULL));
	int rng = 100000 + rand() % 99999;
	return rng;
}

void createEmployeeFile(char calcuType = ' ', std::string fname = " ", std::string mname = " ", std::string lname = " ", double customEmployeeRate = -1, int presentDays = -1, char shiftType = ' ', char dependencyStatus = ' ', int numberOfPresentOnHoliday = -1, int numberOfPresentOnRestDay = -1, int numberOfPresentOnRestHoliDay = -1, int numberOfOvertimeHours = -1, int numberOfSpecialOvertimeHours = -1, double computedGrosspay = 0.0, double computedTax = 0.0, double computedNetPay = 0.0, bool ow = false, std::string id = " ") {
	if (!ow) {
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

		std::cout << "File successfully created with a name of: " << a << std::endl;
		employeeFile.close();
	}
	else if (ow) {
		//Open
		std::string b = id;
		std::string a = b + ".empf";
		std::ofstream employeeFile(a, std::ofstream::trunc);

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

		std::cout << "Changes were saved on: " << a << std::endl;
		employeeFile.close();
		system("pause");
	}
}

void loadEmployeeFile(std::string id) {
	std::string a = id + ".empf";
	std::string content = " ";
	std::ifstream employeeFile(a);
	std::string P;
	int n = 0;
	char ct, st, ds = ' ';
	int pd, nph, npr, nphr, ot, ots;
	double cer, gp, ts, np;
	std::string fn, mn, ln;

	while (std::getline(employeeFile, content)) {
		std::stringstream T(content);
		while (std::getline(T, P, '$')) {
			if (n == 1) {
				ct = P[0];
			}
			else if (n == 2) {
				fn = P;
			}
			else if (n == 3) {
				mn = P;
			}
			else if (n == 4) {
				ln = P;
			}
			else if (n == 5) {
				cer = std::stod(P);
			}
			else if (n == 6) {
				pd = std::stoi(P);
			}
			else if (n == 7) {
				st = P[0];
			}
			else if (n == 8) {
				ds = P[0];
			}
			else if (n == 9) {
				nph = std::stoi(P);
			}
			else if (n == 10) {
				npr = std::stoi(P);
			}
			else if (n == 11) {
				nphr = std::stoi(P);
			}
			else if (n == 12) {
				ot = std::stoi(P);
			}
			else if (n == 13) {
				ots = std::stoi(P);
			}
			else if (n == 14) {
				gp = std::stod(P);
			}
			else if (n == 15) {
				ts = std::stod(P);
			}
			else if (n == 16) {
				np = std::stod(P);
			}
			n++;
		}
		loadEditEmployeeData(id, ct, fn, mn, ln, cer, pd, st, ds, nph, npr, nphr, ot, ots, gp, ts, np);
	}

	employeeFile.close();
}