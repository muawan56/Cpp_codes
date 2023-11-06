// Task_01
// Muhammad Umar Awan - ROLL no: BSEF22M502

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Queue
{
private:
    T *data;      // Dynamic array to store queue elements
    int front;    // Index of the front of the queue
    int rear;     // Index of the rear of the queue
    int capacity; // Capacity of the queue
    int size;     // Number of elements in the queue

    // Private member function to increase the capacity of the queue
    void increaseCapacity()
    {
        int newCapacity = capacity * 2;
        T *newData = new T[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[(front + i) % capacity];
        }

        delete[] data;
        data = newData;
        front = 0;
        rear = size;
        capacity = newCapacity;
    }

public:
    // Parameterized constructor with default values
    Queue(int initialCapacity = 10)
    {
        capacity = initialCapacity;
        data = new T[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // Destructor to free memory
    ~Queue()
    {
        delete[] data;
    }

    // Enqueue: Add an element to the rear of the queue
    void enqueue(T element)
    {
        if (size == capacity)
        {
            increaseCapacity();
        }

        data[rear] = element;
        rear = (rear + 1) % capacity;
        size++;
    }

    // Dequeue: Remove an element from the front of the queue
    void dequeue()
    {
        if (size > 0)
        {
            front = (front + 1) % capacity;
            size--;
        }
    }

    // SeeFirst: Return the first element without removal
    T seeFirst() const
    {
        if (size > 0)
        {
            return data[front];
        }
        else
        {
            throw std::out_of_range("Queue is empty.");
        }
    }
};

int main()
{
    // Demonstrating the Queue class with different data types
    Queue<int> intQueue;
    Queue<float> floatQueue;
    Queue<string> stringQueue;

    // Enqueue some elements
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    floatQueue.enqueue(3.14);
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");

    // Display the first elements
    cout << "First element in intQueue: " << intQueue.seeFirst() << endl;
    cout << "First element in floatQueue: " << floatQueue.seeFirst() << endl;
    cout << "First element in stringQueue: " << stringQueue.seeFirst() << endl;

    // Dequeue elements
    intQueue.dequeue();
    floatQueue.dequeue();
    stringQueue.dequeue();

    // Display the new first elements
    cout << "First element in intQueue after dequeue: " << intQueue.seeFirst() << endl;
    cout << "First element in floatQueue after dequeue: " << floatQueue.seeFirst() << endl;
    cout << "First element in stringQueue after dequeue: " << stringQueue.seeFirst() << endl;

    return 0;
}
