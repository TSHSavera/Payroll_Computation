#pragma once

//Static Values
struct staticVal {
    //Employee Codes
    double code1;
    double code2;
    double code3;
    //Special Days - Regular
    double holidayMultiplier;
    double restDayMultiplier;
    double restHoliDayMultiplier;
    //Special Days - Night
    double restDayNightMultiplier;
    double nightShiftMultiplier;
    double holidayNightMultiplier;
    double restHoliDayNightMultiplier;
    //Overtime
    double overtimeMultiplier;
    double overtimeRestDayMultiplier;
};

//  Gross Pay
double computeGrossPay(double cc[3], char calculationType, char employeeCode, int numberOfPresentDays, char shiftType, double customDailyRate = 0.0, int presentOnHoliday = 0, int presentOnRestDay = 0, int presentOnRestHoliDay = 0, int overtimeHours = 0, int overtimeHoursOnRestDay = 0) {
    //Placeholders
    double grossPay = 0.00;
    staticVal staticA;
    //Assignment
    //Employee Codes
    staticA.code1 = cc[0];
    staticA.code2 = cc[1];
    staticA.code3 = cc[2];

    //Special Days - Regular
    staticA.holidayMultiplier = 2.00;
    staticA.restDayMultiplier = 1.30;
    staticA.restHoliDayMultiplier = 2.60;
    //Special Days - Night
    staticA.restDayNightMultiplier = 1.43;
    staticA.nightShiftMultiplier = 1.10;
    staticA.holidayNightMultiplier = 2.20;
    staticA.restHoliDayNightMultiplier = 2.70;
    //Overtime
    staticA.overtimeMultiplier = 1.25;
    staticA.overtimeRestDayMultiplier = 1.69;

    if (calculationType == '1') {
        //Do Basic Calculations
        //  Check Employee Code
        if (employeeCode == 'a' || employeeCode == 'A') {
            //  Calculate for EC-A
            //  Check Shift Type (regular or night)
            if (shiftType == '1') {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * (staticA.code1);
                return grossPay;
            }
            else if (shiftType == '2') {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (staticA.code1 * staticA.nightShiftMultiplier);
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == 'b' || employeeCode == 'B') {
            //Calculate for EC-B
            //  Check Shift Type (regular or night)
            if (shiftType == '1') {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * (staticA.code2);
                return grossPay;
            }
            else if (shiftType == '2') {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (staticA.code2 * staticA.nightShiftMultiplier);
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == 'c' || employeeCode == 'C') {
            //Calculate for EC-C
            //  Check Shift Type (regular or night)
            if (shiftType == '1') {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * (staticA.code3);
                return grossPay;
            }
            else if (shiftType == '2') {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (staticA.code3 * staticA.nightShiftMultiplier);
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == 'd' || employeeCode == 'D') {
            //Calculate for EC-D
            //  Check Shift Type (regular or night)
            if (shiftType == '1') {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * (customDailyRate);
                return grossPay;
            }
            else if (shiftType == '2') {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (customDailyRate * staticA.nightShiftMultiplier);
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else {
            return -2;
        }
    }
    else if (calculationType == '2') {
        //Do Advance Calculations
        //  Check Employee Code
        if (employeeCode == 'a' || employeeCode == 'A') {
            //  Calculate for EC-A
            //  Check Shift Type (regular or night)
            if (shiftType == '1') {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * staticA.code1;
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (staticA.code1 * staticA.holidayMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (staticA.code1 * staticA.restDayMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (staticA.code1 * staticA.restHoliDayMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * staticA.overtimeMultiplier * staticA.code2;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * staticA.overtimeRestDayMultiplier * staticA.code2;
                }
                return grossPay;
            }
            else if (shiftType == '2') {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (staticA.code1 * staticA.nightShiftMultiplier);
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (staticA.code1 * staticA.holidayNightMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (staticA.code1 * staticA.restDayNightMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (staticA.code1 * staticA.restHoliDayNightMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * staticA.overtimeMultiplier * staticA.code1;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * staticA.overtimeRestDayMultiplier * staticA.code1;
                }
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == 'b' || employeeCode == 'B') {
            //Calculate for EC-B
            //  Check Shift Type (regular or night)
            if (shiftType == '1') {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * staticA.code2;
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (staticA.code2 * staticA.holidayMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (staticA.code2 * staticA.restDayMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (staticA.code2 * staticA.restHoliDayMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * staticA.overtimeMultiplier * staticA.code2;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * staticA.overtimeRestDayMultiplier * staticA.code2;
                }
                return grossPay;
            }
            else if (shiftType == '2') {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (staticA.code2 * staticA.nightShiftMultiplier);
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (staticA.code2 * staticA.holidayNightMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (staticA.code2 * staticA.restDayNightMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (staticA.code2 * staticA.restHoliDayNightMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * staticA.overtimeMultiplier * staticA.code2;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * staticA.overtimeRestDayMultiplier * staticA.code2;
                }
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == 'c' || employeeCode == 'C') {
            //Calculate for EC-C
            //  Check Shift Type (regular or night)
            if (shiftType == '1') {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * staticA.code3;
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (staticA.code3 * staticA.holidayMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (staticA.code3 * staticA.restDayMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (staticA.code3 * staticA.restHoliDayMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * staticA.overtimeMultiplier * staticA.code3;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * staticA.overtimeRestDayMultiplier * staticA.code3;
                }
                return grossPay;
            }
            else if (shiftType == '2') {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (staticA.code3 * staticA.nightShiftMultiplier);
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (staticA.code3 * staticA.holidayNightMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (staticA.code3 * staticA.restDayNightMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (staticA.code3 * staticA.restHoliDayNightMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * staticA.overtimeMultiplier * staticA.code3;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * staticA.overtimeRestDayMultiplier * staticA.code3;
                }
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else if (employeeCode == 'd' || employeeCode == 'D') {
            //Calculate for EC-C
            //  Check Shift Type (regular or night)
            if (shiftType == '1') {
                //  Regular
                grossPay = (8 * numberOfPresentDays) * customDailyRate;
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (customDailyRate * staticA.holidayMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (customDailyRate * staticA.restDayMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (customDailyRate * staticA.restHoliDayMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * staticA.overtimeMultiplier * customDailyRate;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * staticA.overtimeRestDayMultiplier * customDailyRate;
                }
                return grossPay;
            }
            else if (shiftType == '2') {
                //  Night
                grossPay = (8 * numberOfPresentDays) * (customDailyRate * staticA.nightShiftMultiplier);
                //  Check if presentOnHoliday is present, if yes - calculate, if no - skip
                if (presentOnHoliday > 0) {
                    //  Compute
                    grossPay += (8 * presentOnHoliday) * (customDailyRate * staticA.holidayNightMultiplier);
                }
                //  Check if presentOnRestDay is present, if yes - calculate, if no - skip
                if (presentOnRestDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestDay) * (customDailyRate * staticA.restDayNightMultiplier);
                }
                //  Check if presentOnRestHoliDay is present, if yes - calculate, if no - skip
                if (presentOnRestHoliDay > 0) {
                    //  Compute
                    grossPay += (8 * presentOnRestHoliDay) * (customDailyRate * staticA.restHoliDayNightMultiplier);
                }
                //  Check if overtime is present, if yes - calculate, if no - skip
                if (overtimeHours > 0) {
                    //  Compute
                    grossPay += overtimeHours * staticA.overtimeMultiplier * customDailyRate;
                }
                //  Check if overtimeOnRestDay is present, if yes - calculate, if no - skip
                if (overtimeHoursOnRestDay > 0) {
                    //  Compute
                    grossPay += overtimeHoursOnRestDay * staticA.overtimeRestDayMultiplier * customDailyRate;
                }
                return grossPay;
            }
            else {
                return -3;
            }
        }
        else {
            return -2;
        }
    }
    else {
        return -1;
    }
}