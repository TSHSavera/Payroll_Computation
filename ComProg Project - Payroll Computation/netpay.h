#pragma once

//Net Pay
double computeNetPay(double grossPay, double taxDependency) {
    double netPay = 0.0;
    //  Compute Net Pay
    netPay = grossPay - taxDependency;
    return netPay;
}