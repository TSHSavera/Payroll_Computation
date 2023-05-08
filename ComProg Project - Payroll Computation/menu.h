#pragma once
#include "questions.h"
#include "print.h"
#include "fileHandling.h"
#include <conio.h>

int calculationType();
int femployeeName_first(bool);
int femployeeName_mid(bool);
int femployeeName_last(bool);
int femployeeCode(bool);
int fcCustomEmployeeRate(bool);
int fpresentDays(bool, bool);
int fshiftType(bool);
int fdependencyType(bool);
int showBasicSummary();
int fpresentInHoliday(bool);
int fpresentInRest(bool);
int fpresentInHoliRest(bool);
int overtimeHours(bool);
int overtimeHoursSpecial(bool);
int showSummaryAdvance();

char menu(bool pc) {
	//Declare
	char a = '0';
	if (pc = false) {
		//Ask use what they want to do
		printHead();
        std::cout
            << "Welcome! What would you like to do?" << std::endl
            << "[1] Payroll Computation" << std::endl
            << "[2] Edit Variables" << std::endl
            << "[3] Load Employee Data" << std::endl
            << "[4] Load Config File" << std::endl
            << "[5] Save Config" << std::endl
            << "[E] Exit" << std::endl;
		a = _getch();

		//Send the value to main function
		return a;
	}
	else if (pc = true) {
		//Ask use what they want to do
		printHead();
		std::cout
			<< generateRandomMessage(3)
			<< " What would you like to do?" << std::endl
			<< "[1] Payroll Computation" << std::endl
			<< "[2] Edit Variables" << std::endl
			<< "[3] Load Employee Data" << std::endl
			<< "[4] Load Config File" << std::endl
			<< "[5] Save Config" << std::endl
			<< "[6] Save Employee data into a file" << std::endl
            << "[E] Exit" << std::endl;
		a = _getch();

		//Send the value to main function
		return a;
	}
}

int pc() {
    //Function Variables
    char calcuType = calculationType();



    //Check calcuType
    if (calcuType == '1') {
        if (femployeeName_first(false) == 0) {
            if (femployeeName_mid(false) == 0) {
                if (femployeeName_last(false) == 0) {
                    //Only Asks for Basics
                    int a = femployeeCode(false);

                    //  Chapter - Employee Code Main
                    if (a == 0) {
                        //  Chapter - Present Days
                        //Go code without fcCustomEmployee
                        if (fpresentDays(false, false) == 0) {
                            //  Chapter - Shift Type
                            if (fshiftType(false) == 0) {
                                //  Chapter - Dependency
                                if (fdependencyType(false) == 0) {
                                    //  Chapter - Summary before processing
                                    if (showBasicSummary() == 0) {
                                        // TODO: IF TA RETURNS 1 GOTO START AGAIN, ELSE EXIT.
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                    if (a == 1) {
                        //  Chapter - Custom Employee Rate
                        if (fcCustomEmployeeRate(false) == 0) {
                            //  Chapter - Present Days
                            if (fpresentDays(false, false) == 0) {
                                //  Chapter - Shift Type
                                if (fshiftType(false) == 0) {
                                    //  Chapter - Dependency
                                    if (fdependencyType(false) == 0) {
                                        //  Chapter - Summary before processing
                                        if (showBasicSummary() == 0) {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (calcuType == '2') {
        if (femployeeName_first(false) == 0) {
            if (femployeeName_mid(false) == 0) {
                if (femployeeName_last(false) == 0) {
                    //Only ask for advanced
                    int a = femployeeCode(false);

                    //  Chapter - Employee Code Main
                    if (a == 0) {
                        //  Chapter - Present Days
                        //Go code without fcCustomEmployee
                        if (fpresentDays(false, true) == 0) {
                            //  Chapter - Shift Type
                            if (fshiftType(false) == 0) {
                                //  Chapter - Dependency
                                if (fdependencyType(false) == 0) {
                                    //  Chapter - Number of days present in holidays
                                    if (fpresentInHoliday(false) == 0) {
                                        //  Chapter - Number of days present in rest
                                        if (fpresentInRest(false) == 0) {
                                            //  Chapter - Number of days present in holirest
                                            if (fpresentInHoliRest(false) == 0) {
                                                //  Chapter - Number of overtime hours
                                                if (overtimeHours(false) == 0) {
                                                    //  Chapter - Number of special overtime hours
                                                    if (overtimeHoursSpecial(false) == 0) {
                                                        //  Chapter - Summary before processing
                                                        if (showSummaryAdvance() == 0) {
                                                            return 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (a == 1) {
                        //  Chapter - Custom Employee Rate
                        if (fcCustomEmployeeRate(false) == 0) {
                            //  Chapter - Present Days
                            if (fpresentDays(false, true) == 0) {
                                //  Chapter - Shift Type
                                if (fshiftType(false) == 0) {
                                    //  Chapter - Dependency
                                    if (fdependencyType(false) == 0) {
                                        //  Chapter - Number of days present in holidays
                                        if (fpresentInHoliday(false) == 0) {
                                            //  Chapter - Number of days present in rest
                                            if (fpresentInRest(false) == 0) {
                                                //  Chapter - Number of days present in holirest
                                                if (fpresentInHoliRest(false) == 0) {
                                                    //  Chapter - Number of overtime hours
                                                    if (overtimeHours(false) == 0) {
                                                        //  Chapter - Number of special overtime hours
                                                        if (overtimeHoursSpecial(false) == 0) {
                                                            //  Chapter - Summary before processing
                                                            if (showSummaryAdvance() == 0) {
                                                                return 0;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
        system("pause");
        calculationType();
    }
    return 0;
}


int led() {
    std::cout << "Type employee ID: ";
    std::string a = " ";
    std::cin >> a;
    loadEmployeeFile(a);
    return 0;
}
int se() {
    createEmployeeFile('1', "tangina", "tangina", "tangina", 250.0, 23, '2', '2', 2, 2, 2, 24, 24, 26000.00, 2000.00, 24000.00);
    return 0;
}
