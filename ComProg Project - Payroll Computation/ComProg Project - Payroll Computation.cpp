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



    //Function Variables
    start:
    char calcuType = calculationType();
    


    //Check calcuType
    if (calcuType == '1') {
        if (femployeeName_first() == 0) {
            if (femployeeName_mid() == 0) {
                if (femployeeName_last() == 0) {
                    //Only Asks for Basics
                    int a = femployeeCode();

                    //  Chapter - Employee Code Main
                    if (a == 0) {
                        //  Chapter - Present Days
                        //Go code without fcCustomEmployee
                        if (fpresentDays() == 0) {
                            //  Chapter - Shift Type
                            if (fshiftType() == 0) {
                                //  Chapter - Dependency
                                if (fdependencyType() == 0) {
                                    //  Chapter - Summary before processing
                                    if (showBasicSummary() == 0) {
                                        // TODO: IF TA RETURNS 1 GOTO START AGAIN, ELSE EXIT.
                                        tryAgain();
                                    }
                                }
                            }
                        }
                    }
                    if (a == 1) {
                        //  Chapter - Custom Employee Rate
                        if (fcCustomEmployeeRate() == 0) {
                            //  Chapter - Present Days
                            if (fpresentDays() == 0) {
                                //  Chapter - Shift Type
                                if (fshiftType() == 0) {
                                    //  Chapter - Dependency
                                    if (fdependencyType() == 0) {
                                        //  Chapter - Summary before processing
                                        if (showBasicSummary() == 0) {
                                            tryAgain();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (calcuType == '2') {
        if (femployeeName_first() == 0) {
            if (femployeeName_mid() == 0) {
                if (femployeeName_last() == 0) {
                    //Only ask for advanced
                    int a = femployeeCode();

                    //  Chapter - Employee Code Main
                    if (a == 0) {
                        //  Chapter - Present Days
                        //Go code without fcCustomEmployee
                        if (fpresentDays(false, true) == 0) {
                            //  Chapter - Shift Type
                            if (fshiftType() == 0) {
                                //  Chapter - Dependency
                                if (fdependencyType() == 0) {
                                    //  Chapter - Number of days present in holidays
                                    if (fpresentInHoliday() == 0) {
                                        //  Chapter - Number of days present in rest
                                        if (fpresentInRest() == 0) {
                                            //  Chapter - Number of days present in holirest
                                            if (fpresentInHoliRest() == 0) {
                                                //  Chapter - Number of overtime hours
                                                if (overtimeHours() == 0) {
                                                    //  Chapter - Number of special overtime hours
                                                    if (overtimeHoursSpecial() == 0) {
                                                        //  Chapter - Summary before processing
                                                        if (showSummaryAdvance() == 0) {
                                                            tryAgain();
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (a == 1) {
                        //  Chapter - Custom Employee Rate
                        if (fcCustomEmployeeRate() == 0) {
                            //  Chapter - Present Days
                            if (fpresentDays(false, true) == 0) {
                                //  Chapter - Shift Type
                                if (fshiftType() == 0) {
                                    //  Chapter - Dependency
                                    if (fdependencyType() == 0) {
                                        //  Chapter - Number of days present in holidays
                                        if (fpresentInHoliday() == 0) {
                                            //  Chapter - Number of days present in rest
                                            if (fpresentInRest() == 0) {
                                                //  Chapter - Number of days present in holirest
                                                if (fpresentInHoliRest() == 0) {
                                                    //  Chapter - Number of overtime hours
                                                    if (overtimeHours() == 0) {
                                                        //  Chapter - Number of special overtime hours
                                                        if (overtimeHoursSpecial() == 0) {
                                                            //  Chapter - Summary before processing
                                                            if (showSummaryAdvance() == 0) {
                                                                tryAgain();
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
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