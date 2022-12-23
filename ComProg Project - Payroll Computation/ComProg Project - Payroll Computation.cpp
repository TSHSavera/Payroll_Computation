#include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>
#include <math.h>
using namespace std;

//Global Variables
string evaluationError = "";
//Static Values
double
    //Employee Codes
    code1 = 250.0,
    code2 = 320.0,
    code3 = 450.0,
    //Dependency
    withDep = 0.10,
    withoutDep = 0.20,
    //Special Days - Regular
    holidayMultiplier = 2.00,
    restDayMultiplier = 1.30,
    restHoliDayMultiplier = 2.60,
    //Special Days - Night
    restDayNightMultiplier = 1.43,
    nightShiftMultiplier = 1.10,
    holidayNightMultiplier = 2.20,
    restHoliDayNightMultiplier = 2.70,
    //Overtime
    overtimeMultiplier = 1.25,
    overtimeRestDayMultiplier = 1.69;


//  Random Message Generator

string successMessages(int number) {
    switch (number) {
    case 1:
        return "\t\t\tSweet! That went well. ";
        break;

    case 2:
        return "\t\t\tI've got that very clear! ";
        break;

    case 3:
        return "\t\t\tThis should be good to go. ";
        break;

    case 4:
        return "\t\t\tI see, I see. ";
        break;

    case 5:
        return "\t\t\tThat was fast and neat! Moving forward. ";
        break;

    default:
        return "\t\t\tUnknown parameter passed";
        break;
    }
    
}
string wrongMessages(int number) {
    switch (number) {
    case 1:
        return "\n\n\t\tThat doesn't seem right. Please try again...\n\n";
        break;

    case 2:
        return "\n\n\t\tIt seems you've failed to follow the conditions. Retrying...\n\n";
        break;

    case 3:
        return "\n\n\t\tThere was a mistake in your input. Going back up...\n\n";
        break;

    case 4:
        return "\n\n\t\tLet's try to avoid that mistake next time. Re-enter that data needed...\n\n";
        break;

    case 5:
        return "\n\n\t\tLet me guess, you have a typographical error. Don't worry, we'll return to the previous question...\n\n";
        break;

    default:
        return "\n\nUnknown parameter passed\n\n";
        break;
    }
}
string taskDoneMessages(int number) {
    switch (number) {
    case 1:
        return "\t\tSweet! That went well. ";
        break;

    case 2:
        return "\t\tTask done smoothly! ";
        break;

    case 3:
        return "\t\tFlawlessly done. ";
        break;

    case 4:
        return "\t\tFlawless. Clean. Neat. ";
        break;

    case 5:
        return "\t\tThat was fast and neat! Moving forward. ";
        break;

    default:
        return "\t\tUnknown parameter passed";
        break;
    }

}

//  Check user input
bool checkUserInput(int code, string ec, double valueToBeChecked = -1, double valueToCompare = -1, char rangeRule = NULL) {
    //Code 1 - Check for employeeCode
    if (code == 1) {
        if (ec == "a" || ec == "A") {
            return true;
        }
        else if (ec == "b" || ec == "B") {
            return true;
        }
        else if (ec == "c" || ec == "C") {
            return true;
        }
        else if (ec == "d" || ec == "D") {
            return true;
        }
        else {
            return false;
        }
    }
    else if (code == 2) {
        //Code 2 - Check if negative
        if (valueToBeChecked <= -1) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (code  == 3) {
        //  Range Test
        if (rangeRule == 'A' || rangeRule == 'a') {
            //==
            if (valueToBeChecked == valueToCompare) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (rangeRule == 'B' || rangeRule == 'b') {
            //<=
            if (valueToBeChecked <= valueToCompare) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (rangeRule == 'C' || rangeRule == 'c') {
            //>=
            if (valueToBeChecked >= valueToCompare) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (rangeRule == 'D' || rangeRule == 'd') {
            //!=
            if (valueToBeChecked != valueToCompare) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (rangeRule == 'E' || rangeRule == 'e') {
            //<
            if (valueToBeChecked < valueToCompare) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (rangeRule == 'F' || rangeRule == 'f') {
            //>
            if (valueToBeChecked > valueToCompare) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}


//  Randomize Messages
string generateRandomMessage(int type) {
    //Initialize Variables
    string messageString;

    //RNG
    srand((unsigned) time(NULL));
    int rng = 1 + rand() % 5;
    //Process data received
    //  Types are: 1 - Wrong Input, 2 - Success
    switch (type) {
    case 1:
        messageString = wrongMessages(rng);
        break;

    case 2:
        messageString = successMessages(rng);
        break;
    case 3:
        messageString = taskDoneMessages(rng);
        break;
    }

    //Return
    return messageString;
}

//  Gross Pay
double computeGrossPay(int calculationType, string employeeCode, int numberOfPresentDays, int shiftType, double customDailyRate = 0.0, int presentOnHoliday = 0, int presentOnRestDay = 0, int presentOnRestHoliDay = 0, int overtimeHours = 0, int overtimeHoursOnRestDay = 0) {
    //Placeholders
    double grossPay = 0.00;
    
    if (calculationType == 1) {
        //Do Basic Calculations
        //  Check Employee Code
        if (employeeCode == "a" || employeeCode == "A") {
            //  Calculate for EC-A
            //  Check Shift Type (regular or night)
            if (shiftType == 1) {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * (code1);
                return grossPay;
            }
            else if (shiftType == 2) {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (code1 * nightShiftMultiplier);
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == "b" || employeeCode == "B") {
            //Calculate for EC-B
            //  Check Shift Type (regular or night)
            if (shiftType == 1) {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * (code2);
                return grossPay;
            }
            else if (shiftType == 2) {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (code2 * nightShiftMultiplier);
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == "c" || employeeCode == "C") {
            //Calculate for EC-C
            //  Check Shift Type (regular or night)
            if (shiftType == 1) {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * (code3);
                return grossPay;
            }
            else if (shiftType == 2) {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (code3 * nightShiftMultiplier);
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == "d" || employeeCode == "D") {
            //Calculate for EC-D
            //  Check Shift Type (regular or night)
            if (shiftType == 1) {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * (customDailyRate);
                return grossPay;
            }
            else if (shiftType == 2) {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (customDailyRate * nightShiftMultiplier);
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else {
            return -2;
        }
    }
    else if (calculationType == 2) {
        //Do Advance Calculations
        //  Check Employee Code
        if (employeeCode == "a" || employeeCode == "A") {
            //  Calculate for EC-A
            //  Check Shift Type (regular or night)
            if (shiftType == 1) {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * code1;
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (code1 * holidayMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (code1 * restDayMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (code1 * restHoliDayMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * overtimeMultiplier * code2;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * overtimeRestDayMultiplier * code2;
                }
                return grossPay;
            }
            else if (shiftType == 2) {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (code1 * nightShiftMultiplier);
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (code1 * holidayNightMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (code1 * restDayNightMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (code1 * restHoliDayNightMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * overtimeMultiplier * code1;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * overtimeRestDayMultiplier * code1;
                }
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == "b" || employeeCode == "B") {
            //Calculate for EC-B
            //  Check Shift Type (regular or night)
            if (shiftType == 1) {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * code2;
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (code2 * holidayMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (code2 * restDayMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (code2 * restHoliDayMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * overtimeMultiplier * code2;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * overtimeRestDayMultiplier * code2;
                }
                return grossPay;
            }
            else if (shiftType == 2) {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (code2 * nightShiftMultiplier);
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (code2 * holidayNightMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (code2 * restDayNightMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (code2 * restHoliDayNightMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * overtimeMultiplier * code2;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * overtimeRestDayMultiplier * code2;
                }
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == "c" || employeeCode == "C") {
            //Calculate for EC-C
            //  Check Shift Type (regular or night)
            if (shiftType == 1) {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * code3;
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (code3 * holidayMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (code3 * restDayMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (code3 * restHoliDayMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * overtimeMultiplier * code3;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * overtimeRestDayMultiplier * code3;
                }
                return grossPay;
            }
            else if (shiftType == 2) {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (code3 * nightShiftMultiplier);
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (code3 * holidayNightMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (code3 * restDayNightMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (code3 * restHoliDayNightMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * overtimeMultiplier * code3;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * overtimeRestDayMultiplier * code3;
                }
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == "d" || employeeCode == "D") {
            //Calculate for EC-C
            //  Check Shift Type (regular or night)
            if (shiftType == 1) {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * customDailyRate;
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (customDailyRate * holidayMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (customDailyRate * restDayMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (customDailyRate * restHoliDayMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * overtimeMultiplier * customDailyRate;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * overtimeRestDayMultiplier * customDailyRate;
                }
                return grossPay;
            }
            else if (shiftType == 2) {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (customDailyRate * nightShiftMultiplier);
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (customDailyRate * holidayNightMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (customDailyRate * restDayNightMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (customDailyRate * restHoliDayNightMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * overtimeMultiplier * customDailyRate;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * overtimeRestDayMultiplier * customDailyRate;
                }
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else {
            return -2;
        }
    }
    else {
        return -1;
    }
}

//Tax - Dependency
double computeTaxDependency(int typeOfTax, double grossPay) {
    double taxDependency = 0.0;
    //  Know the type of tax
    if (typeOfTax == 1) {
        //  Compute With Dependency Tax
        taxDependency = grossPay * withDep;
        return taxDependency;
    }
    else if (typeOfTax == 2) {
        //  Compute Without Dependency Tax
        taxDependency = grossPay * withoutDep;
        return taxDependency;
    }
    else {
        return -1;
    }
}

//Net Pay
double computeNetPay(double grossPay, double taxDependency) {
    double netPay = 0.0;
    //  Compute Net Pay
    netPay = grossPay - taxDependency;
    return netPay;
}

void clearInvalid() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "\t\t\t[ERROR] INVALID DATA TYPE INPUT" << endl << "Cleaning up...";
    system("pause");
}

void printOutValues(int calcuType = -1, string employeeCode = NULL, double customEmployeeRate = -1, int presentDays = -1, int shiftType = -1, int dependencyStatus = -1, int numberOfPresentOnHoliday = -1, int numberOfPresentOnRestDay = -1, int numberOfPresentOnRestHoliDay = -1, int numberOfOvertimeHours = -1, int numberOfSpecialOvertimeHours = -1) {
    
    //  Print Head
    cout << "\t\t\t\+-----------------------------------------+" << endl;
    cout << "\t\t\t|          PAYROLL COMPUTATION            |" << endl;
    cout << "\t\t\t\|                                         |" << endl;
    cout << "\t\t\t\+-----------------------------------------+" << endl;
    if (calcuType != -1) {
        if (calcuType == 1) {

    cout << "\t\t\t| 1. Calculation Type: Basic \t\t\t  |" << endl;
    cout << "\t\t\t+-----------------------------------------+" << endl;
        }
        else if (calcuType == 2) {
    cout << "\t\t\t| 1. Calculation Type: Advance \t\t  |" << endl;
    cout << "\t\t\t+-----------------------------------------+" << endl;
        }
    }

    if (employeeCode != " ") {
        if (customEmployeeRate != -1) {

            cout << "\t\t\t| 2. Employee Code: " << employeeCode <<"\t\t\t  |" << endl;
            cout << "\t\t\t+-----------------------------------------+" << endl;
            cout << "\t\t\t| 2. Custom Employee Rate: " << customEmployeeRate <<"\t\t  |" << endl;
            cout << "\t\t\t+-----------------------------------------+" << endl;
        }
        else {
            cout << "\t\t\t| 2. Employee Code: " << employeeCode << "\t\t\t  |" << endl;
            cout << "\t\t\t+-----------------------------------------+" << endl;
        }
    }

    if (presentDays != -1) {
        cout << "\t\t\t| 3. Number of Present Days: " << presentDays << "\t\t  |" << endl; 
        cout << "\t\t\t+-----------------------------------------+" << endl;
    }

    if (shiftType != -1) {
        if (shiftType == 1) {
            cout << "\t\t\t| 4. Shift Type: Regular Shift" << "\t\t  |" << endl;
            cout << "\t\t\t+-----------------------------------------+" << endl;
        }
        else if (shiftType == 2) {
            cout << "\t\t\t| 4. Shift Type: Night Shift" << "\t\t  |" << endl;
            cout << "\t\t\t+-----------------------------------------+" << endl;
        }
    }

    if (dependencyStatus != -1) {
        if (dependencyStatus == 2) {
            cout << "\t\t\t\| 5. Dependency Type: Without Dependents" <<"  |" << endl;
             cout << "\t\t\t+-----------------------------------------+" << endl;
        }
        else if (dependencyStatus == 1) { 
            cout << "\t\t\t\| 5. Dependency Type: With Dependents" << "\t  |" << endl;
            cout <<"\t\t\t+-----------------------------------------+" << endl; 
        }
    }

    if (numberOfPresentOnHoliday != -1) {
        cout << "\t\t\t| 6. Number of Present on Holidays: " << numberOfPresentOnHoliday << "\t  |" << endl;
        cout << "\t\t\t+-----------------------------------------+" << endl;
    }


    if (numberOfPresentOnRestDay != -1) {
        cout << "\t\t\t| 7. Number of Present on Restday: " << numberOfPresentOnRestDay << "\t  |" << endl;
        cout << "\t\t\t+-----------------------------------------+" << endl;
    }

    if (numberOfPresentOnRestHoliDay != -1) {
        cout << "\t\t\t| 8. Number of Present on Rest/Holiday: " << numberOfPresentOnRestHoliDay << " |" << endl;
        cout << "\t\t\t+-----------------------------------------+" << endl;
    }

    if (numberOfOvertimeHours != -1) {
        cout << "\t\t\t| 9. Number of Overtime Hours: " << numberOfOvertimeHours << "\t  |" << endl;
        cout << "\t\t\t+-----------------------------------------+" << endl;
    }

    if (numberOfSpecialOvertimeHours != -1) {
        cout << "\t\t\t| 10. Number of SP Overtime Hours: " << numberOfSpecialOvertimeHours << " |" << endl;
        cout << "\t\t\t+-----------------------------------------+" << endl;
    }


    cout << endl;
}

//Main Function
int main() {
    //  Password Variables
    string pass;
    int attempts = 1;
    //string calcuTypeText;

    //  Enter Password
    cEnterPassword:
    system("cls");
    if (attempts >= 4) {
        cout << "\t\t\t\t\tYou have been blocked from using the system!" << endl;
        system("pause");
        exit(0);
    }
    cout << "\t\t\t\+-----------------------------------------+" << endl;
    cout << "\t\t\t|          PAYROLL COMPUTATION            |" << endl;
    cout << "\t\t\t\+-----------------------------------------+" << endl;
    cout << "\t\t\tYou have "<<attempts<<"/ 3 Attempts\n" << endl;
    cout << "\t\t\tENTER PASSCODE: ";
    cin >> pass;
 

    if (pass != "1234") {
        attempts++;
        goto cEnterPassword;
    }

    start:
    //Initialize Variables
    string employeeCode;
    int calcuType = 0, presentDays = 0, shiftType = 0, dependencyStatus = 0, numberOfPresentOnRestDay = 0, numberOfPresentOnHoliday = 0, numberOfPresentOnRestHoliDay = 0, numberOfOverHours = 0, numberOfSpecialOverHours = 0, numberOfAbsent = 0;
    double grossPay = 0.00, netPay = 0.00, tax = 0.00, customEmployeeRate = -1;

    //Function Variables
    int basicCalGoBackSteps = 0;

    string tA;
    
    
    firstUserInput:
    customEmployeeRate = -1;
    //Clear
    system("cls");
    //Start Asking for user inputs
    cout << "\t\t\t\+-----------------------------------------+" << endl;
    cout << "\t\t\t|          PAYROLL COMPUTATION            |" << endl;
    cout << "\t\t\t\+-----------------------------------------+" << endl;
    //Ask for calculation type
    cout << "\t\t\tPlease choose a calculation type." << endl;
    cout << "\t\t\tCalculation type: [1] Basic \n\t\t\t\t\t  [2] Advance"<<endl;
    cout << "\t\t\tEnter type: ";
    cin >> calcuType;
    //  Check cin value
    while (cin.fail()) {
        clearInvalid();
        goto firstUserInput;
    }
    
    //Check calcuType
    if (calcuType == 1) {
        //Only Asks for Basics
        
        //  Chapter - Employee Code Main
        cEmployeeCode:
        //Clear
        system("cls");
        printOutValues(1," ");
        //Ask for employee code
        cout << "\t\t\tState employee code [A] [B] [C] [D]: ";
        cin >> employeeCode;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto cEmployeeCode;
        }
        //  Perform Checks
        if (checkUserInput(1, employeeCode) == false) {
            cout << generateRandomMessage(1);
            system("pause");
            goto cEmployeeCode;
        }

        //  Chapter - Custom Employee Rate if D
        if (employeeCode == "D" || employeeCode == "d") {
            //  Ask input if yes
            //Clear
            cCustomEmployeeRate:
            system("cls");
            printOutValues(calcuType, employeeCode);
            cout << "\t\t\tEnter custom rate: ";
            cin >> customEmployeeRate;
            //  Check cin value
            while (cin.fail()) {
                clearInvalid();
                goto cCustomEmployeeRate;
            }
            //  Check if not negative
            if (customEmployeeRate <= 0) {
                cout << generateRandomMessage(1);
                system("pause");
                goto cCustomEmployeeRate;
            }
        }

        //  Chapter - Present Days
        cPresentDays:
        //Clear
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate);
        //Ask for number of present days
        cout << "\t\t\tState the number of present days: ";
        cin >> presentDays;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto cPresentDays;
        }
        if (checkUserInput(2, " ", presentDays) == true) {
            cout << generateRandomMessage(1);
            system("pause");
            goto cPresentDays;
        }
        if (checkUserInput(3, " ", presentDays, 30, 'f')) {
            cout << generateRandomMessage(1);
            system("pause");
            goto cPresentDays;
        }

        //  Chapter - Shift Type
        cShiftType:
        //Clear
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays);
        //Ask for shift type
        cout << "\t\t\tState the shift type (1 - Regular, 2 - Night): ";
        cin >> shiftType;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto cShiftType;
        }
        
        //Check input
        if (checkUserInput(3, " ", shiftType, 1, 'a') == false) {
            if (checkUserInput(3, " ", shiftType, 2, 'a') == false) {
                cout << generateRandomMessage(1);
                system("pause");
                goto cShiftType;
            }
        }
        

        //  Chapter - Dependency
        cDependency:
        //Clear
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType);
        //Ask for dependency
        cout << "\t\t\tState the dependency type (1 - With, 2 - Without): ";
        cin >> dependencyStatus;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto cDependency;
        }
        
        //Check input
        if (checkUserInput(3, " ", dependencyStatus, 1, 'a') == false) {
            if (checkUserInput(3, " ", dependencyStatus, 2, 'a') == false) {
                cout << generateRandomMessage(1);
                system("pause");
                goto cDependency;
            }
        }

        //  Chapter - Summary before processing
        cBasicSummary:
        //Clear
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask if this is final
        cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << endl << endl
            << "\t\tEnter 0 if it's final. Pick a value from 1-5: ";

        cin >> basicCalGoBackSteps;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto cBasicSummary;
        }
        //  Check input
        switch (basicCalGoBackSteps) {
        case 0:
            goto calculateBasic;
            break;
        case 1:
            goto firstUserInput;
            break;
        case 2:
            goto cEmployeeCode;
            break;
        case 3:
            goto cPresentDays;
            break;
        case 4:
            goto cShiftType;
            break;
        case 5:
            goto cDependency;
            break;
        default:
            cout << generateRandomMessage(1);
            system("pause");
            goto cBasicSummary;
            break;
        }

        //Compute Gross Pay
        calculateBasic:
        //  Clear before processing then display the data values
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        double computedGrossPay = 0.0, computedTaxDependency = 0.0, computedNetPay = 0.0;
        //Compute
        if (employeeCode != "D") {
            if (employeeCode != "d") {
                computedGrossPay = computeGrossPay(1, employeeCode, presentDays, shiftType);
                computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
                computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
                cout
                    << fixed << setprecision(2)
                    << "\t\t\t+-----------------------------------------+" << endl
                    << "\t\t\t|                                    \t  |" << endl
                    << "\t\t\t\+-----------------------------------------+" << endl
                    << "\t\t\t|\tGross Pay : PHP " << computedGrossPay <<"    \t  |" << endl
                    << "\t\t\t\+-----------------------------------------+" << endl
                    << "\t\t\t|\tTax: PHP " << computedTaxDependency <<"\t\t\t  |" << endl
                    << "\t\t\t\+-----------------------------------------+" << endl
                    << "\t\t\t|\tNet Pay: PHP " << computedNetPay <<"\t\t  |" << endl
                    << "\t\t\t\+-----------------------------------------+\n\n" << endl;
            }
        }
        else {  
            computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
            computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
            cout
                << fixed << setprecision(2)
                << "Gross Pay: PHP " << computeGrossPay(1, employeeCode, presentDays, shiftType, customEmployeeRate) << endl
                << "Tax: PHP " << computeTaxDependency(dependencyStatus, computeGrossPay(1, employeeCode, presentDays, shiftType, customEmployeeRate)) << endl
                << "Net Pay: PHP " << computeNetPay(computeGrossPay(1, employeeCode, presentDays, shiftType, customEmployeeRate), computeTaxDependency(dependencyStatus, computeGrossPay(1, employeeCode, presentDays, shiftType, customEmployeeRate))) << endl << endl;
        }

        //Try Again Segment
        cout << generateRandomMessage(3) << "Would you like to try again? (Y/n)";
        cin >> tA;
        if (tA == "Y" || tA == "y") {
            goto start;
        }
        else if (tA == "N" || tA == "n") {
            goto exit;
        }
        else {
            cout << generateRandomMessage(1);
            system("pause");
            goto calculateBasic;
        }
    }
    else if (calcuType == 2) {
    //Only ask for advanced

    //  Advance Counters
    int totalPresentDays = 0;
    //  Chapter - Employee Code Main
    caEmployeeCode:
    //Clear
    system("cls");
    printOutValues(2, " ");
    //Ask for employee code
    cout << "\t\t\tState employee code [A]  [B]  [C]  [D]: ";
    cin >> employeeCode;
    //  Check cin value
    while (cin.fail()) {
        clearInvalid();
        goto caEmployeeCode;
    }
    //  Perform Checks
    if (checkUserInput(1, employeeCode) == false) {
        cout << generateRandomMessage(1);
        cout << "\t" << system("pause");
        goto caEmployeeCode;
    }

    //  Chapter - Custom Employee Rate if D
    if (employeeCode == "D" || employeeCode == "d") {
        //  Ask input if yes
        //Clear
        caCustomEmployeeRate:
        system("cls");
        printOutValues(calcuType, employeeCode);
        cout << "\t\t\tEnter custom rate: ";
        cin >> customEmployeeRate;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caCustomEmployeeRate;
        }
        //  Check if not negative
        if (customEmployeeRate <= 0) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caCustomEmployeeRate;
        }
    }

    //  Chapter - Present Days
        caPresentDays:
        //Clear
        totalPresentDays = 0;
        numberOfPresentOnHoliday = 0;
        numberOfPresentOnRestDay = 0;
        numberOfPresentOnRestHoliDay = 0;
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate);
        //Ask for number of present days
        cout << "\t\t\tState the number of REGULAR present days: ";
        cin >> presentDays;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caPresentDays;
        }
        if (checkUserInput(2, " ", presentDays) == true) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caPresentDays;
        }
        if (checkUserInput(3, " ", presentDays, 30, 'f')) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caPresentDays;
        }
        totalPresentDays += presentDays;

    //  Chapter - Shift Type
        caShiftType:
        //Clear
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays);
        //Ask for shift type
        cout << "\t\t\tState the shift type (1 - Regular, 2 - Night): ";
        cin >> shiftType;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caShiftType;
        }

        //Check input
        if (checkUserInput(3, " ", shiftType, 1, 'a') == false) {
            if (checkUserInput(3, " ", shiftType, 2, 'a') == false) {
                cout << generateRandomMessage(1);
                system("pause");
                goto caShiftType;
            }
        }


        //  Chapter - Dependency
        caDependency:
        //Clear
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType);
        //Ask for dependency
        cout << "\t\t\tState the dependency type (1 - With, 2 - Without): ";
        cin >> dependencyStatus;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caDependency;
        }

        //Check input
        if (checkUserInput(3, " ", dependencyStatus, 1, 'a') == false) {
            if (checkUserInput(3, " ", dependencyStatus, 2, 'a') == false) {
                cout << generateRandomMessage(1);
                system("pause");
                goto caDependency;
            }
        }
        //  Print before proceeding to adv
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);


        //  Chapter - Number of days present in holidays
        
        //Clear
        caPresentInHolidays:
        //Reset value from rollbacks
        totalPresentDays -= numberOfPresentOnHoliday;
        //  Check if the total present days is 30
        if (checkUserInput(3, " ", totalPresentDays, 30, 'c')) {
            cout << "\t\t\tTotal of Present Days is 30. \nProceeding without adding more days...\nSkipping other day-related inputs...";
            system("pause");
            goto caOvertimeHours;
        }
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus);
        //Ask for present in holidays
        cout << "\t\t\tState the number of days present in holidays: ";
        cin >> numberOfPresentOnHoliday;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caPresentInHolidays;
        }
        //  Check if negative
        if (checkUserInput(2, " ", numberOfPresentOnHoliday) == true) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caPresentInHolidays;
        }
        //  Check if the total present days will not go over 30
        if (checkUserInput(3, " ", totalPresentDays+numberOfPresentOnHoliday, 3, 'c')) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caPresentInHolidays;
        }
        //  Add to Total Days if total days is not 30
        totalPresentDays += numberOfPresentOnHoliday;


        //  Chapter - Number of days present in Rest Day
        //Clear
        caPresentInRestDays:
        //Reset value from rollbacks
        totalPresentDays -= numberOfPresentOnRestDay;
        //  Check if the total present days is 30
        if (checkUserInput(3, " ", totalPresentDays, 30, 'c')) {
            cout << "\t\t\tTotal of Present Days is 30.\nProceeding without adding more days...\nSkipping other day-related inputs...";
            system("pause");
            goto caOvertimeHours;
            
        }
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday);
        //Ask for present in rest days
        cout << "\t\t\tState the number of days present in rest day: ";
        cin >> numberOfPresentOnRestDay;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caPresentInRestDays;
        }

        //  Check if negative
        if (checkUserInput(2, " ", numberOfPresentOnRestDay) == true) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caPresentInRestDays;
        }
        //  Check if the total present days will not go over 30
        if (checkUserInput(3, " ", totalPresentDays + numberOfPresentOnRestDay, 31, 'c')) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caPresentInRestDays;
        }
        //  Add to Total Days if total days is not 30
        totalPresentDays += numberOfPresentOnHoliday;


        //  Chapter - Number of days present in Holi-Rest Day
        //Clear
        caPresentInHoliRestDays:
        //Reset value from rollbacks
        totalPresentDays -= numberOfPresentOnRestHoliDay;
        //  Check if the total present days is 30
        if (checkUserInput(3, " ", totalPresentDays, 30, 'c')) {
            cout << "\t\t\tTotal of Present Days is 30.\nProceeding without adding more days...\nSkipping other day-related inputs...";
            system("pause");
            goto caOvertimeHours;
            
        }
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay);
        //Ask for present in holi-rest days
        cout << "\t\t\tState the number of days present in holiday at the same time rest day: ";
        cin >> numberOfPresentOnRestHoliDay;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caPresentInHoliRestDays;
        }

        //  Check if negative
        if (checkUserInput(2, " ", numberOfPresentOnRestHoliDay) == true) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caPresentInHoliRestDays;
        }
        //  Check if the total present days will not go over 30
        if (checkUserInput(3, " ", totalPresentDays + numberOfPresentOnRestHoliDay, 31, 'c')) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caPresentInHoliRestDays;
        }
        //  Add to Total Days if total days is not 30
        totalPresentDays += numberOfPresentOnRestHoliDay;

        //  Chapter - Overtime
        //Clear
        caOvertimeHours:
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay);
        //Ask for Regular OT hours
        cout << "\t\t\tState the number of regular day overtime hours: ";
        cin >> numberOfOverHours;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caOvertimeHours;
        }

        //  Check if negative
        if (checkUserInput(2, " ", numberOfOverHours) == true) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caOvertimeHours;
        }

        //  Chapter - Special Overtime
        //Clear
        caSpecialOvertimeHours:
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours);
        //Ask for present in holi-rest days
        cout << "\t\t\tState the number of special day overtime hours (this includes: Rest Day and Holidays): ";
        cin >> numberOfSpecialOverHours;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto caSpecialOvertimeHours;
        }

        //  Check if negative
        if (checkUserInput(2, " ", numberOfSpecialOverHours) == true) {
            cout << generateRandomMessage(1);
            system("pause");
            goto caSpecialOvertimeHours;
        }

        //  Chapter - Summary before processing
        cAdvanceSummary:
        //Clear
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        //Ask if this is final
        cout
            << "\t\tHere are your inputs. If you want to change values, please state the number you wish to go back to." << endl
            << "\t\tTake note that you need to re-enter the other values that you've passed through." << endl
            << "\t\tEnter 0 if it's final. Pick a value from 1-10: ";
        cin >> basicCalGoBackSteps;
        //  Check cin value
        while (cin.fail()) {
            clearInvalid();
            goto cAdvanceSummary;
        }
        //  Check input
        switch (basicCalGoBackSteps) {
        case 0:
            goto calculateAdvanced;
            break;
        case 1:
            goto firstUserInput;
            break;
        case 2:
            goto caEmployeeCode;
            break;
        case 3:
            goto caPresentDays;
            break;
        case 4:
            goto caShiftType;
            break;
        case 5:
            goto caDependency;
            break;
        case 6:
            goto caPresentInHolidays;
            break;
        case 7:
            goto caPresentInRestDays;
            break;
        case 8:
            goto caPresentInHoliRestDays;
            break;
        case 9:
            goto caOvertimeHours;
            break;
        case 10:
            goto caSpecialOvertimeHours;
            break;
        default:
            cout << generateRandomMessage(1);
            system("pause");
            goto cAdvanceSummary;
            break;
        }

        //Compute Gross Pay
        calculateAdvanced:
        system("cls");
        printOutValues(calcuType, employeeCode, customEmployeeRate, presentDays, shiftType, dependencyStatus, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
        double computedGrossPay = 0.0, computedTaxDependency = 0.0, computedNetPay = 0.0;
        //Compute
        if (employeeCode != "D") {
            if (employeeCode != "d") {
                computedGrossPay = computeGrossPay(1, employeeCode, presentDays, shiftType, 0, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
                computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
                computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
                cout
                    << fixed << setprecision(2)
                    << "+-------------------------+" << endl
                    << "|Computing Gross Pay...   |" << endl
                    << "|Computing Tax...         |" << endl
                    << "|Computing Net Pay...     |" << endl
                    << "+-------------------------+" << endl

                    << "+-------------------------+" << endl
                    << "|Gross Pay : PHP " << computedGrossPay << " |" << endl
                    << "|Tax: PHP " << computedTaxDependency << "\t  |" << endl
                    << "|Net Pay: PHP " << computedNetPay << "\t  |" << endl
                    << "+-------------------------+" << endl;
            }
        }
        else {
            computedGrossPay = computeGrossPay(1, employeeCode, presentDays, shiftType, customEmployeeRate, numberOfPresentOnHoliday, numberOfPresentOnRestDay, numberOfPresentOnRestHoliDay, numberOfOverHours, numberOfSpecialOverHours);
            computedTaxDependency = computeTaxDependency(dependencyStatus, computedGrossPay);
            computedNetPay = computeNetPay(computedGrossPay, computedTaxDependency);
            cout
                << fixed << setprecision(2)
                << "Computing Gross Pay..." << endl
                << "Computing Tax..." << endl
                << "Computing Net Pay..." << endl << endl
                << "Gross Pay: PHP " << computedGrossPay << endl
                << "Tax: PHP " << computedTaxDependency << endl
                << "Net Pay: PHP " << computedNetPay << endl << endl;
        }

        //Try Again Segment
        cout << generateRandomMessage(3) << "Would you like to try again? (Y/n)";
        cin >> tA;
        if (tA == "Y" || tA == "y") {
            goto start;
        }
        else if (tA == "N" || tA == "n") {
            goto exit;
        }
        else {
            cout << generateRandomMessage(1);
            system("pause");
            goto calculateAdvanced;
        }
    }
    else {
        cout << generateRandomMessage(1);
        system("pause");
        goto firstUserInput;
    }
    
    exit:
    cout << "Thank you for using our program!";
    system("pause");
    exit(0);
}