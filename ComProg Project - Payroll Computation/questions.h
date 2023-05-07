#pragma once
#include "checkuserinput.h"
#include "messages.h"
#include "print.h"
#include "grosspay.h"
#include "taxdep.h"
#include "netpay.h"
#include "menu.h"
#include <conio.h>
#include <string>


//Initialize Variables
std::string name = " ";
char employeeCode;
int presentDays = 0, numberOfPresentOnRestDay = 0, numberOfPresentOnHoliday = 0, numberOfPresentOnRestHoliDay = 0, numberOfOverHours = 0, numberOfSpecialOverHours = 0, numberOfAbsent = 0;
double grossPay = 0.00, netPay = 0.00, tax = 0.00, customEmployeeRate = -1;
char calcuType = '0', shiftType = '0', dependencyStatus = '0';

//  Advance Counters
int totalPresentDays = 0;

int showBasicSummary();
void fcalculateAdvance();
int showSummaryAdvance();


int calculationType() {
    //Clear
    //system("cls");
    //Start Asking for user inputs
    printHead();
    //Ask for calculation type
    std::cout << "\t\t\tPlease choose a calculation type." << std::endl;
    std::cout << "\t\t\tCalculation type: [1] Basic \n\t\t\t\t\t  [2] Advance" << std::endl;
    std::cout << "\t\t\tEnter type: ";
    calcuType = _getch();
    if (calcuType == '1') {
        return calcuType;
    }
    else if (calcuType == '2') {
        return calcuType;
    }
    else {
        std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
        system("pause");
        calculationType();
    }
    
}

int femployeeName(bool edit = false) {
    if (!edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType);
        //Ask
        std::cout << "\t\t\tEnter employee name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        //Perform Checks
        if (name == " ") {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            femployeeName();
        }
    }
    else if (edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType);
        //Ask
        std::cout << "\t\t\tEdit employee name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        //Perform Checks
        if (name == " ") {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            femployeeName();
        }
    }
    return 0;
}

int femployeeCode(bool edit = false) {

    if (!edit) {
        //Input data for the first time/reset
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name);
        //Ask for employee code
        std::cout << "\t\t\tState employee code [A] [B] [C] [D]: ";
        employeeCode = _getch();
        //  Perform Checks
        //  Check if it's not equal with a, b, c, or d
        if (checkUserInput('1', employeeCode) == false) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            femployeeCode();
        }
        //Check if D
        if (employeeCode == 'D' || employeeCode == 'd') {
            //Call custom employee
            return 1;
        }
        // Go
        std::cout << "test" << employeeCode;
        return 0;
    }
    else if (edit) {
        //Input data in edit mode
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode);
        //Ask for employee code
        std::cout << "\t\t\tEdit employee code [A] [B] [C] [D]: ";
        employeeCode = _getch();

        //Clear custom employee rate in change event
        if (employeeCode != 'd' && employeeCode != 'D') {
            customEmployeeRate = -1;
        }

        //  Check if it matches the required inputs
        if (checkUserInput('1', employeeCode) == false) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            femployeeCode(true);
        }
        //  Check if the input is D. If yes, proceed to customEmployeeRate again.
        if (employeeCode == 'd' || employeeCode == 'D') {
            //Call customEmployeeRate again if changed to D
            return 1;
        }
        //If not D, return to preview
        if (employeeCode != 'd' && employeeCode != 'D') {
            return 0;
        }
    }
}


int fcCustomEmployeeRate(bool edit = false) {
    if (!edit) {
        //Ask input if yes
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode);
        std::cout << "\t\t\tEnter custom rate: ";
        std::cin >> customEmployeeRate;

        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            clearInvalid();
            fcCustomEmployeeRate();
        }
        //  Check if not negative
        if (customEmployeeRate <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            fcCustomEmployeeRate();
        }

        return 0;

    }
    else if (edit) {
        //Ask input if yes
        //  Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate);
        std::cout << "\t\t\tEdit custom rate: ";
        std::cin >> customEmployeeRate;
        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            clearInvalid();
            fcCustomEmployeeRate(true);
        }
        //  Check if not negative
        if (customEmployeeRate <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            fcCustomEmployeeRate(true);
        }
        //Return to preview
        return 0;
    }
}


int fpresentDays(bool edit = false, bool adv = false) {
    // Check if advanced mode
    if (!adv) {
        // If not advanced, check if in edit mode
        if (!edit) {
            //If not edit
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate);
            //Ask for number of present days
            std::cout << "\t\t\tState the number of present days: ";
            std::cin >> presentDays;
            //  Check values
            while (std::cin.fail()) {
                clearInvalid();
                fpresentDays();
            }
            if (checkUserInput('2', ' ', presentDays) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays();
            }
            if (checkUserInput('3', ' ', presentDays, 30, 'f')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays();
            }
            return 0;
        }
        
        else if (edit) {
            //If not advanced, but in edit mode
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays);
            //Ask for number of present days
            std::cout << "\t\t\tEdit the number of present days: ";
            std::cin >> presentDays;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentDays();
            }
            if (checkUserInput('2', ' ', presentDays) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays();
            }
            if (checkUserInput('3', ' ', presentDays, 30, 'f')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays();
            }

            return 0;
        }
    }
    else if (adv) {
        //Present Days - Advanced
        //Clear
        if (!edit) {
            // Set Variables
            totalPresentDays = 0;
            numberOfPresentOnHoliday = 0;
            numberOfPresentOnRestDay = 0;
            numberOfPresentOnRestHoliDay = 0;
            //  Ask for number of present days
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate);
            std::cout << "\t\t\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\t\t\tState the number of REGULAR present days: ";
            std::cin >> presentDays;
            //  Error checking
            while (std::cin.fail()) {
                clearInvalid();
                fpresentDays(false, true);
            }
            if (checkUserInput('2', ' ', presentDays) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays(false, true);
            }
            if (checkUserInput('3', ' ', presentDays, 30, 'f')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays(false, true);
            }
            int a = totalPresentDays;
            if (checkUserInput('3', ' ', a + presentDays, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays(false, true);
            }
            totalPresentDays += presentDays;
            return 0;
        }
        else if (edit) {
            totalPresentDays -= presentDays;
            //Ask for number of present days
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate);
            std::cout << "\t\t\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\t\t\tEdit the number of REGULAR present days: ";
            std::cin >> presentDays;
            //  Error checking
            while (std::cin.fail()) {
                clearInvalid();
                fpresentDays(true, true);
            }
            if (checkUserInput('2', ' ', presentDays) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays(true, true);
            }
            if (checkUserInput('3', ' ', presentDays, 30, 'f')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays(true, true);
            }
            int a = totalPresentDays;
            if (checkUserInput('3', ' ', a + presentDays, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentDays(true, true);
            }

            totalPresentDays += presentDays;
            //  Go back to preview
            return 0;
        }
    }
}

int fshiftType(bool edit = false) {
    if (!edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays);
        //Ask for shift type
        std::cout << "\t\t\tState the shift type (1 - Regular, 2 - Night): ";
        shiftType = _getch();

        //Check input
        if (checkUserInput('4', ' ', shiftType, '1') == false) {
            if (checkUserInput('4', ' ', shiftType, '2') == false) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fshiftType();
            }
        }

        return 0;
    }
    else if (edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType);
        //Ask for shift type
        std::cout << "\t\t\tEdit the shift type (1 - Regular, 2 - Night): ";
        shiftType = _getch();

        //Check input
        if (checkUserInput('4', ' ', shiftType, '1') == false) {
            if (checkUserInput('4', ' ', shiftType, '2') == false) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fshiftType(true);
            }
        }
        //Return to preview after editing
        return 0;
    }

}

int fdependencyType(bool edit = false) {
    if (!edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType);
        //Ask for dependency
        std::cout << "\t\t\tState the dependency type (1 - With, 2 - Without): ";
        dependencyStatus = _getch();

        //Check input
        if (checkUserInput('4', ' ', dependencyStatus, '1') == false) {
            if (checkUserInput('4', ' ', dependencyStatus, '2') == false) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fdependencyType();
            }
        }

        return 0;
    }
    else if (edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask for dependency
        std::cout << "\t\t\tEdit the dependency type (1 - With, 2 - Without): ";
        dependencyStatus = _getch();

        //Check input
        if (checkUserInput('4', ' ', dependencyStatus, '1') == false) {
            if (checkUserInput('4', ' ', dependencyStatus, '2') == false) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fdependencyType(true);
            }
        }
        //Return to preview after editing
        return 0;
    }
}

// Question - Result
void fcalculateBasic() {
    //  Clear before processing then display the data values
    //system("cls");
    printHead();
    printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
    double computedGrossPay = 0.0, computedTaxDependency = 0.0, computedNetPay = 0.0;
    //Compute
    if (employeeCode != 'D' && employeeCode != 'd') {
        
        computedGrossPay = computeGrossPay('1', employeeCode, presentDays, shiftType);
        computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
        computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
        printFinal(computedGrossPay, computedTaxDependency, computedNetPay);
    }
    else {
        computedGrossPay = computeGrossPay('1', employeeCode, presentDays, shiftType, customEmployeeRate);
        computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
        computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
        printFinal(computedGrossPay, computedTaxDependency, computedNetPay);
    }
    
}

// Preview Results
int showBasicSummary() {
    int a = 0;
    if (employeeCode != 'd' && employeeCode != 'D') {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl << std::endl
            << "\t\tEnter 0 if it's final. Pick a value from 1-5: ";

        std::cin >> a;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            showBasicSummary();
        }
        //  Check input
        switch (a) {
        case 0:
            fcalculateBasic();
            return 0;
            break;
        case 1:
            if (femployeeName(true) == 0) {
                showBasicSummary();
            }
        case 2:
            if (femployeeCode(true) == 0) {
                showBasicSummary();
            }
            break;
        case 3:
            if (fpresentDays(true) == 0) {
                showBasicSummary();
            }
            break;
        case 4:
            if (fshiftType(true) == 0) {
                showBasicSummary();
            }
            break;
        case 5:
            if (fdependencyType(true) == 0) {
                showBasicSummary();
            }
            break;
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            showBasicSummary();
            break;
        }
    }
    else if (employeeCode == 'd' || employeeCode == 'D') {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl << std::endl
            << "\t\tEnter 0 if it's final. If not, pick a value from 1-6: ";

        std::cin >> a;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            showBasicSummary();
        }
        //  Check input
        switch (a) {
        case 0:
            fcalculateBasic();
            return 0;
            break;
        case 1:
            if (femployeeName(true) == 0) {
                showBasicSummary();
            }
        case 2:
            if (femployeeCode(true) == 0) {
                showBasicSummary();
            }
            break;
        case 3:
            if (fcCustomEmployeeRate(true) == 0) {
                showBasicSummary();
            }
            break;
        case 4:
            if (fpresentDays(true) == 0) {
                showBasicSummary();
            } 
            break;
        case 5:
            if (fshiftType(true) == 0) {
                showBasicSummary();
            }
            break;
        case 6:
            if (fdependencyType(true) == 0) {
                showBasicSummary();
            }
            break;
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            showBasicSummary();
            break;
        }
    }
    return 0;
}


int fpresentInHoliday(bool edit = false) {
    if (!edit) {
        //  Check if the total present days is 30
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tProceeding without adding more days...\n\t\t\tSkipping other day-related inputs..." << std::endl << "\t\t\t";
            system("pause");
            return 0;
        }
        else {
            //Ask for present in holidays
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
            std::cout << "\t\t\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\t\t\tState the number of days present in holidays: ";
            std::cin >> numberOfPresentOnHoliday;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInHoliday();
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnHoliday) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliday();
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnHoliday, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliday();
            }
            //  Add to Total Days if total days is not 30
            totalPresentDays += numberOfPresentOnHoliday;
        }
    }
    else if (edit) {
        //Reset value from rollbacks
        totalPresentDays -= numberOfPresentOnHoliday;
        numberOfPresentOnHoliday = 0;
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tChange other value before\n\t\t\tyou can edit this one..." << std::endl << "\t\t\t";            system("pause");
            return 0;
        }
        else {
            //Ask for present in holidays
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
            std::cout << "\t\t\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\t\t\tEdit the number of days present in holidays: ";
            std::cin >> numberOfPresentOnHoliday;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInHoliday(true);
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnHoliday) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliday(true);
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnHoliday, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliday(true);
            }
            //  Add to Total Days if total days is not 30
            totalPresentDays += numberOfPresentOnHoliday;
        }
    }
    return 0;
}

int fpresentInRest(bool edit = false) {
    //  Check if the total present days is 30
    if (!edit) {
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tProceeding without adding more days...\n\t\t\tSkipping other day-related inputs..." << std::endl << "\t\t\t";
            system("pause");
            return 0;
        }
        else {
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday);
            //Ask for present in rest days
            std::cout << "\t\t\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\t\t\tState the number of days present in rest day: ";
            std::cin >> numberOfPresentOnRestDay;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInRest();
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnRestDay) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInRest();
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestDay, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInRest();
            }
            //  Add to Total Days if total days is not 30
            totalPresentDays += numberOfPresentOnRestDay;
        }
    }
    else if (edit) {
        //Reset value from rollbacks
        totalPresentDays -= numberOfPresentOnRestDay;
        numberOfPresentOnRestDay = 0;
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tChange other value before\n\t\t\tyou can edit this one..." << std::endl << "\t\t\t";            system("pause");
            return 0;
        }
        else {
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday);
            //Ask for present in rest days
            std::cout << "\t\t\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\t\t\tEdit the number of days present in rest day: ";
            std::cin >> numberOfPresentOnRestDay;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInRest(true);
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnRestDay) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInRest(true);
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestDay, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInRest(true);
            }
        }
        //  Add to Total Days if total days is not 30
        totalPresentDays += numberOfPresentOnRestDay;
    }
    return 0;
}

int fpresentInHoliRest(bool edit = false) {
    if (!edit) {
        //  Check if the total present days is 30
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tProceeding without adding more days...\n\t\t\tSkipping other day-related inputs..." << std::endl << "\t\t\t";
            system("pause");
            return 0;
        }
        else {
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay);
            //Ask for present in holi-rest days
            std::cout << "\t\t\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\t\t\tState the number of days present in holiday at the same time rest day: ";
            std::cin >> numberOfPresentOnRestHoliDay;
            //  Check cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInHoliRest();
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnRestHoliDay) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliRest();
            }
            //int b = totalPresentDays + numberOfPresentOnRestHoliDay;
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestHoliDay, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliRest();
            }
            // Check if will go over 30 once added to totalPresentDays
            //int a = ;
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestHoliDay, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                std::cout << totalPresentDays + numberOfPresentOnRestHoliDay << std::endl;
                system("pause");
                fpresentInHoliRest();

            }
            //  Add to Total Days if all tests are passed
            totalPresentDays += numberOfPresentOnRestHoliDay;
        }
    }
    else if (edit) {
        //Reset value from rollbacks
        totalPresentDays -= numberOfPresentOnRestHoliDay;
        numberOfPresentOnRestHoliDay = 0;
        //  Check if the total present days is 30
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tChange other value before\n\t\t\tyou can edit this one..." << std::endl << "\t\t\t";
            system("pause");
            return 0;
        }
        else {
            //system("cls");
            printHead();
            printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay);
            //Ask for present in holi-rest days
            std::cout << "\t\t\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\t\t\tEdit the number of days present in holiday at the same time rest day: ";
            std::cin >> numberOfPresentOnRestHoliDay;
            //  Check cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInHoliRest(true);
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnRestHoliDay) == true) {
                //std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliRest(true);
                std::cout << "I'm the problem b";
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestHoliDay, 31, 'c')) {
                //std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliRest(true);
                std::cout << "I'm the problem c";
            }
            // Check if will go over 30 once added to totalPresentDays
            int a = totalPresentDays;
            if (checkUserInput('3', ' ', a + presentDays, 31, 'c')) {
                //std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
                system("pause");
                fpresentInHoliRest(true);
                std::cout << "I'm the problem d";
            }
            //  Add to Total Days if all tests are passed
            totalPresentDays += numberOfPresentOnRestHoliDay;
        }
    }
    return 0;
}




int overtimeHours(bool edit = false) {
    //system("cls");
    printHead();
    printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay);
    if (!edit) {
        //Ask for Regular OT hours
        std::cout << "\t\t\tState the number of regular day overtime hours: ";
        std::cin >> numberOfOverHours;
        while (std::cin.fail()) {
            clearInvalid();
            overtimeHours();
        }
        //  Check if negative
        if (checkUserInput('2', ' ', numberOfOverHours) == true) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            overtimeHours();
        }
    }
    else if (edit) {
        //Ask for Regular OT hours
        std::cout << "\t\t\tEdit the number of regular day overtime hours: ";
        std::cin >> numberOfOverHours;
        while (std::cin.fail()) {
            clearInvalid();
            overtimeHours(true);
        }
        //  Check if negative
        if (checkUserInput('2', ' ', numberOfOverHours) == true) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            overtimeHours(true);
        }
    }
    return 0;
}

int overtimeHoursSpecial(bool edit = false) {
    if (numberOfPresentOnHoliday == 0 && numberOfPresentOnRestDay == 0 && numberOfPresentOnRestHoliDay == 0) {
        std::cout << "\t\t\tEmployee isn't present in any special day. Skipping special overtime...";
        return 0;
    }
    //system("cls");
    printHead();
    printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours);
    if (!edit) {
        //Ask for present in holi-rest days
        std::cout << "\t\t\tState the number of special day overtime hours (this includes: Rest Day and Holidays): ";
        std::cin >> numberOfSpecialOverHours;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            overtimeHoursSpecial();
        }
        //  Check if negative
        if (checkUserInput('2', ' ', numberOfSpecialOverHours) == true) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            std::cout << "Im the problem";
            system("pause");
            overtimeHoursSpecial(true);
        }
    }
    else if (edit) {
        std::cout << "\t\t\tEdit the number of special day overtime hours (this includes: Rest Day and Holidays): ";
        std::cin >> numberOfSpecialOverHours;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            overtimeHoursSpecial(true);
        }
        //  Check if negative
        if (checkUserInput('2', ' ', numberOfSpecialOverHours) == true) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            std::cout << "Im the problem";
            system("pause");
            overtimeHoursSpecial(true);
        }
    }
    // Return to corresponding functions if edit
    return 0;
}

int showSummaryAdvance() {
    int a = 0;
    if (employeeCode != 'd' && employeeCode != 'D') {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl
            << "\t\tEnter 0 if it's final. Pick a value from 1-10: ";
        std::cin >> a;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            showSummaryAdvance();
        }
        //  Check input
        switch (a) {
        case 0:
            fcalculateAdvance();
            return 0;
            break;
        case 1:
            if (femployeeName(true) == 0) {
                showSummaryAdvance();
            }
        case 2:
            if (femployeeCode(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 3:
            if (fpresentDays(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 4:
            if (fshiftType(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 5:
            if (fdependencyType(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 6:
            if (fpresentInHoliday(true)) {
                showSummaryAdvance();
            }
            break;
        case 7:
            if (fpresentInRest(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 8:
            if (fpresentInHoliRest(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 9:
            if (overtimeHours(true) == 0) {
                showSummaryAdvance();
            }
        case 10:
            if (overtimeHoursSpecial(true) == 0) {
                showSummaryAdvance();
            }
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            showSummaryAdvance();
            break;
        }
    }
    else if (employeeCode == 'd' || employeeCode == 'D') {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl
            << "\t\tPress enter if it's final. Pick a value from 1-11: ";
        std::cin >> a;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            showSummaryAdvance();
        }
        //  Check input
        switch (a) {
        case 0:
            fcalculateAdvance();
            return 0;
            break;
        case 1:
            if (femployeeName(true) == 0) {
                showSummaryAdvance();
            }
        case 2:
            if (femployeeCode(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 3:
            if (fcCustomEmployeeRate(true) == 0) {
                showSummaryAdvance();
            }
        case 4:
            if (fpresentDays(true, true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 5:
            if (fshiftType(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 6:
            if (fdependencyType(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 7:
            if (fpresentInHoliday(true)) {
                showSummaryAdvance();
            }
            break;
        case 8:
            if (fpresentInRest(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 9:
            if (fpresentInHoliRest(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 10:
            if (overtimeHours(true) == 0) {
                showSummaryAdvance();
            }
        case 11:
            if (overtimeHoursSpecial(true) == 0) {
                showSummaryAdvance();
            }
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            showSummaryAdvance();
            break;
        }
    }
    return 0;
}

void fcalculateAdvance() {
    //Compute Gross Pay
    //system("cls");
    printHead();
    printOutValues(calcuType, name, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
    double computedGrossPay = 0.0, computedTaxDependency = 0.0, computedNetPay = 0.0;
    //Compute
    if (employeeCode != 'D' && employeeCode != 'd') {
        computedGrossPay = computeGrossPay('1', employeeCode, presentDays, shiftType, 0, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
        computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
        std::cout

            << std::fixed << std::setprecision(2)
            << "\t\t\t+-----------------------------------------+" << std::endl
            << "\t\t\t|             FINAL RESULTS           \t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+" << std::endl
            << "\t\t\t|\tGross Pay : PHP " << computedGrossPay << "    \t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+" << std::endl
            << "\t\t\t|\tTax: PHP " << computedTaxDependency << "\t\t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+" << std::endl
            << "\t\t\t|\tNet Pay: PHP " << computedNetPay << "\t\t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+\n\n" << std::endl;
    }
    else {
        computedGrossPay = computeGrossPay('1', employeeCode, presentDays, shiftType, customEmployeeRate, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
        computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
        std::cout

            << std::fixed << std::setprecision(2)
            << "\t\t\t+-----------------------------------------+" << std::endl
            << "\t\t\t|             FINAL RESULTS           \t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+" << std::endl
            << "\t\t\t|\tGross Pay : PHP " << computedGrossPay << "    \t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+" << std::endl
            << "\t\t\t|\tTax: PHP " << computedTaxDependency << "\t\t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+" << std::endl
            << "\t\t\t|\tNet Pay: PHP " << computedNetPay << "\t\t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+\n\n" << std::endl;
    }
}