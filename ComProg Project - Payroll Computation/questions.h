#pragma once
#include "checkuserinput.h"
#include "messages.h"
#include "print.h"
#include "grosspay.h"
#include "taxdep.h"
#include "netpay.h"
#include "menu.h"
#include <conio.h>
#include <iomanip>
#include <climits>
#include <cctype>
#include <string>


//Initialize Variables
std::string fname = " "; 
std::string mname = " "; 
std::string lname = " "; 
//Func
int rep = 0;

char employeeCode;
int presentDays = 0, numberOfPresentOnRestDay = 0, numberOfPresentOnHoliday = 0, numberOfPresentOnRestHoliDay = 0, numberOfOverHours = 0, numberOfSpecialOverHours = 0, numberOfAbsent = 0;
double grossPay = 0.00, netPay = 0.00, tax = 0.00, customEmployeeRate = -1;
char calcuType = '0', shiftType = '0', dependencyStatus = '0';
//Custom codes
double cc[3] = { 250.0, 320.0,450.0 };
int rng[2] = {100000, 999999};

int getRngLimits(int limit) {
    if (limit == 1) {
        return rng[0];
    }
    else if (limit == 2) {
        return rng[1];
    }
}

void setCC(int index, double ccData) {
    cc[index - 1] = ccData;
}
void setRng(int index, int rngData) {
    rng[index - 1] = rngData;
}

int randomizer(int ll, int ul) {
    //RNG
    srand((unsigned)time(NULL));
    int rng = ll + (rand()% ul);
    return rng;
}

int ev() {
    char a = ' ';
    //Clear
    system("cls");
    //Ask
    std::cout
        << "\t+--------------------------------------------+" << std::endl
        << "\t|               EDIT CONFIG                  | " << std::endl
        << "\t+--------------------------------------------+" << std::endl
        << "\t|Current default values for employee codes:  |" << std::endl
        << "\t|\t[A]" << cc[0] <<" \t\t                     | "<< std::endl
        << "\t|\t[B]" << cc[1] << "\t\t                     | "<<std::endl
        << "\t|\t[C]" << cc[2] << "\t\t                     | "<<std::endl
        << "\t+--------------------------------------------+" << std::endl
        << std::endl
        << "\t+--------------------------------------------+" << std::endl
        << "\t|Current default limits for ID Generation:   |" << std::endl
        << "\t|\t[D] " << rng[0] <<" \t                     |" << std::endl
        << "\t|\t[E] " << rng[1] << " \t                     |"<<std::endl
        << "\t+--------------------------------------------+" << std::endl
        << std::endl
        << "\t+--------------------------------------------+" << std::endl
        << "\t|\t[0] Exit Edit Config \t             |" << std::endl
        << "\t|\t[1] Save Config File\t             |" << std::endl
        << "\t|\t[2] Load Config File\t             |" << std::endl
        << "\t+--------------------------------------------+" << std::endl
        << "\n\tChoose a letter to edit: ";
    a = _getch();
    
    //Check
    if (a == 'A' || a == 'a') {
        cc0:
        //Edit cc[0]
        std::cout << std::endl << "Enter a new value: ";
        std::cin >> cc[0];
        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            clearInvalid();
            goto cc0;
        }
        //Check if negative
        if (cc[0] <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            goto cc0;
        }
        ev();
    }
    else if (a == 'B' || a == 'b') {
        cc1:
        //Edit cc[1]
        std::cout << std::endl << "Enter a new value: ";
        std::cin >> cc[1];
        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            clearInvalid();
            goto cc1;
        }
        //Check if negative
        if (cc[0] <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            goto cc1;
        }
        ev();
    }
    else if (a == 'C' || a == 'c') {
        cc2:
        //Edit cc[2]
        std::cout << std::endl << "Enter a new value: ";
        std::cin >> cc[2];
        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            clearInvalid();
            goto cc2;
        }
        //Check if negative
        if (cc[0] <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            goto cc2;
        }
        ev();
    }

    else if (a == 'D' || a == 'd') {
        rng1:
        //Edit rng[0]
        std::cout << std::endl << "Enter a new value: ";
        std::cin >> rng[0];
        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            clearInvalid();
            goto rng1;
        }
        //Check if negative
        if (cc[0] <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            goto rng1;
        }
        ev();
    }
    else if (a == 'E' || a == 'e') {
        rng2:
        //Edit rng[1]
        std::cout << std::endl << "Enter a new value: ";
        std::cin >> rng[1];
        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            clearInvalid();
            goto rng2;
        }
        //Check if negative
        if (cc[0] <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            goto rng2;
        }
        ev();
    }
    else if (a == '0') {
        return 0;
    }
    else if (a == '1') {
        saveConfig(cc, rng);
        return 0;
    }
    else if (a == '2') {
        loadConfig();
        return 0;
    }
    else {
        std::cout << generateRandomMessage(1) << std::endl << "\t";
        system("pause");
        ev();
    }
}

//  Advance Counters
int totalPresentDays = 0;

int showBasicSummary();
void fcalculateAdvance();
int showSummaryAdvance();
void cleanUp();

void cleanUp() {
    //clear
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}


int calculationType() {
    rep++;
    fname = "";
    mname = "";
    lname = "";

    employeeCode = '0';
    presentDays = 0, numberOfPresentOnRestDay = 0, numberOfPresentOnHoliday = 0, numberOfPresentOnRestHoliDay = 0, numberOfOverHours = 0, numberOfSpecialOverHours = 0, numberOfAbsent = 0;
    grossPay = 0.00, netPay = 0.00, tax = 0.00, customEmployeeRate = -1;
    calcuType = '0', shiftType = '0', dependencyStatus = '0';
    //Clear
    system("cls");
    //Start Asking for user inputs
    printHead();
    //Ask for calculation type
    std::cout << "\tPlease choose a calculation type." << std::endl;
    std::cout << "\tCalculation type: [1] Basic \n\t\t\t  [2] Advance" << std::endl;
    std::cout << "\tEnter type: ";
    calcuType = _getch();
    if (calcuType == '1') {
        return calcuType;
    }
    else if (calcuType == '2') {
        return calcuType;
    }
    else {
        std::cout << generateRandomMessage(1) << std::endl << "\t";
        system("pause");
        calculationType();
    }
    
}

int femployeeName_first(bool edit = false) {
    if (!edit) {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType);
        //Ask
        std::cout << "\tEnter Employee's First Name: ";
        if (rep >= 2) {
            cleanUp();
        }
        std::getline(std::cin, fname);
        //Perform Checks
        if (fname == "") {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            femployeeName_first();
        }
        return 0;
    }
    else if (edit) {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname);
        //Ask
        std::cout << "\tEdit Employee's First Name: ";
        std::cin.ignore(256, '\n');
        std::getline(std::cin, fname);
        //Perform Checks
        if (fname == " ") {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            femployeeName_first();
        }
        return 0;
    }
}

int femployeeName_mid(bool edit = false) {
    if (!edit) {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname);
        //Ask
        std::cout << "\tEnter Employee's Middle Name: ";
        //std::cin.ignore(256, '\n');
        std::getline(std::cin, mname);
        //Perform Checks
        if (mname == "") {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            femployeeName_mid();
        }
        return 0;
    }
    else if (edit) {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname);
        //Ask
        std::cout << "\tEdit Employee's Middle name: ";
        std::cin.ignore(256, '\n');
        std::getline(std::cin, mname);
        //Perform Checks
        if (mname == "") {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            femployeeName_mid();
        }
        return 0;
    }
}

int femployeeName_last(bool edit = false) {
    if (!edit) {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType,fname,mname);
        //Ask
        std::cout << "\tEnter Employee's Last Name: ";
        //std::cin.ignore(10000, '\n');
        std::getline(std::cin, lname);
        //Perform Checks
        if (lname == "") {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            femployeeName_last();
        }
        return 0;
    }
    else if (edit) {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType,fname, mname, lname);
        //Ask
        std::cout << "\tEdit Employee's Last Name: ";
        std::cin.ignore(256, '\n');
        std::getline(std::cin, lname);
        //Perform Checks
        if (lname == "") {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            femployeeName_last();
        }
        return 0;
    }
}

int femployeeCode(bool edit = false) {

    if (!edit) {
        //Input data for the first time/reset
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname);
        //Ask for employee code
        std::cout << "\tState employee code [A] [B] [C] [D]: ";
        employeeCode = _getch();
        //  Perform Checks
        //  Check if it's not equal with a, b, c, or d
        if (checkUserInput('1', employeeCode) == false) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
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
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode);
        //Ask for employee code
        std::cout << "\tEdit employee code [A] [B] [C] [D]: ";
        employeeCode = _getch();

        //Clear custom employee rate in change event
        if (employeeCode != 'd' && employeeCode != 'D') {
            customEmployeeRate = -1;
        }

        //  Check if it matches the required inputs
        if (checkUserInput('1', employeeCode) == false) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
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
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode);
        std::cout << "\tEnter custom rate: ";
        std::cin >> customEmployeeRate;

        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            clearInvalid();
            fcCustomEmployeeRate();
        }
        //  Check if not negative
        if (customEmployeeRate <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            fcCustomEmployeeRate();
        }

        return 0;

    }
    else if (edit) {
        //Ask input if yes
        //  Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate);
        std::cout << "\tEdit custom rate: ";
        std::cin >> customEmployeeRate;
        //  Check value
        //  Reset in invalid input
        while (std::cin.fail()) {
            clearInvalid();
            fcCustomEmployeeRate(true);
        }
        //  Check if not negative
        if (customEmployeeRate <= 0) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
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
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate);
            //Ask for number of present days
            std::cout << "\tState the number of present days: ";
            std::cin >> presentDays;
            //  Check values
            while (std::cin.fail()) {
                clearInvalid();
                fpresentDays();
            }
            if (checkUserInput('2', ' ', presentDays) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentDays();
            }
            if (checkUserInput('3', ' ', presentDays, 30, 'f')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentDays();
            }
            return 0;
        }
        
        else if (edit) {
            //If not advanced, but in edit mode
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays);
            //Ask for number of present days
            std::cout << "\tEdit the number of present days: ";
            std::cin >> presentDays;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentDays();
            }
            if (checkUserInput('2', ' ', presentDays) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentDays();
            }
            if (checkUserInput('3', ' ', presentDays, 30, 'f')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate);
            std::cout << "\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\tState the number of REGULAR present days: ";
            std::cin >> presentDays;
            //  Error checking
            while (std::cin.fail()) {
                clearInvalid();
                fpresentDays(false, true);
            }
            if (checkUserInput('2', ' ', presentDays) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentDays(false, true);
            }
            if (checkUserInput('3', ' ', presentDays, 30, 'f')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentDays(false, true);
            }
            int a = totalPresentDays;
            if (checkUserInput('3', ' ', a + presentDays, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentDays(false, true);
            }
            totalPresentDays += presentDays;
            return 0;
        }
        else if (edit) {
            totalPresentDays -= presentDays;
            //Ask for number of present days
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate);
            std::cout << "\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\tEdit the number of REGULAR present days: ";
            std::cin >> presentDays;
            //  Error checking
            while (std::cin.fail()) {
                clearInvalid();
                fpresentDays(true, true);
            }
            if (checkUserInput('2', ' ', presentDays) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentDays(true, true);
            }
            if (checkUserInput('3', ' ', presentDays, 30, 'f')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentDays(true, true);
            }
            int a = totalPresentDays;
            if (checkUserInput('3', ' ', a + presentDays, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays);
        //Ask for shift type
        std::cout << "\tState the shift type (1 - Regular, 2 - Night): ";
        shiftType = _getch();

        //Check input
        if (checkUserInput('4', ' ', shiftType, '1') == false) {
            if (checkUserInput('4', ' ', shiftType, '2') == false) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fshiftType();
            }
        }

        return 0;
    }
    else if (edit) {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType);
        //Ask for shift type
        std::cout << "\tEdit the shift type (1 - Regular, 2 - Night): ";
        shiftType = _getch();

        //Check input
        if (checkUserInput('4', ' ', shiftType, '1') == false) {
            if (checkUserInput('4', ' ', shiftType, '2') == false) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType);
        //Ask for dependency
        std::cout << "\tState the dependency type (1 - With, 2 - Without): ";
        dependencyStatus = _getch();

        //Check input
        if (checkUserInput('4', ' ', dependencyStatus, '1') == false) {
            if (checkUserInput('4', ' ', dependencyStatus, '2') == false) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fdependencyType();
            }
        }

        return 0;
    }
    else if (edit) {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask for dependency
        std::cout << "\tEdit the dependency type (1 - With, 2 - Without): ";
        dependencyStatus = _getch();

        //Check input
        if (checkUserInput('4', ' ', dependencyStatus, '1') == false) {
            if (checkUserInput('4', ' ', dependencyStatus, '2') == false) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
    system("cls");
    printHead();
    printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
    double computedGrossPay = 0.0, computedTaxDependency = 0.0, computedNetPay = 0.0;
    //Compute
    if (employeeCode != 'D' && employeeCode != 'd') {
        
        computedGrossPay = computeGrossPay(cc,'1', employeeCode, presentDays, shiftType);
        computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
        computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
        grossPay = computedGrossPay;
        tax = computedTaxDependency;
        netPay = computedNetPay;
        printFinal(1, computedGrossPay, computedTaxDependency, computedNetPay);

    }
    else {
        computedGrossPay = computeGrossPay(cc,'1', employeeCode, presentDays, shiftType, customEmployeeRate);
        computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
        computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
        grossPay = computedGrossPay;
        tax = computedTaxDependency;
        netPay = computedNetPay;
        printFinal(1, computedGrossPay, computedTaxDependency, computedNetPay);
    }
    
}

// Preview Results
int showBasicSummary() {
    int a = 0;
    double cer = 0.0;
    if (employeeCode == 'a' || employeeCode == 'A') {
        cer = cc[0];
    }
    else if (employeeCode == 'b' || employeeCode == 'B') {
        cer = cc[1];
    }
    else if (employeeCode == 'c' || employeeCode == 'C') {
        cer = cc[2];
    }
    else if (employeeCode == 'd' || employeeCode == 'D') {
        cer = customEmployeeRate;
    }

    if (employeeCode != 'd' && employeeCode != 'D') {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask if this is final
        std::cout
            << "\tHere are your inputs. If you want to change "<< std::endl
            << "\tvalues, please state the number you wish to go back to." << std::endl << std::endl
            << "\tEnter 0 if it's final. Pick a value from 1-7: ";

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
            createEmployeeFile(calcuType, fname, mname, lname, cer, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours, grossPay, tax, netPay, false);
            return 0;
            break;
        case 1:
            if (femployeeName_first(true) == 0) {
                showBasicSummary();
            }
            break;
        case 2:
            if (femployeeName_mid(true) == 0) {
                showBasicSummary();
            }
            break;
        case 3:
            if (femployeeName_last(true) == 0) {
                showBasicSummary();
            }
            break;
        case 4:
            if (femployeeCode(true) == 0) {
                showBasicSummary();
            }
            break;
        case 5:
            if (fpresentDays(true) == 0) {
                showBasicSummary();
            }
            break;
        case 6:
            if (fshiftType(true) == 0) {
                showBasicSummary();
            }
            break;
        case 7:
            if (fdependencyType(true) == 0) {
                showBasicSummary();
            }
            break;
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            showBasicSummary();
            break;
        }
    }
    else if (employeeCode == 'd' || employeeCode == 'D') {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask if this is final
        std::cout
            << "\tHere are your inputs. If you want to change " << std::endl
            << "\tvalues, please state the number you wish to go back to." << std::endl << std::endl
            << "\t\tEnter 0 if it's final. If not, pick a value from 1-8: ";

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
            createEmployeeFile(calcuType, fname, mname, lname, cer, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours, grossPay, tax, netPay, false);
            return 0;
            break;
        case 1:
            if (femployeeName_first(true) == 0) {
                showBasicSummary();
            }
            break;
        case 2:
            if (femployeeName_mid(true) == 0) {
                showBasicSummary();
            }
            break;
        case 3:
            if (femployeeName_last(true) == 0) {
                showBasicSummary();
            }
            break;
        case 4:
            if (femployeeCode(true) == 0) {
                showBasicSummary();
            }
            break;
        case 5:
            if (fcCustomEmployeeRate(true) == 0) {
                showBasicSummary();
            }
            break;
        case 6:
            if (fpresentDays(true) == 0) {
                showBasicSummary();
            }
            break;
        case 7:
            if (fshiftType(true) == 0) {
                showBasicSummary();
            }
            break;
        case 8:
            if (fdependencyType(true) == 0) {
                showBasicSummary();
            }
            break;
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t";
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
            std::cout << "\tTotal of Present Days is 30.\n\tProceeding without adding more days...\n\tSkipping other day-related inputs..." << std::endl << "\t";
            system("pause");
            return 0;
        }
        else {
            //Ask for present in holidays
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
            std::cout << "\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\tState the number of days present in holidays: ";
            std::cin >> numberOfPresentOnHoliday;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInHoliday();
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnHoliday) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentInHoliday();
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnHoliday, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
            std::cout << "\tTotal of Present Days is 30.\n\tChange other value before\n\tyou can edit this one..." << std::endl << "\t";            system("pause");
            return 0;
        }
        else {
            //Ask for present in holidays
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
            std::cout << "\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\tEdit the number of days present in holidays: ";
            std::cin >> numberOfPresentOnHoliday;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInHoliday(true);
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnHoliday) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentInHoliday(true);
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnHoliday, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
            std::cout << "\tTotal of Present Days is 30.\n\tProceeding without adding more days...\n\tSkipping other day-related inputs..." << std::endl << "\t";
            system("pause");
            return 0;
        }
        else {
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday);
            //Ask for present in rest days
            std::cout << "\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\tState the number of days present in rest day: ";
            std::cin >> numberOfPresentOnRestDay;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInRest();
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnRestDay) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentInRest();
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestDay, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
            std::cout << "\tTotal of Present Days is 30.\n\tChange other value before\n\tyou can edit this one..." << std::endl << "\t";            system("pause");
            return 0;
        }
        else {
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday);
            //Ask for present in rest days
            std::cout << "\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\tEdit the number of days present in rest day: ";
            std::cin >> numberOfPresentOnRestDay;
            //  Check std::cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInRest(true);
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnRestDay) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentInRest(true);
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestDay, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
            std::cout << "\tTotal of Present Days is 30.\n\tProceeding without adding more days...\n\tSkipping other day-related inputs..." << std::endl << "\t";
            system("pause");
            return 0;
        }
        else {
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay);
            //Ask for present in holi-rest days
            std::cout << "\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\tState the number of days present in holiday at the same time rest day: ";
            std::cin >> numberOfPresentOnRestHoliDay;
            //  Check cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInHoliRest();
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnRestHoliDay) == true) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentInHoliRest();
            }
            //int b = totalPresentDays + numberOfPresentOnRestHoliDay;
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestHoliDay, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentInHoliRest();
            }
            // Check if will go over 30 once added to totalPresentDays
            //int a = ;
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestHoliDay, 31, 'c')) {
                std::cout << generateRandomMessage(1) << std::endl << "\t";
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
            std::cout << "\tTotal of Present Days is 30.\n\tChange other value before\n\tyou can edit this one..." << std::endl << "\t";
            system("pause");
            return 0;
        }
        else {
            system("cls");
            printHead();
            printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay);
            //Ask for present in holi-rest days
            std::cout << "\tTotal number of present days: " << totalPresentDays << std::endl;
            std::cout << "\tEdit the number of days present in holiday at the same time rest day: ";
            std::cin >> numberOfPresentOnRestHoliDay;
            //  Check cin value
            while (std::cin.fail()) {
                clearInvalid();
                fpresentInHoliRest(true);
            }
            //  Check if negative
            if (checkUserInput('2', ' ', numberOfPresentOnRestHoliDay) == true) {
                //std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentInHoliRest(true);
                std::cout << "I'm the problem b";
            }
            //  Check if the total present days will not go over 30
            if (checkUserInput('3', ' ', totalPresentDays + numberOfPresentOnRestHoliDay, 31, 'c')) {
                //std::cout << generateRandomMessage(1) << std::endl << "\t";
                system("pause");
                fpresentInHoliRest(true);
                std::cout << "I'm the problem c";
            }
            // Check if will go over 30 once added to totalPresentDays
            int a = totalPresentDays;
            if (checkUserInput('3', ' ', a + presentDays, 31, 'c')) {
                //std::cout << generateRandomMessage(1) << std::endl << "\t";
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
    system("cls");
    printHead();
    printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay);
    if (!edit) {
        //Ask for Regular OT hours
        std::cout << "\tState the number of regular day overtime hours: ";
        std::cin >> numberOfOverHours;
        while (std::cin.fail()) {
            clearInvalid();
            overtimeHours();
        }
        //  Check if negative
        if (checkUserInput('2', ' ', numberOfOverHours) == true) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            overtimeHours();
        }
    }
    else if (edit) {
        //Ask for Regular OT hours
        std::cout << "\tEdit the number of regular day overtime hours: ";
        std::cin >> numberOfOverHours;
        while (std::cin.fail()) {
            clearInvalid();
            overtimeHours(true);
        }
        //  Check if negative
        if (checkUserInput('2', ' ', numberOfOverHours) == true) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            overtimeHours(true);
        }
    }
    return 0;
}

int overtimeHoursSpecial(bool edit = false) {
    if (numberOfPresentOnHoliday == 0 && numberOfPresentOnRestDay == 0 && numberOfPresentOnRestHoliDay == 0) {
        std::cout << "\tEmployee isn't present in any special day. Skipping special overtime...";
        return 0;
    }
    system("cls");
    printHead();
    printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours);
    if (!edit) {
        //Ask for present in holi-rest days
        std::cout << "\tState the number of special day overtime hours (this includes: Rest Day and Holidays): ";
        std::cin >> numberOfSpecialOverHours;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            overtimeHoursSpecial();
        }
        //  Check if negative
        if (checkUserInput('2', ' ', numberOfSpecialOverHours) == true) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            std::cout << "Im the problem";
            system("pause");
            overtimeHoursSpecial(true);
        }
    }
    else if (edit) {
        std::cout << "\tEdit the number of special day overtime hours (this includes: Rest Day and Holidays): ";
        std::cin >> numberOfSpecialOverHours;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            overtimeHoursSpecial(true);
        }
        //  Check if negative
        if (checkUserInput('2', ' ', numberOfSpecialOverHours) == true) {
            std::cout << generateRandomMessage(1) << std::endl << "\t";
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
    double cer = 0.0;
    if (employeeCode == 'a' || employeeCode == 'A') {
        cer = cc[0];
    } 
    else if (employeeCode == 'b' || employeeCode == 'B') {
        cer = cc[1];
    }
    else if (employeeCode == 'c' || employeeCode == 'C') {
        cer = cc[2];
    }
    else if(employeeCode == 'd' || employeeCode == 'D') {
        cer = customEmployeeRate;
    }

    if (employeeCode != 'd' && employeeCode != 'D') {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl
            << "\t\tEnter 0 if it's final. Pick a value from 1-12: ";
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
            createEmployeeFile(calcuType, fname, mname, lname, cer, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours, grossPay, tax, netPay, false);
            system("pause");
            return 0;
            break;
        case 1:
            if (femployeeName_first(true) == 0) {
                showSummaryAdvance();
            }
        case 2:
            if (femployeeName_mid(true) == 0) {
                showSummaryAdvance();
            }
        case 3:
            if (femployeeName_last(true) == 0) {
                showSummaryAdvance();
            }
        case 4:
            if (femployeeCode(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 5:
            if (fpresentDays(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 6:
            if (fshiftType(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 7:
            if (fdependencyType(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 8:
            if (fpresentInHoliday(true)) {
                showSummaryAdvance();
            }
            break;
        case 9:
            if (fpresentInRest(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 10:
            if (fpresentInHoliRest(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 11:
            if (overtimeHours(true) == 0) {
                showSummaryAdvance();
            }
        case 12:
            if (overtimeHoursSpecial(true) == 0) {
                showSummaryAdvance();
            }
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            showSummaryAdvance();
            break;
        }
    }
    else if (employeeCode == 'd' || employeeCode == 'D') {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        //Ask if this is final
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl
            << "\t\tEnter 0 if it's final. Pick a value from 1-13: ";
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
            createEmployeeFile(calcuType, fname, mname, lname, cer, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours, grossPay, tax, netPay, false);
            return 0;
            break;
        case 1:
            if (femployeeName_first(true) == 0) {
                showSummaryAdvance();
            }
        case 2:
            if (femployeeName_mid(true) == 0) {
                showSummaryAdvance();
            }
        case 3:
            if (femployeeName_last(true) == 0) {
                showSummaryAdvance();
            }
        case 4:
            if (femployeeCode(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 5:
            if (fcCustomEmployeeRate(true) == 0) {
                showSummaryAdvance();
            }
        case 6:
            if (fpresentDays(true, true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 7:
            if (fshiftType(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 8:
            if (fdependencyType(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 9:
            if (fpresentInHoliday(true)) {
                showSummaryAdvance();
            }
            break;
        case 10:
            if (fpresentInRest(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 11:
            if (fpresentInHoliRest(true) == 0) {
                showSummaryAdvance();
            }
            break;
        case 12:
            if (overtimeHours(true) == 0) {
                showSummaryAdvance();
            }
        case 13:
            if (overtimeHoursSpecial(true) == 0) {
                showSummaryAdvance();
            }
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            showSummaryAdvance();
            break;
        }
    }
    return 0;
}

void fcalculateAdvance() {
    //Compute Gross Pay
    system("cls");
    printHead();
    printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
    double computedGrossPay = 0.0, computedTaxDependency = 0.0, computedNetPay = 0.0;
    //Compute
    if (employeeCode != 'D' && employeeCode != 'd') {
        computedGrossPay = computeGrossPay(cc,'2', employeeCode, presentDays, shiftType, 0, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
        computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
        grossPay = computedGrossPay;
        tax = computedTaxDependency;
        netPay = computedNetPay;
        std::cout

            << std::fixed << std::setprecision(2)
            << "\t+-----------------------------------------+" << std::endl
            << "\t|             FINAL RESULTS           \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t|\tGross Pay : PHP " << computedGrossPay << "    \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t|\tTax: PHP " << computedTaxDependency << " \t\t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t|\tNet Pay: PHP " << computedNetPay << "\t \t  |" << std::endl
            << "\t\+-----------------------------------------+\n\n" << std::endl;
    }
    else {
        computedGrossPay = computeGrossPay(cc,'2', employeeCode, presentDays, shiftType, customEmployeeRate, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
        computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
        grossPay = computedGrossPay;
        tax = computedTaxDependency;
        netPay = computedNetPay;
        std::cout

            << std::fixed << std::setprecision(2)
            << "\t+-----------------------------------------+" << std::endl
            << "\t|             FINAL RESULTS           \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t|\tGross Pay : PHP " << computedGrossPay << "    \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t|\tTax: PHP " << computedTaxDependency << "\t  \t  |" << std::endl
            << "\t\+-----------------------------------------+" << std::endl
            << "\t|\tNet Pay: PHP " << computedNetPay << "\t \t  |" << std::endl
            << "\t\+-----------------------------------------+\n\n" << std::endl;
    }
}


int loadEditEmployeeData(std::string id, char ct, std::string fn, std::string mn, std::string ln, double cer, int pd, char st, char ds, int nph = 0, int npr = 0, int nphr = 0, int ot = 0, int ots = 0, double gp = 0.0, double td = 0.0, double np = 0.0) {
    //Load the data
    calcuType = ct;
    fname = fn;
    mname = mn;
    lname = ln;
    customEmployeeRate = cer;
    presentDays = pd;
    shiftType = st;
    dependencyStatus = ds;
    numberOfPresentOnHoliday = nph;
    numberOfPresentOnRestDay = npr;
    numberOfPresentOnRestHoliDay = nphr;
    numberOfOverHours = ot;
    numberOfSpecialOverHours = ots;

    employeeCode = 'D';

    leedS:
    if (ct == '1') {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        printFinal(2 ,gp, td, np);
        //Ask if this is final
        std::cout
            << "\tHere are your inputs. If you want to change " << std::endl
            << "\tvalues, please state the number you wish to go back to." << std::endl << std::endl
            << "\t\tEnter 0 if it's final. If not, pick a value from 1-8: ";
        int a = 0;
        std::cin >> a;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            goto leedS;
        }
        //  Check input
        switch (a) {
        case 0:
            fcalculateBasic();
            createEmployeeFile(calcuType, fname, mname, lname, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours, grossPay, tax, netPay, true, id);
            return 0;
            break;
        case 1:
            if (femployeeName_first(true) == 0) {
                goto leedS;
            }
            break;
        case 2:
            if (femployeeName_mid(true) == 0) {
                goto leedS;
            }
            break;
        case 3:
            if (femployeeName_last(true) == 0) {
                goto leedS;
            }
            break;
        case 4:
            if (femployeeCode(true) == 0) {
                goto leedS;
            }
            break;
        case 5:
            if (fcCustomEmployeeRate(true) == 0) {
                goto leedS;
            }
            break;
        case 6:
            if (fpresentDays(true) == 0) {
                goto leedS;
            }
            break;
        case 7:
            if (fshiftType(true) == 0) {
                goto leedS;
            }
            break;
        case 8:
            if (fdependencyType(true) == 0) {
                goto leedS;
            }
            break;
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            goto leedS;
            break;
        }
    }
    else if (ct == '2') {
        //Clear
        system("cls");
        printHead();
        printOutValues(calcuType, fname, mname, lname, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        printFinal(2 ,gp, td, np);
        //Ask if this is final
        int a = 0;
        std::cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << std::endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << std::endl
            << "\t\tEnter 0 if it's final. Pick a value from 1-13: ";
        std::cin >> a;
        //  Check std::cin value
        while (std::cin.fail()) {
            clearInvalid();
            goto leedS;
        }
        //  Check input
        switch (a) {
        case 0:
            fcalculateAdvance();
            createEmployeeFile(calcuType, fname, mname, lname, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours, grossPay, tax, netPay, true, id);
            return 0;
            break;
        case 1:
            if (femployeeName_first(true) == 0) {
                goto leedS;
            }
            break;
        case 2:
            if (femployeeName_mid(true) == 0) {
                goto leedS;
            }
            break;
        case 3:
            if (femployeeName_last(true) == 0) {
                goto leedS;
            }
            break;
        case 4:
            if (femployeeCode(true) == 0) {
                goto leedS;
            }
            break;
        case 5:
            if (fcCustomEmployeeRate(true) == 0) {
                goto leedS;
            }
        case 6:
            if (fpresentDays(true, true) == 0) {
                goto leedS;
            }
            break;
        case 7:
            if (fshiftType(true) == 0) {
                goto leedS;
            }
            break;
        case 8:
            if (fdependencyType(true) == 0) {
                goto leedS;
            }
            break;
        case 9:
            if (fpresentInHoliday(true)) {
                goto leedS;
            }
            break;
        case 10:
            if (fpresentInRest(true) == 0) {
                goto leedS;
            }
            break;
        case 11:
            if (fpresentInHoliRest(true) == 0) {
                goto leedS;
            }
            break;
        case 12:
            if (overtimeHours(true) == 0) {
                goto leedS;
            }
        case 13:
            if (overtimeHoursSpecial(true) == 0) {
                goto leedS;
            }
        default:
            std::cout << generateRandomMessage(1) << std::endl << "\t";
            system("pause");
            goto leedS;
            break;
        }
    }
}