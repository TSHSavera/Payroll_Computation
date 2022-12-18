#include <iostream>
#include <iomanip>
using namespace std;

//Global Variables
string evaluationError = "";

string successMessages(int number) {
    switch (number) {
    case 1:
        return "Sweet! That went well. ";
        break;

    case 2:
        return "I've got that very clear! ";
        break;

    case 3:
        return "This should be good to go. ";
        break;

    case 4:
        return "I see, I see. ";
        break;

    case 5:
        return "That was fast and neat! Moving forward. ";
        break;

    default:
        return "Unknown parameter passed";
        break;
    }
    
}
string wrongMessages(int number) {
    switch (number) {
    case 1:
        return "<Payroll Calculator> That doesn't seem right. Please try again...\n";
        break;

    case 2:
        return "<Payroll Calculator> It seems you've failed to follow the conditions. Retrying...\n";
        break;

    case 3:
        return "<Payroll Calculator> There was a mistake in your input. Going back up...\n";
        break;

    case 4:
        return "<Payroll Calculator> Let's try to avoid that mistake next time. Re-enter that data needed...\n";
        break;

    case 5:
        return "<Payroll Calculator> Let me guess, you have a typographical error. Don't worry, we'll return to the previous question...\n";
        break;

    default:
        return "<Payroll Calculator> Unknown parameter passed\n";
        break;
    }
}

//Randomize Messages
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
    }

    //Return
    return messageString;
}

//Main Function
int main() {
start:
    //Initialize Variables
    int employeeCode = 0;
    int calcuType = 0, numberOfHours = 0, presentDays = 0, shiftType, dependencyStatus = 0, numberOfPresentOnRestDay = 0, numberOfPresentOnHoliday = 0, numberOfPresentOnRestHoliDay = 0, numberOfOverHours = 0, numberOfAbsent = 0;
    double grossPay = 0.00, netPay = 0.00, tax = 0.00;
    string tA, cC;

    //Static Values
    double
        code1 = 250.0,
        code2 = 320.0,
        code3 = 450.0,
        withDep = 0.10,
        withoutDep = 0.20,
        holidayMultiplier = 2.00,
        restDayMultiplier = 1.30,
        restHoliDayMultiplier = 2.60,
        restDayNightMultiplier = 1.43,
        nightShiftMultiplier = 1.10,
        holidayNightMultiplier = 2.20,
        overtimeMultiplier = 1.25,
        overtimeRestDayMultiplier = 1.69;

    //Get user input
    //  Base
    cout << "\t\t\t\t\t\tPAYROLL CALCULATOR" << endl;
    cout << "========================================================================================================================" << endl;
    cout << "\t\t\t\tPlease choose an EMPLOYEE CODE: [1]\t [2]\t [3]\t" << endl;
    cout << "\n<Payroll Calculator> Welcome! To get started please enter the employee code: ";
    cin >> employeeCode;
    //  Check user input
    if (employeeCode <= 0 || employeeCode > 3) {
        cout << generateRandomMessage(1);
        goto start;
    }
    
cCalculationType:
    cout
        << "<Payroll Calculator> That was clear! Now, I wanna ask you if you want to access advance calculations."
        << endl << "\nBasic Calculation Includes: Number of absent, type of shift, and dependency. The system will always consider the REGULAR values on calculating the payroll (8 hours a day, 5 days a week, monthly payroll)"
        << endl << "Advance Calculation Includes: Custom working hours, type of Shift, civil status, rest day and holiday calculations, and overtime."
        << endl << "\n<Payroll Calculator> Type 1 if Yes, 2 if No (1 or 2): ";
    cin >> calcuType;
    //  Check user input
    if (calcuType == 1) {
        goto AdvanceCalculations;
    }
    else if (calcuType == 2) {
        goto BasicCalculations;
    }
    else {
        cout << generateRandomMessage(1);
        goto cCalculationType;
    }
    

    //  Basic
BasicCalculations:
cNumberOfAbsentBasic:
    cout << "<Payroll Calculator> Since you've opted to basic calculator, please enter the number of absent days: ";
    cin >> numberOfAbsent;
    //  Check user input
    if (numberOfAbsent <= -1) {
        cout << generateRandomMessage(1);
        goto cNumberOfAbsentBasic;
    } else {
        goto cShiftTypeBasic;
    }
    

cShiftTypeBasic:
    cout << "\n<Payroll Calculator> " << generateRandomMessage(2) << "Now, please enter the type of shift."<<"\n Enter [1] if REGULAR and [2] if NIGHT : ";
    cin >> shiftType;
    //  Check user input
    if (shiftType == 1 || shiftType == 2) {
        goto cDependencyStatusBasic;
    }
    else {
        cout << generateRandomMessage(1);
        goto cShiftTypeBasic;
    }

cDependencyStatusBasic:
    cout << "\n<Payroll Calculator> " << generateRandomMessage(2) << "Now, please state if you have any dependents." << "\n Enter [1] if you have child or dependent relative, [2] if single: ";
    cin >> dependencyStatus;

    if (dependencyStatus == 1 || dependencyStatus == 2) {
        if (employeeCode == 1) {
            goto employeeCode1;
        }
        else if (employeeCode == 2) {
            goto employeeCode2;
        }
        else if (employeeCode == 3) {
            goto employeeCode3;
        }
    }
    else {
        cout << generateRandomMessage(1);
        goto cDependencyStatusBasic;
    }




AdvanceCalculations:

    //  Advance
    cout << "<Payroll Calculator> " << generateRandomMessage(2) << " Now, please enter the TOTAL number of his REGULAR working hours: ";
    cin >> numberOfHours;


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
    //Check if it's a basic or advance calculation
    if (calcuType == 2) {
        //  Basic Calculations
        
        //Check if the employee's dependency status
        if (dependencyStatus == 1) {
            //Check shift
            if (shiftType == 1) {
                //Calculate now - with Depedent - Regular Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * code1;
                tax = grossPay * withDep;
                netPay = grossPay - tax;
                cout << "\n<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl 
                        << "\n\tGross Pay: PHP " << grossPay << endl 
                        << "\tTax: PHP " << tax << endl 
                        << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else if (shiftType == 2) {
                //Calculate now - with Dependent - Night Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * (code1*nightShiftMultiplier);
                tax = grossPay * withDep;
                netPay = grossPay - tax;
                cout << "\n<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl 
                        << "\n\tGross Pay: PHP " << grossPay << endl 
                        << "\tTax: PHP " << tax << endl 
                        << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else {
                cout << generateRandomMessage(1);
                goto start;
            }
        }
        else if (dependencyStatus == 2) {
            //Check shift
            if (shiftType == 1) {
                //Calculate now - without Depedent - Regular Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * code1;
                tax = grossPay * withoutDep;
                netPay = grossPay - tax;
                cout << "\n<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else if (shiftType == 2) {
                //Calculate now - without Dependent - Night Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * (code1 * nightShiftMultiplier);
                tax = grossPay * withoutDep;
                netPay = grossPay - tax;
                cout << "\n<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else {
                cout << generateRandomMessage(1);
                goto start;
            }
        }
    }
employeeCode2:
    //Check if it's a basic or advance calculation
    if (calcuType == 2) {
        //  Basic Calculations

        //Check if the employee's dependency status
        if (dependencyStatus == 1) {
            //Check shift
            if (shiftType == 1) {
                //Calculate now - with Depedent - Regular Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * code2;
                tax = grossPay * withDep;
                netPay = grossPay - tax;
                cout << "\n<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else if (shiftType == 2) {
                //Calculate now - with Dependent - Night Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * (code2 * nightShiftMultiplier);
                tax = grossPay * withDep;
                netPay = grossPay - tax;
                cout << "\n<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else {
                cout << generateRandomMessage(1);
                goto start;
            }
        }
        else if (dependencyStatus == 2) {
            //Check shift
            if (shiftType == 1) {
                //Calculate now - without Depedent - Regular Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * code2;
                tax = grossPay * withoutDep;
                netPay = grossPay - tax;
                cout << "<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else if (shiftType == 2) {
                //Calculate now - without Dependent - Night Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * (code2 * nightShiftMultiplier);
                tax = grossPay * withoutDep;
                netPay = grossPay - tax;
                cout << "<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else {
                cout << generateRandomMessage(1);
                goto start;
            }
        }
    }
employeeCode3:
    //Check if it's a basic or advance calculation
    if (calcuType == 2) {
        //  Basic Calculations

        //Check if the employee's dependency status
        if (dependencyStatus == 1) {
            //Check shift
            if (shiftType == 1) {
                //Calculate now - with Depedent - Regular Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * code3;
                tax = grossPay * withDep;
                netPay = grossPay - tax;
                cout << "<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else if (shiftType == 2) {
                //Calculate now - with Dependent - Night Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * (code3 * nightShiftMultiplier);
                tax = grossPay * withDep;
                netPay = grossPay - tax;
                cout << "<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else {
                cout << generateRandomMessage(1);
                goto start;
            }
        }
        else if (dependencyStatus == 2) {
            //Check shift
            if (shiftType == 1) {
                //Calculate now - without Depedent - Regular Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * code3;
                tax = grossPay * withoutDep;
                netPay = grossPay - tax;
                cout << "<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else if (shiftType == 2) {
                //Calculate now - without Dependent - Night Shift
                grossPay = ((8 * 5 * 4) - numberOfAbsent) * (code3 * nightShiftMultiplier);
                tax = grossPay * withoutDep;
                netPay = grossPay - tax;
                cout << "<Payroll Calculator> I've successfully calculated your gross pay, tax, and net pay!" << endl
                    << "\n\tGross Pay: PHP " << grossPay << endl
                    << "\tTax: PHP " << tax << endl
                    << "\tNet Pay: PHP " << netPay << endl;
                //After completing the task, go to try again.
                goto tryAgain;
            }
            else {
                cout << generateRandomMessage(1);
                goto start;
            }
        }
    }
error:
    cout << "test";

tryAgain:
    //Ask if they want to try again
    cout << endl << "<Payroll Calculator> Operation done! Do you want to try again? (Y/n): ";
    cin >> tA;

    if (tA == "y" || tA == "Y") {
clearConsole:
        //Ask if they want to clear the console
        cout << "<Payroll Calculator> Do you want to clear the console? (Y/n): ";
        cin >> cC;

        if (cC == "y" || cC == "Y") {
            system("cls");
            goto start;
        }
        else if (cC == "n" || cC == "N") {
            goto start;
        }
        else {
            cout << endl << generateRandomMessage(1);
            goto clearConsole;
        }
    }
    else if (tA == "n" || tA == "N") {
        cout << endl << "Thank You and God Bless!" << endl;
        system("pause");
        exit(0);
    }
    else {
        cout << endl << generateRandomMessage(1);
        goto tryAgain;
    }
}