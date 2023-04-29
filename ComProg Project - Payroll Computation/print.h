#pragma once
#include <string>
#include <iostream>

void printOutValues(char calcuType = ' ', char employeeCode = NULL, double customEmployeeRate = -1, int presentDays = -1, char shiftType = ' ', char dependencyStatus = ' ', int numberOfPresentOnHoliday = -1, int numberOfPresentOnRestDay = -1, int numberOfPresentOnRestHoliDay = -1, int numberOfOvertimeHours = -1, int numberOfSpecialOvertimeHours = -1) {

    if (calcuType != ' ') {
        if (calcuType == '1') {

            std::cout << "\t\t\t| 1. Calculation Type: Basic \t\t  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
        }
        else if (calcuType == '2') {
            std::cout << "\t\t\t| 1. Calculation Type: Advance \t\t  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
        }
    }

    if (employeeCode != ' ') {
        if (customEmployeeRate != -1) {

            std::cout << "\t\t\t| 2. Employee Code: " << employeeCode << "\t\t\t  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
            std::cout << "\t\t\t| 2. Custom Employee Rate: " << customEmployeeRate << "\t\t  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
        }
        else {
            std::cout << "\t\t\t| 2. Employee Code: " << employeeCode << "\t\t\t  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
        }
    }

    if (presentDays != -1) {
        std::cout << "\t\t\t| 3. Number of Present Days: " << presentDays << "\t\t  |" << std::endl;
        std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
    }

    if (shiftType != ' ') {
        if (shiftType == '1') {
            std::cout << "\t\t\t| 4. Shift Type: Regular Shift" << "\t\t  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
        }
        else if (shiftType == '2') {
            std::cout << "\t\t\t| 4. Shift Type: Night Shift" << "\t\t  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
        }
    }

    if (dependencyStatus != ' ') {
        if (dependencyStatus == '2') {
            std::cout << "\t\t\t\| 5. Dependency Type: Without Dependents" << "  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
        }
        else if (dependencyStatus == '1') {
            std::cout << "\t\t\t\| 5. Dependency Type: With Dependents" << "\t  |" << std::endl;
            std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
        }
    }

    if (numberOfPresentOnHoliday != -1) {
        std::cout << "\t\t\t| 6. Number of Present on Holidays: " << numberOfPresentOnHoliday << "\t  |" << std::endl;
        std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
    }


    if (numberOfPresentOnRestDay != -1) {
        std::cout << "\t\t\t| 7. Number of Present on Restday: " << numberOfPresentOnRestDay << "\t  |" << std::endl;
        std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
    }

    if (numberOfPresentOnRestHoliDay != -1) {
        std::cout << "\t\t\t| 8. Number of Present on Rest/Holiday: " << numberOfPresentOnRestHoliDay << " |" << std::endl;
        std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
    }

    if (numberOfOvertimeHours != -1) {
        std::cout << "\t\t\t| 9. Number of Overtime Hours: " << numberOfOvertimeHours << "\t  |" << std::endl;
        std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
    }

    if (numberOfSpecialOvertimeHours != -1) {
        std::cout << "\t\t\t| 10. Number of SP Overtime Hours: " << numberOfSpecialOvertimeHours << "   \t  |" << std::endl;
        std::cout << "\t\t\t+-----------------------------------------+" << std::endl;
    }


    std::cout << std::endl;
}

void printHead() {
    //  Print Head
    std::cout << "\t\t\t\+-----------------------------------------+" << std::endl;
    std::cout << "\t\t\t|          PAYROLL COMPUTATION            |" << std::endl;
    std::cout << "\t\t\t\|                                         |" << std::endl;
    std::cout << "\t\t\t\+-----------------------------------------+" << std::endl;
}