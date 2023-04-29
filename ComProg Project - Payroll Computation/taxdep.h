#pragma once

struct staticValues {
    //Dependencies
    double withDep;
    double withoutDep;
};

//Tax - Dependency
double computeTaxDependency(int typeOfTax, double grossPay) {
    staticValues staticA;
    //Dependency
    staticA.withDep = 0.10;
    staticA.withoutDep = 0.20;

    double taxDependency = 0.0;
    //  Know the type of tax
    if (typeOfTax == 1) {
        //  Compute With Dependency Tax
        taxDependency = grossPay * staticA.withDep;
        return taxDependency;
    }
    else if (typeOfTax == 2) {
        //  Compute Without Dependency Tax
        taxDependency = grossPay * staticA.withoutDep;
        return taxDependency;
    }
    else {
        return -1;
    }
}
