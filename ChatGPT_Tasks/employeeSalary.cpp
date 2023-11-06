#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string name;
    double salary;
    static constexpr double DEFAULT_SALARY = 0.00;

public:
    Employee() : name("Jhon Deo"), salary(DEFAULT_SALARY) {}
    Employee(string employee, double sal) : name(employee), salary(sal) {}
    string getName() const
    {
        return name;
    }
    double getSalary() const
    {
        return salary;
    }

    void giveRaise(const double &newSalary)
    {
        salary += newSalary;
    }

    ~Employee() {}
};

int main()
{
    Employee person1("Usama", 100000);
    string name = person1.getName();
    double salary = person1.getSalary();

    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;

    person1.giveRaise(20000);
    salary = person1.getSalary();
    cout << "New salary: " << salary << endl;

    return 0;
}