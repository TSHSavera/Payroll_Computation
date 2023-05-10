#pragma once
#include <iostream>
#include <conio.h>
#include <string>

int enterPassword() {
    //Initialize Variables
    char cpass;
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
        
        cpass = _getch();

        while (cpass != 13) {
            if (cpass == 8) {
                if (pass.length()) {
                    std::cout << "\b \b";
                    pass.pop_back();
                }
                cpass = _getch();
                continue;
            }
            pass.push_back(cpass);
            std::cout << '*';
            cpass = _getch();
        }

        if (pass == "1234") {
            return 0;
        }
        
        std::cout << std::endl << "\tWrong password. Try again." << std::endl << "\t";
        system("pause");
        pass.clear();
    }
    return -1;
}