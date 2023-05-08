#include <iostream>

//User Defined
#include "password.h"
#include "errorHandling.h"
#include "questions.h"

// NOTE: REMOVE USING NAMESPACE STD. ADD STD:: TO COUT, CIN, STRING, ENDL, std::fixed, std::setprecision!
//using namespace std;

//Global Variables
std::string evaluationError = "";

bool startMenus(bool prc = false) {
    int a = menu(prc);

    if (a == '1') {
        //Call pc
        int b = pc();
        if (b == 0) {
            startMenus(true);
        }
    }
    else if (a == '2') {
        //Call ev
        int c = ev();
        if (c == 0) {
            startMenus();
        }
    }
    else if (a == '3') {
        //Call led
        int d = led();
        if (d == 0) {
            startMenus();
        }
    }
    else if (a == '4') {
        //Call lcf
        int e = 0;
        if (e == 0) {
            startMenus();
        }
    }
    else if (a == '5') {
        //Call sc
        int f = 0;
        if (f == 0) {
            startMenus();
        }
    }
    else if (a == '6') {
        //Call se
        int g = se();
        if (g == 0) {
            startMenus();
        }
    }
    else if (a == 'e' || a == 'E') {
        //Exit
        return true;
    }
    else {
        startMenus();
    }
}

//Main Function
int main() {
    //  Enter Password
    //cEnterPassword:
    if (enterPassword() == -1) {
        system("cls");
        // TODO: Improve the design of this!!!
        // Show a message once the user have reached the maximum number of attempts
        std::cout << "\tYou have been blocked from using the system!" << std::endl << std::endl << "\t";
        system("pause");
        exit(0);
    }
    
    if (!startMenus()) {
        startMenus();
    }
    
    
    exit:
    std::cout << "\tThank you for using our program!" << std::endl << "\t";
    system("pause");
    exit(0);
}