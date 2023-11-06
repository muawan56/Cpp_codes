#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
    int xCoordinate;
    int yCoordinate;
    int *p;

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
    p = new int;
    *p = 0;
    cout << "Default constructor is called!" << xCoordinate << " " << yCoordinate << endl;
}

// Overloaded constructor
Point::Point(int c1, int c2) : xCoordinate(c1), yCoordinate(c2)
{
    p = new int;
    *p = c2;
    cout << "Overloaded constructor is called!" << endl;
}

// Copy constructor
Point::Point(const Point &original) // temp is sent by reference here in parameter(original) here original is ptr;
{
    cout << "COPY constructor called" << endl;
    xCoordinate = original.xCoordinate; // do this in member initializer list as well
    yCoordinate = original.yCoordinate;
    p = new int;
    *p = *(original.p); // Deep copy
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

// pass object by VALUE
void display(Point temp) // temp is a copy of ptr that is created by COPY CONSTRUCTOR
                        // display is not member func of class Point
{
    temp.displayCoordinates();
    cout << "Address of temp is " << &temp << endl;
}

int main()
{
    Point ptr(10, 15);
    cout << "Address of ptr is " << &ptr << endl;
    display(ptr);

    cout << "Back in main function" << endl;

    return 0;
}