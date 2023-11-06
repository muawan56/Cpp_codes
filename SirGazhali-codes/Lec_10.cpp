#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
    int xCoordinate;
    int yCoordinate;

public:
    // Default constructor
    Point();

    // Overloaded constructor
    Point(int c1, int c2);

    // Copy constructor
    Point(const Point &);

    // Destructor
    ~Point();

    void setX(int c1)
    {
        xCoordinate = c1;
    }
    int getX() const
    {
        return xCoordinate;
    }
    void setY(int c2)
    {
        yCoordinate = c2;
    }
    int getY() const
    {
        return yCoordinate;
    }

    void displayCoordinates() const;
    void setCoordinates(int x, int y);
};

// Default constructor
Point::Point() : xCoordinate(0), yCoordinate(0)
{
    cout << "Default constructor is called!" << xCoordinate << " " << yCoordinate << endl;
    // cout << "Default constructor address" << this << endl;  // shows address
}

// Overloaded constructor
Point::Point(int c1, int c2) : xCoordinate(c1), yCoordinate(c2)
{
    cout << "Overloaded constructor is called!" << endl;
    cout << "Overloaded constructor address" << this << endl;
}

// Copy constructor
Point::Point(const Point &original) // temp is sent by reference here in parameter(original);
{
    cout << "COPY constructor called" << endl;
    // cout << "COPY constructor address" << this << endl;  // show address of this member func

    xCoordinate = original.xCoordinate; // do this in member initializer list as well
    yCoordinate = original.yCoordinate;
}

// Destructor
Point::~Point()
{
    cout << "Destructor is called on " << xCoordinate << " " << yCoordinate << endl;
}

void Point::displayCoordinates() const
{
    cout << "Coordinates are (" << getX() << ", " << getY() << ")" << endl;
}

void Point::setCoordinates(int x, int y)
{
    setX(x);
    setY(y);
}

// // pass object by REFERENCE
// void display(Point &p)
// {
//     p.displayCoordinates();
//     cout << "pass object by REFERENCE!" << endl;
// }

// pass object by VALUE
void display(Point temp) // temp is created by COPY CONSTRUCTOR
{
    temp.displayCoordinates();
    cout << "Address of temp is " << &temp << endl;
    // cout << "Default constructor address" << this << endl; //ERROR this cannot be used in non member function
}

Point createAfunction()
{
    Point temp;  // 2. default constructor is called
    temp.setCoordinates(22, 34);
    return temp;   // 3. copy constructor is called
}

int main()
{
    Point ptr(10, 15); // 1. overloaded constructor is called
    cout << "Before calling createFunction." << endl;
    ptr.displayCoordinates(); //(10, 15)

    ptr = createAfunction();
    cout << "After calling createFunction." << endl;
    ptr.displayCoordinates();
    cout << "Back in main function" << endl;

    return 0;
}