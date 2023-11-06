#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Group35
{
private:
    int type; // 0 for 3 integers, 1 for 5 integers
    int values[5];

    // Private helper function to set values according to rules
    void setValuesFive(int v1, int v2, int v3, int v4, int v5)
    {
        values[0] = max(v1, v5);
        values[2] = (v1 + v2) / 2;
        values[1] = max(values[0], values[2]);
        values[4] = max(v3, v5);
        values[3] = v3 + v4 + values[4];
    }

    void setValuesThree(int v1, int v2, int v3)
    {
        values[0] = max(v1, 0); // For a 3-integer object, the last two values are 0.
        values[2] = (v1 + v2) / 2;
        values[1] = max(values[0], values[2]);
        values[4] = 0;
        values[3] = 0;
    }

public:
    // Non-parameterized constructor
    Group35()
    {
        // Generate a random number (0 or 1) to decide the object type
        type = rand() % 2;

        // Initialize values randomly within an integer range (e.g., 1 to 100)
        for (int i = 0; i < 5; i++)
        {
            values[i] = rand() % 100 + 1;
        }

        // Set values according to the rules
        if (type == 0)
        {
            setValuesThree(values[0], values[1], values[2]);
        }
        else
        {
            setValuesFive(values[0], values[1], values[2], values[3], values[4]);
        }
    }

    // Setter function for 3 integers
    void setValues(int v1, int v2, int v3)
    {
        type = 0;
        setValuesThree(v1, v2, v3);
    }

    // Setter function for 5 integers
    void setValues(int v1, int v2, int v3, int v4, int v5)
    {
        type = 1;
        setValuesFive(v1, v2, v3, v4, v5);
    }

    // Overload the stream operator to print objects
    friend ostream &operator<<(ostream &os, const Group35 &obj)
    {
        os << "<";
        for (int i = 0; i < 5; i++)
        {
            os << obj.values[i];
            if (i < 4)
            {
                os << ", ";
            }
        }
        os << ">";
        return os;
    }

    // Mutate function to either reduce or grow the object
    void mutate()
    {
        if (type == 0)
        {
            // Reduce from 3 to 5 integers
            setValuesFive(values[0], values[1], values[2], values[2], values[2]);
            type = 1;
        }
        else
        {
            // Grow from 5 to 3 integers
            setValuesThree(values[0], values[1], (values[2] + values[3]) / 2);
            type = 0;
        }
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0))); // Fixed the typo: Added the missing parenthesis

    // Create an array of five Group35 objects
    Group35 objects[5];

    // Print all objects
    for (int i = 0; i < 5; i++)
    {
        cout << "Object " << i + 1 << ": " << objects[i] << endl;
    }

    // Perform three iterations with mutations
    for (int iteration = 1; iteration <= 3; iteration++)
    {
        cout << "Iteration " << iteration << ":" << endl;
        for (int i = 0; i < 5; i++)
        {
            // Generate a random number (0 or 1) to decide whether to mutate or not
            int mutateDecision = rand() % 2;
            if (mutateDecision == 1)
            {
                objects[i].mutate();
            }
            cout << "Object " << i + 1 << ": " << objects[i] << endl;
        }
        cout << "---------------------------" << endl;
    }

    return 0;
}
