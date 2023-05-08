#pragma once
#include "questions.h"
#include "print.h"
#include "fileHandling.h"
#include <conio.h>
#include <stdio.h>

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

char menu(bool pc = false) {
    system("cls");
	//Declare
	char a = '0';
	if (!pc) {
		//Ask use what they want to do
		printHead();
        std::cout
            << "\t| Welcome! What would you like to do?\t  |" << std::endl
            << "\t|[1] Payroll Computation\t\t  |" << std::endl
            << "\t|[2] Settings\t\t\t\t  |" << std::endl
            << "\t|[3] Load Employee Data\t\t\t  |" << std::endl
            << "\t|[4] Delete Employee Data\t\t  |" << std::endl
            << "\t|[E] Exit\t\t\t\t  |" << std::endl
            << " \t+-----------------------------------------+" << std::endl;
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
                                        system("pause");
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
                                            system("pause");
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
                                                            system("pause");
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
                                                                system("pause");
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
        std::cout << generateRandomMessage(1) << std::endl << "\t";
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
int dempf() {
    //Clear
    system("cls");
    //Ask for the ID you want to remove
    char a;
    std::string id, ext = ".empf", file;
    char idHandler[100];
    std::cout << "Enter the employee ID you want to remove. Enter C to cancel operation: ";
    std::cin >> id;
    confirm:
    system("cls");
    std::cout << "Are you sure you want to delete employee with ID " << id << "? (Y/n): ";
    a = _getch();
    if (a == 'Y' || a == 'y') {
        file = id + ext;
        strcpy_s(idHandler, 100, file.c_str());

        if (id == "C" || id == "c") {
            return 0;
        }

        if (remove(idHandler) != 0) {
            perror("Error Deleting");
            system("pause");
            dempf();
        }
        else {
            std::cout << std::endl << "Successfully removed employee with ID: " << id << std::endl;
            system("pause");
        }
        return 0;
    }
    else if (a == 'N' || a == 'n') {
        return 0;
    }
    else {
        goto confirm;
    }
    
}
