#include <iostream>
using namespace std;

class Test
{
private:
    int any;
    const int num; // const member variable

public:
    Test() : num(99) // it is initialized here or where it is declared
    {
        // num = 99; //ERROR bcz const variable cannot initialize here
    }

    Test(int val) : any(val), num(val) // it is initialized by the parameter too
    {
        cout << "Parameterized constructor on " << any << " " << num << endl;
    }

    void displayPoint()
    {
        cout << "Const is: " << num << endl;
    }
};

int main()
{
    Test t1(55);
    t1.displayPoint();
    return 0;
}


// 31:33
/*#include <iostream>

using namespace std;

class Test
{
private:
    const int num; // if it is defined first and we want to store val in num then it will store garbage
    int val;

public:
    Test() : num(99) // it is initialized here or where it is declared
    {
        // num = 99; //ERROR bcz const variable cannot initialize here
    }

    Test(int value) : val(value), num(val) // garbage will be stored in num as val is defined later in private
    {
        cout << "Parameterized constructor on " << val << " " << num << endl;
    }

    void displayPoint()
    {
        cout << "Const is: " << num << endl;
    }
};

int main()
{
    Test t1(55);
    t1.displayPoint();
    return 0;
}*/