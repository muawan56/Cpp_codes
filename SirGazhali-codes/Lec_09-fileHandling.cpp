#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
    int xCoordinate;
    int yCoordinate;

public:
    Point() : xCoordinate(0), yCoordinate(0)
    {
        cout << "Default constructor is called!" << xCoordinate << " " << yCoordinate << endl;
    }

    Point(int c1, int c2) : xCoordinate(c1), yCoordinate(c2)
    {
        cout << "Overloaded constructor is called!" << endl;
    }

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

    void displayCoordinates() const
    {
        cout << "Coordinates are (" << getX() << ", " << getY() << ")" << endl;
    }

    void setCoordinates(int x, int y)
    {
        setX(x);
        setY(y);
    }
    void writeToFile(ofstream &) const;
    void readToFile(ifstream &);
    // Destructor
    ~Point()
    {
        cout << "Destructor is called on " << xCoordinate << " " << yCoordinate << endl;
    }
};

// IMPLEMENTATION
void Point::writeToFile(ofstream &fileout) const
{
    // fileout << xCoordinate << " " << yCoordinate << endl;
    fileout << getX() << " " << getY() << endl;
}

void Point::readToFile(ifstream &filein)
{
    // filein >> xCoordinate >> yCoordinate;
    int r1, r2;
    filein >> r1 >> r2;
    setX(r1);
    setY(r2);
}

int main()
{
    int num;
    cout << "Points you want to create: ";
    cin >> num;

    Point *ptr = new Point[num];

    int x, y;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter coordinates for point " << i + 1 << " :";
        cin >> x;
        cin.ignore(); // it will ignore comma above
        cin >> y;
        ptr[i].setCoordinates(x, y);
    }

    for (int i = 0; i < num; i++)
    {
        ptr[i].displayCoordinates();
    }

    // once data has displayed on screen we will write in file
    // METHOD 1
    cout << endl
         << "Writing data in 'point.txt'" << endl;
    ofstream fout;
    fout.open("point.txt");
    if (!fout)
        cout << "ERROR: file not found";
    else
    {
        fout << num << endl;
        for (int i = 0; i < num; i++)
        {
            // int c1 = ptr[i].getX();
            // int c2 = ptr[i].getY();

            // fout << c1 << " " << c2 << endl;

            // METHOD 2

            ptr[i].writeToFile(fout); // fout is handle of out file declared above
        }
        fout.close();
    }

    delete[] ptr;
    ptr = nullptr;

    // READ file data
    cout << endl
         << "Reading data form 'point.text'" << endl;
    ifstream finput;
    finput.open("point.txt");
    if (!finput)
    {
        cout << "ERROR: can't read file";
    }
    else
    {
        int pointNum;
        finput >> pointNum;
        Point *point = new Point[pointNum];
        int x, y;
        for (int i = 0; i < pointNum; i++)
        {
            // finput >> x >> y;
            // point[i].setX(x);
            // point[i].setY(y);
            // point[i].displayCoordinates();
            point[i].readToFile(finput);
            point[i].displayCoordinates();
        }
        finput.close();

        delete[] point;
        point = nullptr;
    }

    return 0;
}