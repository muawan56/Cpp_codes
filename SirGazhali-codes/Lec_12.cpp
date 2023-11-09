#include <iostream>

// from 0:00 to 50:00
// using namespace std;

// class Point
// {
// private:
//     int num;

// public:
//     Point() : num(0)
//     {
//         cout << "Default constructor called " << this << endl;
//     }

//     Point(int num)
//     {
//         this->num = num;
//         cout << "Overloaded constructor called " << this << endl;
//     }

//     // Copy constructor
//     Point(const Point &orig)
//     {
//         cout << "Copy constructor called " << this << endl;
//         num = orig.num;
//     }

//     ~Point()
//     {
//         cout << "Destructor called " << this << endl;
//     };

//     void setnum(int c1)
//     {
//         num = c1;
//     }
//     int getnum() const
//     {
//         return num;
//     }

//     void display()
//     {
//         cout << "In display: " << num << endl;
//     }
// };

// // local function returning Point type
// Point pointTesting()
// {

//     // For Scenario C
//     return Point(15); // Un named tempraroy object

//     // For Scenario A and B
//     // Point p1(15);
//     // return p1; // return Point type object
// }

// int main()
// {
//     // Scenario A
//     // Point p;
//     // p = pointTesting(); // Assignment
//     // p.display();        // 15

//     // Scenario B       // RVO or Copy Elision take place
//     //    Point p = pointTesting();   //  Initialization
//     //     p.display(); // 15

//     // Scenario C       // RVO or Copy Elision take place
//     Point p = pointTesting();
//     p.display();
// }

// form 50:00
using namespace std;

class Point
{
private:
    int num;
    static int p; // only declared here not allocated memory

public:
    Point() : num(0)
    {
        cout << "Default constructor called " << this << endl;
        p = p + 5;
    }

    Point(int num)
    {

        cout << "Overloaded constructor called " << this << endl;
        this->num = num;
        p = p + 10;
    }

    // Copy constructor
    Point(const Point &orig)
    {
        cout << "Copy constructor called " << this << endl;
        num = orig.num;
        p++;
    }

    ~Point()
    {
        cout << "Destructor called " << this << endl;
    };

    void setnum(int c1)
    {
        num = c1;
    }
    int getnum() const
    {
        return num;
    }

    void display()
    {
        cout << "In display Num: " << num << " Static: " << p << endl;
    }

    static int getP()
    {
        return p;
    }
};

int Point::p = 50; // memory is allocated here/ defining here

int main()
{

    // cout << "Static variable is: " << Point::getP() << endl;
    // Point p1;
    // Point p2(30);

    // p1.display();
    // p2.display();

    // For Static class objects
    static Point p1; // destroyed at end of main

    for (int i = 0; i < 5; i++)
    {
        static Point P2(15); // only one time overloaded constr is called
    }

    cout << "Main ends here" << endl;

    return 0;
}