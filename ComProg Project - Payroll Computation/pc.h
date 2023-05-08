#pragma once

//Function Variables
char calcuType = calculationType();

//Check calcuType
if (calcuType == '1') {
    if (femployeeName() == 0) {
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
                            int b = tryAgain();
                            if (b == 1) {
                                goto startCalcu;
                            }
                            else if ()
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
                                int b = tryAgain();
                            }
                        }
                    }
                }
            }
        }
    }
}
else if (calcuType == '2') {
    if (femployeeName() == 0) {
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
                                                int b = tryAgain();
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
                                                    int b = tryAgain();
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