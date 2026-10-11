#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<string> &q, int k)
{
    stack<string> s;
    int n = q.size();

    if (k < 0 || k > n)
        return;

    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<string> q;

    q.push("J1");
    q.push("J2");
    q.push("J3");
    q.push("J4");
    q.push("J5");
    q.push("J6");
    q.push("J7");

    reverseFirstK(q, 3);

    cout << "Queue after reversing first 3 jobs: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

