#include <iostream>
using namespace std;

class Employee
{
protected:
    int empNo, basicSalary, currentMonthSalary;
    static int employeeCount;

public:
    Employee(int bSalary)
    {
        basicSalary = bSalary;
        empNo = employeeCount++;
    }

    friend ostream &operator<<(ostream &out, const Employee &employee)
    {
        out << "Employee Number:" << employee.empNo << '\n';
        out << "Basic Salary:  " << employee.basicSalary << '\n';
        if (employee.currentMonthSalary != 0)
            out << "Salary:  " << employee.currentMonthSalary << '\n';
        return out;
    }

    virtual int calculateSalary(int)
    {
        // 45% house rent, 10% medical allowance
        currentMonthSalary = basicSalary + basicSalary * 0.45 + basicSalary * 0.1;
        return currentMonthSalary;
    }
};

int Employee::employeeCount = 1;

class RegularEmployee : public Employee
{
public:
    RegularEmployee(int bSalary) : Employee(bSalary) {}

    friend ostream &operator<<(ostream &out, const RegularEmployee &employee)
    {
        // Call parent class ostream by type casting
        out << static_cast<const Employee &>(employee);
        return out;
    }
};

class SalesMan : public Employee
{
private:
    float commissionRate;

public:
    SalesMan(int bSalary, float commission) : Employee(bSalary), commissionRate(commission) {}

    int calculateSalary(int sales) override
    {
        // Call parent class calculateSalary function to get regular salary
        int regularSalary = Employee::calculateSalary(0);

        // Calculate commission for this month
        int commission = static_cast<int>(sales * commissionRate);

        // Add commission to the current month salary
        currentMonthSalary = regularSalary + commission;

        return currentMonthSalary;
    }

    friend ostream &operator<<(ostream &out, const SalesMan &salesman)
    {
        // Call parent class ostream by type casting
        out << static_cast<const Employee &>(salesman);
        return out;
    }
};

int main()
{
    RegularEmployee emp1(30000);
    emp1.calculateSalary(20000);
    cout << emp1;
    cout << "\n***************\n\n";

    SalesMan emp2(20000, 0.02);
    emp2.calculateSalary(200000);
    cout << emp2;
    cout << "\n***************\n\n";

    Employee *emp = new RegularEmployee(35000);
    cout << *emp; // Calling ostream of Employee
    delete emp;
    cout << "\n***************\n\n";

    emp = new SalesMan(25000, 0.03);
    ((SalesMan *)emp)->calculateSalary(180000);
    cout << *emp; // Calling ostream of Employee
    delete emp;

    return 0;
}
