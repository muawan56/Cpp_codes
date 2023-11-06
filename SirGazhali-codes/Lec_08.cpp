#include <iostream>

using namespace std;

class Test
{
private:
    int val;
    int *p;

public:
    // Default constructor of class
    Test() : val(0) // member initializer list
    {
        p = new int;
        *p = 0;
        cout << "Default constructor is called on " << val << " " << *p << endl;
    }
    // Parameterized constructor
    Test(int v1, int v2) : val(v1)
    {
        p = new int;
        *p = v2;
        cout << "Constructor is called on " << val << " " << *p << endl;
    }
    void setValue(int temp)
    {
        val = temp;
    }
    void displayTest() const
    {
        cout << "Inside main array: " << val << " " << *p << endl;
    }
    // Destructor of class Test
    ~Test()
    {
        cout << "Destructor is called on " << val << " " << *p << endl;
        if (p)
        {
            delete p;
            p = nullptr;
        }
    }
};
int main()
{
    Test t1;
    Test t2(4, 15); // destructor is called first bcz it is on stack
    // t1.displayTest();
    // t2.displayTest();
    cout << endl
         << "On HEAP" << endl;
    Test *t3 = new Test;
    Test *t4 = new Test(3, 17); // their destructor is not called unless we use delete keyword
                                // bcz they are created on HEAP.
    delete t3;
    t3 = nullptr;
    delete t4;
    t4 = nullptr;

    cout << endl
         << "Array" << endl;

    Test *arr = new Test[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i].setValue(i * 10);
        arr[i].displayTest();
    }

    delete[] arr;
    arr = nullptr;
    return 0;
}