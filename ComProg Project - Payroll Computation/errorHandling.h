#pragma once
#include <iostream>

void clearInvalid() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "\n\t\t\t[ERROR] INVALID DATA TYPE INPUT" << std::endl << "Cleaning up..." << std::endl << "\t\t\t";
    system("pause");
}