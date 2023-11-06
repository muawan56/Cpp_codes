// Task_02
// Muhammad Umar Awan - ROLL no: BSEF22M502

#include <iostream>
#include <queue>

using namespace std;

class Patient
{
private:
    static int turn;
    int timeRequired;

public:
    Patient(int time = 0) : timeRequired(time) {}

    friend ostream &operator<<(ostream &os, const Patient &patient)
    {
        os << "Patient " << Patient::turn << " (" << patient.timeRequired << " minutes)";
        return os;
    }

    int getTimeRequired() const
    {
        return timeRequired;
    }

    int getTurn() const
    {
        return turn;
    }

    void serve(int &remainingTime)
    {
        if (remainingTime <= 5)
        {
            cout << *this << " in service" << endl;
            remainingTime -= timeRequired;
        }
        else
        {
            cout << *this << " in service for 5 minutes" << endl;
            remainingTime -= 5;
        }
        turn++;
    }
};

int Patient::turn = 1;

template <typename T>
class Queue
{
private:
    queue<T> data;

public:
    void enqueue(const T &item)
    {
        data.push(item);
    }

    void dequeue()
    {
        data.pop();
    }

    T seeFirst()
    {
        return data.front();
    }

    bool isEmpty()
    {
        return data.empty();
    }
};

int main()
{
    Queue<Patient> patientQueue;

    // Enqueue 6 patients with different time requirements
    patientQueue.enqueue(Patient(4));
    patientQueue.enqueue(Patient(3));
    patientQueue.enqueue(Patient(6));
    patientQueue.enqueue(Patient(2));
    patientQueue.enqueue(Patient(8));
    patientQueue.enqueue(Patient(4));

    int remainingTime = 5; // Initial time for service

    cout << endl
         << "Queue: 4 3 6 2 8 4" << endl;
    while (!patientQueue.isEmpty())
    {
        Patient patient = patientQueue.seeFirst();
        patient.serve(remainingTime);
        if (patient.getTimeRequired() > 5)
        {
            patientQueue.enqueue(Patient(patient.getTimeRequired() - 5));
        }
        patientQueue.dequeue();
    }

    return 0;
}
