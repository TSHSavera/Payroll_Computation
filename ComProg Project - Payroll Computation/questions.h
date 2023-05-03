#pragma once
#include "checkuserinput.h"
#include "messages.h"
#include "print.h"
#include "grosspay.h"
#include "taxdep.h"
#include "netpay.h"
#include <conio.h>


//Initialize Variables
char employeeCode;
int presentDays = 0, numberOfPresentOnRestDay = 0, numberOfPresentOnHoliday = 0, numberOfPresentOnRestHoliDay = 0, numberOfOverHours = 0, numberOfSpecialOverHours = 0, numberOfAbsent = 0;
double grossPay = 0.00, netPay = 0.00, tax = 0.00, customEmployeeRate = -1;
char calcuType = '0', shiftType = '0', dependencyStatus = '0';

//  Advance Counters
int totalPresentDays = 0;

bool showBasicSummary();
bool fcalculateAdvance();
bool showSummaryAdvance();


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

void fcCustomEmployeeRate(bool edit = false, bool adv = false) {
    if (!edit) {
        //Ask input if yes
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode);
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
    }
    else if (edit) {
        //Ask input if yes
        //  Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode, customEmployeeRate);
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
        //Return to preview after editing
        if (!adv) {
            showBasicSummary();
        }
        else if (adv) {
            showSummaryAdvance();
        }
    }
}

void femployeeCode(bool edit = false, bool adv = false) {
    
    if (!edit) {
        //Input data for the first time/reset
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, ' ');
        //Ask for employee code
        std::cout << "\t\t\tState employee code [A] [B] [C] [D]: ";
        employeeCode = _getch();
        //  Perform Checks
        if (checkUserInput('1', employeeCode) == false) {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            femployeeCode();
        }
        else {
            //Check if D
            if (employeeCode == 'D' || employeeCode == 'd') {
                //Call custom employee
                fcCustomEmployeeRate();
            }
        }
    }
    else if (edit){
        //Input data in edit mode
        //system("cls");
        printHead();
        printOutValues('1', employeeCode);
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
        else {
            //  Check if the input is D. If yes, proceed to customEmployeeRate again.
            if (employeeCode == 'd' || employeeCode == 'D') {
                //Call customEmployeeRate again if changed to D
                if (!adv) {
                    fcCustomEmployeeRate(true);
                }
                else if (adv) {
                    fcCustomEmployeeRate(true, true);
                }
            }
            //If not D, return to preview
            if (employeeCode != 'd' && employeeCode != 'D') {
                if (!adv) {
                    showBasicSummary();
                }
                else if (adv) {
                    showSummaryAdvance();
                }
            }
        }
        
    }
}




void fpresentDays(bool edit = false, bool adv = false) {
    // Check if advanced mode
    if (!adv) {
        // If not advanced, check if in edit mode
        if (!edit) {
            //If not edit
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate);
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
        }
        
        else if (edit) {
            //If not advanced, but in edit mode
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays);
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

            totalPresentDays += presentDays;
            //Return to preview after editing
            showBasicSummary();
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
            printOutValues(calcuType, employeeCode, customEmployeeRate);
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
        }
        else if (edit) {
            totalPresentDays -= presentDays;
            //Ask for number of present days
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate);
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
            showSummaryAdvance();
        }
    }
}

void fshiftType(bool edit = false, bool adv = false) {
    if (!edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays);
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
    }
    else if (edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType);
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
        if (!adv) {
            showBasicSummary();
        }
        else if (adv) {
            showSummaryAdvance();
        }
    }

}

void fdependencyType(bool edit = false, bool adv = false) {
    if (!edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType);
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
    }
    else if (edit) {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
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
        if (!adv) {
            showBasicSummary();
        }
        else if (adv) {
            showSummaryAdvance();
        }
    }
}

// Question - Result
void fcalculateBasic() {
    //  Clear before processing then display the data values
    //system("cls");
    printHead();
    printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
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
bool showBasicSummary() {
    int a = 0;
    if (employeeCode != 'd' && employeeCode != 'D') {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl << std::endl
            << "\t\tEnter 0 if it's final. Pick a value from 2-5: ";

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
            break;
        case 2:
            femployeeCode(true);
            break;
        case 3:
            fpresentDays(true);
            break;
        case 4:
            fshiftType(true);
            break;
        case 5:
            fdependencyType(true);
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
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl << std::endl
            << "\t\tPress enter if it's final. If not, pick a value from 2-6: ";

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
            break;
        case 2:
            femployeeCode(true);
            break;
        case 3:
            fcCustomEmployeeRate(true);
            break;
        case 4:
            fpresentDays(true);
            break;
        case 5:
            fshiftType(true);
            break;
        case 6:
            fdependencyType(true);
            break;
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            showBasicSummary();
            break;
        }
    }
    return true;
}

void overtimeHoursSpecial(bool edit = false) {
    if (numberOfPresentOnHoliday == 0 && numberOfPresentOnRestDay == 0 && numberOfPresentOnRestHoliDay == 0) {
        std::cout << "\t\t\tEmployee isn't present in any special day. Skipping special overtime...";
    }
    //system("cls");
    printHead();
    printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours);
    //Ask for present in holi-rest days
    if (!edit) {
        std::cout << "\t\t\tState the number of special day overtime hours (this includes: Rest Day and Holidays): ";
    }
    else if (edit) {
        std::cout << "\t\t\tEdit the number of special day overtime hours (this includes: Rest Day and Holidays): ";
    }
    std::cin >> numberOfSpecialOverHours;
    //  Check std::cin value
    while (std::cin.fail()) {
        clearInvalid();
        if (!edit) {
            overtimeHoursSpecial();
        }
        else if (edit) {
            overtimeHoursSpecial(true);
        }
    }

    //  Check if negative
    if (checkUserInput('2', ' ', numberOfSpecialOverHours) == true) {
        std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
        std::cout << "Im the problem";
        system("pause");
        if (!edit) {
            overtimeHoursSpecial();
        }
        else if (edit) {
            overtimeHoursSpecial(true);
        }
    }

    // Return to corresponding functions if edit
    if (edit) {
        showSummaryAdvance();
    }
}

void overtimeHours(bool edit = false) {
    //system("cls");
    printHead();
    printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay);
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
        //Call preceeding function
        overtimeHoursSpecial();
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
        // Go back to summary
        showSummaryAdvance();
    }
}

void fpresentInHoliRest(bool edit = false) {
    if (!edit) {
        //  Check if the total present days is 30
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tProceeding without adding more days...\n\t\t\tSkipping other day-related inputs..." << std::endl << "\t\t\t";
            system("pause");
            overtimeHours();
        }
        else {
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay);
            //Ask for present in holi-rest days
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
            //  Call preceeding function
            overtimeHours();
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
            showSummaryAdvance();
        }
        else {
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay);
            //Ask for present in holi-rest days
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
            //  Call preceeding function
            showSummaryAdvance();
        }
    }
}

void fpresentInRest(bool edit = false) {
    //  Check if the total present days is 30
    if (!edit) {
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tProceeding without adding more days...\n\t\t\tSkipping other day-related inputs..." << std::endl << "\t\t\t";
            system("pause");
            overtimeHours();
        }
        else {
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday);
            //Ask for present in rest days
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
            //  Call preceeding function
            fpresentInHoliRest();
        }
    }
    else if (edit) {
        //Reset value from rollbacks
        totalPresentDays -= numberOfPresentOnRestDay;
        numberOfPresentOnRestDay = 0;
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tChange other value before\n\t\t\tyou can edit this one..." << std::endl << "\t\t\t";            system("pause");
            showSummaryAdvance();
        }
        else {
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday);
            //Ask for present in rest days
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
        //  Call preceeding function
        showSummaryAdvance();

    }

}

void fpresentInHoliday(bool edit = false) {
    if (!edit) {
        //  Check if the total present days is 30
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tProceeding without adding more days...\n\t\t\tSkipping other day-related inputs..." << std::endl << "\t\t\t";
            system("pause");
            overtimeHours();
        }
        else {
            //Ask for present in holidays
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
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
            //  Call preceeding function
            fpresentInRest();
        }
    }
    else if (edit) {
        //Reset value from rollbacks
        totalPresentDays -= numberOfPresentOnHoliday;
        numberOfPresentOnHoliday = 0;
        if (checkUserInput('3', ' ', totalPresentDays, 30, 'c')) {
            std::cout << "\t\t\tTotal of Present Days is 30.\n\t\t\tChange other value before\n\t\t\tyou can edit this one..." << std::endl << "\t\t\t";            system("pause");
            showSummaryAdvance();
            //Ask for present in holidays
            //system("cls");
            printHead();
            printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
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
            //  Call preceeding function
            showSummaryAdvance();
        }
    }

}

bool showSummaryAdvance() {
    int a = 0;
    if (employeeCode != 'd' && employeeCode != 'D') {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl
            << "\t\tPress enter if it's final. Pick a value from 2-10: ";
        std::cin >> a;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            showSummaryAdvance();
        }
        //  Check input
        switch (a) {
        case ' ':
            fcalculateAdvance();
            break;
        case 2:
            femployeeCode(true, true);
            break;
        case 3:
            fpresentDays(true, true);
            break;
        case 4:
            fshiftType(true, true);
            break;
        case 5:
            fdependencyType(true, true);
            break;
        case 6:
            fpresentInHoliday(true);
            break;
        case 7:
            fpresentInRest(true);
            break;
        case 8:
            fpresentInHoliRest(true);
            break;
        case 9:
            overtimeHours(true);
        case 10:
            overtimeHoursSpecial(true);
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            showSummaryAdvance();
            break;
        }
        return true;
    }
    else if (employeeCode == 'd' || employeeCode == 'D') {
        //Clear
        //system("cls");
        printHead();
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl
            << "\t\tPress enter if it's final. Pick a value from 2-11: ";
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
            break;
        case 2:
            femployeeCode(true, true);
            break;
        case 3:
            fcCustomEmployeeRate(true, true);
            break;
        case 4:
            fpresentDays(true, true);
            break;
        case 5:
            fshiftType(true, true);
            break;
        case 6:
            fdependencyType(true, true);
            break;
        case 7:
            fpresentInHoliday(true);
            break;
        case 8:
            fpresentInRest(true);
            break;
        case 9:
            fpresentInHoliRest(true);
            break;
        case 10:
            overtimeHours(true);
        case 11:
            overtimeHoursSpecial(true);
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            showSummaryAdvance();
            break;
        }
        return true;
    }
}

bool fcalculateAdvance() {
    //Compute Gross Pay
    //system("cls");
    printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
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
            << "\t\t\t|\tTax: PHP " << computedTaxDependency << "\t\t   |" << std::endl
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
            << "\t\t\t|\tTax: PHP " << computedTaxDependency << "\t\t\t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+" << std::endl
            << "\t\t\t|\tNet Pay: PHP " << computedNetPay << "\t\t  |" << std::endl
            << "\t\t\t\+-----------------------------------------+\n\n" << std::endl;
    }
    return true;
}