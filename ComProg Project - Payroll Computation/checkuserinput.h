#pragma once
#include <string>

//  Check user input
bool checkUserInput(char code, char ec, double valueToBeChecked = -1, double valueToCompare = -1, char rangeRule = NULL) {
    //Code 1 - Check for employeeCode
    if (code == '1') {
        if (ec == 'a' || ec == 'A') {
            return true;
        }
        else if (ec == 'b' || ec == 'B') {
            return true;
        }
        else if (ec == 'c' || ec == 'C') {
            return true;
        }
        else if (ec == 'd' || ec == 'D') {
            return true;
        }
        else {
            return false;
        }
    }
    else if (code == '2') {
        //Code 2 - Check if negative
        if (valueToBeChecked <= -1) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (code == '3') {
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


//Check user input for character values
bool checkUserInput(char code, char ec, char valueToBeTested, char expectedValue) {
    if (code == '4') {
        if (valueToBeTested == expectedValue) {
            return true;
        }
        else {
            return false;
        }
    }
}