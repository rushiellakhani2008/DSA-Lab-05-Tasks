#include <iostream>
using namespace std;
#define SIZE 8

class Stack
{
    int arr[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == SIZE - 1)
        {
            cout << "Stack is full!" << endl;
            return;
        }

        arr[++top] = value;
        displayTop();
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Undo failed! Stack is empty." << endl;
            displayTop();
            return;
        }

        cout << "Undo operation: " << arr[top] << endl;
        top--;
        displayTop();
    }

    void displayTop()
    {
        if (top == -1)
            cout << "Current top: Stack is empty" << endl;
        else
            cout << "Current top: " << arr[top] << endl;
    }

    void displayStack()
    {
        cout << "\nRemaining operations (top to bottom): ";

        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    Stack s;

    cout << "Adding operations:" << endl;
    s.push(12);
    s.push(25);
    s.push(17);
    s.push(31);
    s.push(44);
    s.push(19);

    cout << "\nUndo three times:" << endl;
    s.pop();
    s.pop();
    s.pop();

    cout << "\nPerform new operation 52:" << endl;
    s.push(52);

    cout << "\nUndo twice:" << endl;
    s.pop();
    s.pop();

    cout << "\nFinal stack:" << endl;
    s.displayStack();

    return 0;
}

