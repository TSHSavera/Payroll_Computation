#include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>
#include <string>
//User Defined
#include "password.h"
#include "errorHandling.h"
#include "questions.h"

// NOTE: REMOVE USING NAMESPACE STD. ADD STD:: TO COUT, CIN, STRING, ENDL, std::fixed, std::setprecision!
//using namespace std;

//Global Variables
std::string evaluationError = "";


//Main Function
int main() {
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
    int a = menu();

    if (a == '1') {
        //Call pc
        int b = pc(cc);
        if (b == 0) {
            goto start;
        }
    }
    else if (a == '2') {
        //Call ev
        int c = ev();
        if (c == 0) {
            goto start;
        }
    }
    else if (a == '3') {
        //Call led
        int d = 0;
        if (d == 0) {
            goto start;
        }
    }
    else if (a == '4') {
        //Call lcf
        int e = 0;
        if (e == 0) {
            goto start;
        }
    }
    else if (a == '5') {
        //Call sc
        int f = 0;
        if (f == 0) {
            goto start;
        }
    }
    else if (a == '6') {
        //Call se
        int g = 0;
        if (g == 0) {
            goto start;
        }
    }
    else if (a == 'e' || a == 'E') {
        //Exit
        goto exit;
    }
    else {
        goto start;
    }

    
    
    exit:
    std::cout << "\t\t\tThank you for using our program!" << std::endl << "\t\t\t";
    system("pause");
    exit(0);
}