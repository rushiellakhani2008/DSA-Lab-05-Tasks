#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    stack<char> incoming;
    stack<char> outgoing;

public:
    void enqueue(char item)
    {
        incoming.push(item);
    }

    char dequeue()
    {
        if (outgoing.empty())
        {
            while (!incoming.empty())
            {
                outgoing.push(incoming.top());
                incoming.pop();
            }
        }

        if (outgoing.empty())
        {
            cout << "Queue is empty!" << endl;
            return '\0';
        }

        char item = outgoing.top();
        outgoing.pop();

        return item;
    }
};

int main()
{
    MyQueue q;

    q.enqueue('A');
    q.enqueue('B');

    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue('C');

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}

