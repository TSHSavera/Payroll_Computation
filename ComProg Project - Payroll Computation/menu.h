#pragma once
#include "questions.h"
#include "print.h"
#include <conio.h>

char menu(bool pc = false) {
	//Declare
	char a = '0';
	if (pc = true) {
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
	else if (pc = false) {
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

int pc(double arrCC[3]) {
    //Function Variables
start:
    char calcuType = calculationType();



    //Check calcuType
    if (calcuType == '1') {
        if (femployeeName_first() == 0) {
            if (femployeeName_mid() == 0) {
                if (femployeeName_last() == 0) {
                    //Only Asks for Basics
                    int a = femployeeCode();

                    //  Chapter - Employee Code Main
                    if (a == 0) {
                        //  Chapter - Present Days
                        //Go code without fcCustomEmployee
                        if (fpresentDays() == 0) {
                            //  Chapter - Shift Type
                            if (fshiftType() == 0) {
                                //  Chapter - Dependency
                                if (fdependencyType() == 0) {
                                    //  Chapter - Summary before processing
                                    if (showBasicSummary() == 0) {
                                        // TODO: IF TA RETURNS 1 GOTO START AGAIN, ELSE EXIT.
                                        tryAgain();
                                    }
                                }
                            }
                        }
                    }
                    if (a == 1) {
                        //  Chapter - Custom Employee Rate
                        if (fcCustomEmployeeRate() == 0) {
                            //  Chapter - Present Days
                            if (fpresentDays() == 0) {
                                //  Chapter - Shift Type
                                if (fshiftType() == 0) {
                                    //  Chapter - Dependency
                                    if (fdependencyType() == 0) {
                                        //  Chapter - Summary before processing
                                        if (showBasicSummary() == 0) {
                                            tryAgain();
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
        if (femployeeName_first() == 0) {
            if (femployeeName_mid() == 0) {
                if (femployeeName_last() == 0) {
                    //Only ask for advanced
                    int a = femployeeCode();

                    //  Chapter - Employee Code Main
                    if (a == 0) {
                        //  Chapter - Present Days
                        //Go code without fcCustomEmployee
                        if (fpresentDays(false, true) == 0) {
                            //  Chapter - Shift Type
                            if (fshiftType() == 0) {
                                //  Chapter - Dependency
                                if (fdependencyType() == 0) {
                                    //  Chapter - Number of days present in holidays
                                    if (fpresentInHoliday() == 0) {
                                        //  Chapter - Number of days present in rest
                                        if (fpresentInRest() == 0) {
                                            //  Chapter - Number of days present in holirest
                                            if (fpresentInHoliRest() == 0) {
                                                //  Chapter - Number of overtime hours
                                                if (overtimeHours() == 0) {
                                                    //  Chapter - Number of special overtime hours
                                                    if (overtimeHoursSpecial() == 0) {
                                                        //  Chapter - Summary before processing
                                                        if (showSummaryAdvance() == 0) {
                                                            tryAgain();
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
                        if (fcCustomEmployeeRate() == 0) {
                            //  Chapter - Present Days
                            if (fpresentDays(false, true) == 0) {
                                //  Chapter - Shift Type
                                if (fshiftType() == 0) {
                                    //  Chapter - Dependency
                                    if (fdependencyType() == 0) {
                                        //  Chapter - Number of days present in holidays
                                        if (fpresentInHoliday() == 0) {
                                            //  Chapter - Number of days present in rest
                                            if (fpresentInRest() == 0) {
                                                //  Chapter - Number of days present in holirest
                                                if (fpresentInHoliRest() == 0) {
                                                    //  Chapter - Number of overtime hours
                                                    if (overtimeHours() == 0) {
                                                        //  Chapter - Number of special overtime hours
                                                        if (overtimeHoursSpecial() == 0) {
                                                            //  Chapter - Summary before processing
                                                            if (showSummaryAdvance() == 0) {
                                                                tryAgain();
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
}
