#pragma once
#include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>

void printOutValues(char calcuType = ' ', std::string fname = " ", std::string mname = " ", std::string  lname = " ", char employeeCode = ' ', double customEmployeeRate = -1, int presentDays = -1, char shiftType = ' ', char dependencyStatus = ' ', int numberOfPresentOnHoliday = -1, int numberOfPresentOnRestDay = -1, int numberOfPresentOnRestHoliDay = -1, int numberOfOvertimeHours = -1, int numberOfSpecialOvertimeHours = -1) {

    if (calcuType != ' ') {
        if (calcuType == '1') {

            std::cout << "\t| 0. Calculation Type: Basic\t\t  |" << std::endl;
            std::cout << "\t+-----------------------------------------+" << std::endl;
        }
        else if (calcuType == '2') {
            std::cout << "\t| 0. Calculation Type: Advance\t\t  |" << std::endl;
            std::cout << "\t+-----------------------------------------+" << std::endl;
        }
    }

    if (fname != " ") {
        std::cout << "\t| 1. First Name: " << fname << "\t          |" << std::endl;
        std::cout << "\t+-----------------------------------------+" << std::endl; 
    }
    if (mname != " ") {
        std::cout << "\t| 2. Middle Name: " << mname << "\t\t  |" << std::endl;
        std::cout << "\t+-----------------------------------------+" << std::endl;
    }
    if (lname != " ") {
        std::cout << "\t| 3.  Last Name: " << lname << "\t\t  |" << std::endl;
        std::cout << "\t+-----------------------------------------+" << std::endl;
    }


    if (employeeCode != ' ') {
        if (customEmployeeRate != -1) {
         
            std::cout << "\t| 4. Employee Code: " << employeeCode << "\t\t\t  |" << std::endl;
            std::cout << "\t+-----------------------------------------+" << std::endl;
            std::cout << std::fixed << std::setprecision(2) << "\t| 5. Custom Employee Rate: " << customEmployeeRate << "\t  |" << std::endl;
            std::cout << "\t+-----------------------------------------+" << std::endl;

            if (presentDays != -1) {
                std::cout << "\t| 6. Number of Present Days: " << presentDays << " \t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }

            if (shiftType != ' ') {
                if (shiftType == '1') {
                    std::cout << "\t| 7. Shift Type: Regular Shift" << " \t\t  |" << std::endl;
                    std::cout << "\t+-----------------------------------------+" << std::endl;
                }
                else if (shiftType == '2') {
                    std::cout << "\t| 7. Shift Type: Night Shift" << " \t\t  |" << std::endl;
                    std::cout << "\t+-----------------------------------------+" << std::endl;
                }
            }

            if (dependencyStatus != ' ') {
                if (dependencyStatus == '2') {
                    std::cout << "\t\| 8. Dependency Type: Without Dependents" << "  |" << std::endl;
                    std::cout << "\t+-----------------------------------------+" << std::endl;
                }
                else if (dependencyStatus == '1') {
                    std::cout << "\t\| 8. Dependency Type: With Dependents" << "\t  |" << std::endl;
                    std::cout << "\t+-----------------------------------------+" << std::endl;
                }
            }

            if (numberOfPresentOnHoliday != -1) {
                std::cout << "\t| 9. Number of Present on Holidays: " << numberOfPresentOnHoliday << "\t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }


            if (numberOfPresentOnRestDay != -1) {
                std::cout << "\t| 10. Number of Present on Restday: " << numberOfPresentOnRestDay << "\t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }

            if (numberOfPresentOnRestHoliDay != -1) {
                std::cout << "\t| 11. Number of Present on Rest/Holiday: " << numberOfPresentOnRestHoliDay << "|" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }

            if (numberOfOvertimeHours != -1) {
                std::cout << "\t| 12. Number of Overtime Hours: " << numberOfOvertimeHours << "\t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }

            if (numberOfSpecialOvertimeHours != -1) {
                std::cout << "\t| 13. Number of SP Overtime Hours: " << numberOfSpecialOvertimeHours << "   \t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }
        }
        else {
            std::cout << "\t| 4. Employee Code: " << employeeCode << "\t\t\t  |" << std::endl;
            std::cout << "\t+-----------------------------------------+" << std::endl;

            if (presentDays != -1) {
                std::cout << "\t| 5. Number of Present Days: " << presentDays << " \t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }

            if (shiftType != ' ') {
                if (shiftType == '1') {
                    std::cout << "\t| 6. Shift Type: Regular Shift" << " \t\t  |" << std::endl;
                    std::cout << "\t+-----------------------------------------+" << std::endl;
                }
                else if (shiftType == '2') {
                    std::cout << "\t| 6. Shift Type: Night Shift" << " \t\t  |" << std::endl;
                    std::cout << "\t+-----------------------------------------+" << std::endl;
                }
            }

            if (dependencyStatus != ' ') {
                if (dependencyStatus == '2') {
                    std::cout << "\t\| 7. Dependency Type: Without Dependents" << "  |" << std::endl;
                    std::cout << "\t+-----------------------------------------+" << std::endl;
                }
                else if (dependencyStatus == '1') {
                    std::cout << "\t\| 7. Dependency Type: With Dependents" << "\t  |" << std::endl;
                    std::cout << "\t+-----------------------------------------+" << std::endl;
                }
            }

            if (numberOfPresentOnHoliday != -1) {
                std::cout << "\t| 8. Number of Present on Holidays: " << numberOfPresentOnHoliday << "\t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }


            if (numberOfPresentOnRestDay != -1) {
                std::cout << "\t| 9. Number of Present on Restday: " << numberOfPresentOnRestDay << "\t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }

            if (numberOfPresentOnRestHoliDay != -1) {
                std::cout << "\t| 10. Number of Present on Rest/Holiday: " << numberOfPresentOnRestHoliDay << "|" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }

            if (numberOfOvertimeHours != -1) {
                std::cout << "\t| 11. Number of Overtime Hours: " << numberOfOvertimeHours << "\t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }

            if (numberOfSpecialOvertimeHours != -1) {
                std::cout << "\t| 12. Number of SP Overtime Hours: " << numberOfSpecialOvertimeHours << "   \t  |" << std::endl;
                std::cout << "\t+-----------------------------------------+" << std::endl;
            }
        }
    }

    


    std::cout << std::endl;
}

void printHead() {
    //  Print Head
    std::cout << std::endl;
    std::cout << "\t\+-----------------------------------------+" << std::endl;
    std::cout << "\t\|                PAY TECH                 |" << std::endl;
    std::cout << "\t\|         -- precision payroll --         |" << std::endl;
    std::cout << "\t\+-----------------------------------------+" << std::endl;
}

void printFinal(int type = 1,double gp = 0.00, double td = 0.00, double np = 0.00) {
    if (type == 1) {
        std::cout
            << std::fixed << std::setprecision(2)
            << "\t\+-----------------------------------------+" << std::endl
            << "\t\|             FINAL RESULTS           \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t\|\tGross Pay : PHP " << gp << "    \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t\|\tTax: PHP " << td << "  \t\t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t\|\tNet Pay: PHP " << np << "  \t\t  |" << std::endl
            << "\t\+-----------------------------------------+\n\n" << std::endl;
    }
    else if (type == 2) {
        std::cout
            << std::fixed << std::setprecision(2)
            << "\t\+-----------------------------------------+" << std::endl
            << "\t\|          COMPUTED RESULTS           \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t\|\tGross Pay : PHP " << gp << "    \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t\|\tTax: PHP " << td << "  \t\t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t\|\tNet Pay: PHP " << np << " \t\t  |" << std::endl
            << "\t\+-----------------------------------------+\n\n" << std::endl;
    }
}
