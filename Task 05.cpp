#include <iostream>
using namespace std;

#define SIZE 6

class CircularQueue
{
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int id)
    {
        if (count == SIZE)
        {
            cout << "Queue is full! Passenger " << id
                 << " cannot enter." << endl;
            return;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = id;
        count++;
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Boarded passenger: " << arr[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void display()
    {
        cout << "\nRemaining passengers in boarding order: ";

        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % SIZE] << " ";
        }

        cout << "\nFront position: " << front;
        cout << "\nRear position: " << rear << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    q.dequeue();
    q.dequeue();

    q.enqueue(110);

    q.dequeue();

    q.enqueue(111);
    q.enqueue(112);

    q.display();

    return 0;
}

