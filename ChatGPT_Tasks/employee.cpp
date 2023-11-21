/*Design a class hierarchy for a company that includes employees, managers, and executives.

Encapsulate employee information (name, designation, salary)
Implement methods for calculating payroll and assigning benefits
Derive manager and executive classes from the employee class, adding specific functionalities like managing projects and setting company policies*/

#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string name, designation;
    double salary;

public:
    Employee() : name(""), designation(""), salary(0.00) {}
    Employee(string name, string designation, double salary) : name(name), designation(designation)
    {
        if (salary < 0)
        {
            cout << "Error: Salary cannot be negative." << endl;
            return;
        }
        else
        {
            this->salary = salary;
        }
    }

    // COPY constructor
    Employee(const Employee &orig)
    {
        name = orig.name;
        designation = orig.designation;
        salary = orig.salary;
    }

    // GETTERS functions
    string getName() const
    {
        return name;
    }
    string getDesignation() const
    {
        return designation;
    }
    double getSalary() const
    {
        return salary;
    }

    // SETTERS functions
    void setName(string name) { this->name = name; }
    void setDesignation(string designation) { this->designation = designation; }
    void setSalary(double salary)
    {
        if (salary < 0)
        {
            cout << "Error: Salary cannot be negative." << endl;
            return;
        }
        this->salary = salary;
    }

    // PAYROLL
    double calPayrollAnnually()
    {
        double grosspay = salary * 12;
        double taxdeduction = grosspay * 0.2;
        double insurance = grosspay * 0.05;
        double netpay = grosspay - taxdeduction - insurance;
        return netpay;
    }

    void assignBenefits()
    {
        cout << "\n----------------------------\nAssigning Benefits for " << getName() << " is:" << endl;
        if (getDesignation() == "Executive")
        {
            cout << "Health Insurance\nCar(Fortuner)\nMedical Free" << endl;
        }
        else if (getDesignation() == "Manager")
        {
            cout << "Flat For Free\nCar(Mehran)\nMedical upto 500,000" << endl;
        }
        else
        {
            cout << "Employee has free lunch." << endl;
        }
    }
};

// Mangers class
class Managers : public Employee
{
private:
    string work;

public:
    Managers() : work("none") {}
    Managers(string work) : work(work) {}

    void display() const
    {
        cout << work << endl;
    }
};

// Executive class
class Executive : public Employee
{
private:
    string responsibility;

public:
    Executive() : responsibility("none") {}
    Executive(string responsibility) : responsibility(responsibility) {}

    void display() const
    {
        cout << responsibility << endl;
    }
};

int main()
{
    Employee p1("Talha", "Manager", 50000);
    double netpay = p1.calPayrollAnnually();
    cout << "Annual net pay is:" << netpay << endl;
    p1.setSalary(100000);
    netpay = p1.calPayrollAnnually();
    cout << "Annual net pay is:" << netpay << endl;
    p1.assignBenefits();
    Managers m1("He has to manage the project");
    m1.display();

    Employee p2("Ali", "Executive", 250000);
    p2.calPayrollAnnually();
    p2.assignBenefits();
    Executive e1("He has to superwise the project");
    e1.display();

    Employee p3("Shery", "employee", 60000);
    p3.assignBenefits();

    return 0;
}