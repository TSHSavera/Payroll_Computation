#include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>
#include <string>
//User Defined
#include "password.h"
#include "errorHandling.h"
#include "messages.h"
#include "checkuserinput.h"
#include "print.h"
#include "grosspay.h"
#include "netpay.h"
#include "taxdep.h"
#include "questions.h"

// NOTE: REMOVE USING NAMESPACE STD. ADD STD:: TO COUT, CIN, STRING, ENDL, std::fixed, std::setprecision!
//using namespace std;

//Global Variables
std::string evaluationError = "";

//Main Function
int main() {
    //std::string calcuTypeText;

    //  Enter Password
    //cEnterPassword:
    if (enterPassword() == -1) {
        system("cls");
        // TODO: Improve the design of this!!!
        // Show a message once the user have reached the maximum number of attempts
        std::cout << "\t\t\t\t\tYou have been blocked from using the system!" << std::endl << std::endl << "\t\t\t";
        system("pause");
        exit(0);
    }

    start:
    //Initialize Variables
    char employeeCode;
    int presentDays = 0, numberOfPresentOnRestDay = 0, numberOfPresentOnHoliday = 0, numberOfPresentOnRestHoliDay = 0, numberOfOverHours = 0, numberOfSpecialOverHours = 0, numberOfAbsent = 0;
    double grossPay = 0.00, netPay = 0.00, tax = 0.00, customEmployeeRate = -1;
    char shiftType = '0', dependencyStatus = '0';

    //Function Variables
    int basicCalGoBackSteps = 0;
    char calcuType = calculationType();

    char tA;
    


    //Check calcuType
    if (calcuType == '1') {
        //Only Asks for Basics
        
        //  Chapter - Employee Code Main
        femployeeCode();

        //  Chapter - Present Days
        fpresentDays();
        
        //  Chapter - Shift Type
        fshiftType();

        //  Chapter - Dependency
        fdependencyType();
        
        //  Chapter - Summary before processing
        showBasicSummary();
        
    }
    else if (calcuType == '2') {
        //Only ask for advanced

        //  Chapter - Employee Code Main
        femployeeCode();

        //  Chapter - Present Days
        fpresentDays(false, true);
        
        //  Chapter - Shift Type
        fshiftType(false, true);

        //  Chapter - Dependency
        fdependencyType(false, true);

        //  Chapter - Number of days present in holidays
        fpresentInHoliday();


        //  Chapter - Summary before processing
        showSummaryAdvance();

        

        

        //Try Again Segment
        std::cout << generateRandomMessage(3) << "Would you like to try again? (Y/n)";
        std::cin >> tA;
        if (tA == 'Y' || tA == 'y') {
            goto start;
        }
        else if (tA == 'N' || tA == 'n') {
            goto exit;
        }
        else {
            std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
            system("pause");
            //goto calculateAdvanced;
        }
    }
    else {
        std::cout << generateRandomMessage(1) << std::endl << "\t\t\t";
        system("pause");
        calculationType();
    }
    
    exit:
    std::cout << "\t\t\tThank you for using our program!" << std::endl << "\t\t\t";
    system("pause");
    exit(0);
}