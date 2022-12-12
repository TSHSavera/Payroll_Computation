#include <iostream>
#include <iomanip>
using namespace std;

//Global Variables
string evaluationError = "";

//Check Input Function
//  Modes:
//  1 - Test to <= -1, true
//  2 - Test to <= 0, true
//  3 - Test to 1 if yes, 2 if no.
//  4 - Test to 
bool checkInput(int var, int type) {
    
    switch (type) {
        case 1:
        if (var <= -1) {
            return true;
        } else {
            return false;
        }
        break;

        case 2:
        if (var <= 0) {
            return true; // 1
        } else {
            return false; // 0
        }
        break;

        case 3:
        if (var == 1) {
            return true;
        } else if (var == 2) {
            return false;
        } else {
            evaluationError = "invalid_input";
            return false;
        }
        break;

        default:
        evaluationError = "invalid_parameter";
        break;
    }
}

string successMessages(int number) {
    switch (number) {
        case 1:
        return "Success 1";
        break;
        
        case 2:
        return "Success 2";
        break;

        case 3:
        return "Success 3";
        break;

        case 4:
        return "Success 4";
        break;

        case 5:
        return "Success 5";
        break;
    }
}
string wrongMessages(int number) {
    switch (number) {
        case 1:
        return "Fail 1";
        break;
        
        case 2:
        return "Fail 2";
        break;

        case 3:
        return "Fail 3";
        break;

        case 4:
        return "Fail 4";
        break;

        case 5:
        return "Fail 5";
        break;
    }
}

//Randomize Messages
string generateRandomMessage(int type) {
    //Initialize Variables
    string messageString;
    
    //RNG
    srand(time(NULL));
    int rng = 1 + rand() % 10;
    //Process data received
    //  Types are: 1 - Wrong Input, 2 - Success
    switch (type) {
        case 1:
        messageString = wrongMessages(rng);
        break;

        case 2:
        messageString = successMessages(rng);
        break;
    }

    //Return
    return messageString;
}

//Main Function
int main() {
    start:
    //Initialize Variables
    int employeeCode = 0;
    int calcuType, numberOfHours, presentDays, shiftType, civilStatus, numberOfPresentOnRestDay, numberOfPresentOnHoliday, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfAbsent;
    
    double grossPay, netPay;

    //Get user input
    //  Base
    cout << "<Payroll Calculator> Welcome! To get started please enter the employee code: ";
    cin >> employeeCode;
    cout 
    << "<Payroll Calculator> That was clear! Now, I wanna ask you if you want to access advance calculations." 
    << endl << "\nBasic Calculation includes: Number of absent, type of shift, and civil status. The system will always consider the REGULAR values on calculating the payroll (8 hours a day, 5 days a week.)"
    << endl << "Advance Calculation includes: Custom working hours, type of Shift, civil status, rest day and holiday calculations, and overtime."
    << endl << "\nType 1 if Yes, 2 if No (1 or 2): ";
    cin >> calcuType;
    if (checkInput(calcuType, 3) == 1) {
        //Access Advance Calculations
        goto AdvanceCalculations;
    } else if (checkInput(calcuType, 3) == 0 && evaluationError == "") {
        goto BasicCalculations;
    } else {
        goto start;
        evaluationError = "invalid_input";
    }

    //  Basic
    BasicCalculations:
    cNumberOfAbsentBasic:
    cout << "<Payroll Calculator> Since you've opted to basic calculator, please enter the number of absent days: ";
    cin >> numberOfAbsent;
    
    //  Check input
    if (checkInput(numberOfAbsent, 2) == 0) {
        cout << "Still working";
        cout << generateRandomMessage(1);
        goto cNumberOfAbsentBasic;
    } else {
        cout << generateRandomMessage(2);
        goto cShiftTypeBasic;
    }

    cShiftTypeBasic:
    cout << "<Payroll Calculator> " << generateRandomMessage(2) << "Now, please enter the type of shift. Enter 1 if REGULAR and 2 if NIGHT (1 or 2): ";
    cin >> shiftType;
    //  Check input
    if (checkInput(shiftType, 3) == false && evaluationError == "invalid_input") {
        cout << generateRandomMessage(1);
        goto cShiftTypeBasic;
    }




    AdvanceCalculations:

    //  Advance
    cout << "<Payroll Calculator> "<< generateRandomMessage(2) << " Now, please enter the TOTAL number of his REGULAR working hours: ";
    cin >> numberOfHours;

    //Static Values
    double 
    code1 = 250.0,
    code2 = 320.0, 
    code3 = 450.0, 
    withDep = 0.10, 
    withoutDep = 0.20, 
    holidayMultiplier = 0.200, 
    restDayMultiplier = 0.130, 
    restHoliDayMultiplier = 0.260, 
    restDayNightMultiplier = 0.143, 
    nightShiftMultiplier = 0.110, 
    holidayNightMultiplier = 0.220, 
    overtimeMultiplier = 0.125, 
    overtimeRestDayMultiplier = 0.169;

    //Identify user input
    switch (employeeCode) {
        case 1:
        goto employeeCode1;
        break;
        case 2:
        goto employeeCode2;
        break;
        case 3:
        goto employeeCode3;
        break;
        default:
        goto error;
        break;
    }


    employeeCode1:
    cout << "test";
    employeeCode2:
    cout << "test";
    employeeCode3:
    cout << "test";
    error:
    cout << "test";
}