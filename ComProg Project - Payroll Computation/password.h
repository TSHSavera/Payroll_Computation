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
        std::cout << "\t\t\t\+-----------------------------------------+" << std::endl;
        std::cout << "\t\t\t|          PAYROLL COMPUTATION            |" << std::endl;
        std::cout << "\t\t\t\+-----------------------------------------+" << std::endl;
        std::cout << "\t\t\tYou have " << i+1 << "/ 3 Attempts\n" << std::endl;
        std::cout << "\t\t\tENTER PASSCODE: ";
        std::cin >> pass;
    
    
        if (pass == "1234") {
            return 0;
        }
    }
    return -1;
}