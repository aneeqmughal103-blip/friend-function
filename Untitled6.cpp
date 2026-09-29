#include <iostream>
using namespace std;

// Base class
class Employee {
public:
    // Virtual function
    virtual double calculateSalary() {
        return 0;
    }

    // Virtual destructor
    virtual ~Employee() {}
};

// Derived class: FullTime Employee
class FullTime : public Employee {
private:
    double basicPay;
    double allowancePercent;
    double taxPercent;

public:
    // Constructor
    FullTime(double bp, double ap, double tp) {
        basicPay = bp;
        allowancePercent = ap;
        taxPercent = tp;
    }

    // Override calculateSalary()
    double calculateSalary() override {
        double allowance = basicPay * allowancePercent / 100;
        double tax = basicPay * taxPercent / 100;

        return basicPay + allowance - tax;
    }
};

// Derived class: PartTime Employee
class PartTime : public Employee {
private:
    int hoursWorked;
    double ratePerHour;

public:
    // Constructor
    PartTime(int hw, double rph) {
        hoursWorked = hw;
        ratePerHour = rph;
    }

    // Override calculateSalary()
    double calculateSalary() override {
        return hoursWorked * ratePerHour;
    }
};

int main() {

    // Creating objects
    FullTime fullEmp(50000, 20, 10);
    PartTime partEmp(40, 500);

    // Base class pointer
    Employee* emp;

    // FullTime employee salary
    emp = &fullEmp;
    cout << "FullTime Employee Salary: "
         << emp->calculateSalary() << endl;

    // PartTime employee salary
    emp = &partEmp;
    cout << "PartTime Employee Salary: "
         << emp->calculateSalary() << endl;

    return 0;
}
