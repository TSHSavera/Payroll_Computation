#pragma once
#include <iostream>
#include <conio.h>
#include <string>

int enterPassword() {
    //Initialize Variables
    std::string pass = "";

    for (int i = 0; i < 3; i++) {
        system("cls");
	    //Start Asking
        std::cout << std::endl;
        std::cout << "\t\+-----------------------------------------+" << std::endl;
        std::cout << "\t\|            *--- WELCOME! ---*           |" << std::endl;
        std::cout << "\t\|             *** PAY TECH ***            |" << std::endl;
        std::cout << "\t\|        *-- precision payroll --*        |" << std::endl;
        std::cout << "\t\+-----------------------------------------+" << std::endl;
        std::cout << "\tYou have " << i+1 << "/ 3 Attempts\n" << std::endl;
        std::cout << "\tENTER PASSCODE: ";
        std::cin >> pass;
    
    
        if (pass == "1234") {
            return 0;
        }
    }
    return -1;
}