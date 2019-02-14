#include <iostream>
#include <queue>
#include <stack>
using namespace std;

enum
{
    STACK,
    QUEUE,
    PRIORITY_QUEUE,
    COUNT
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n, !cin.eof())
    {
        int isPossible[COUNT];
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        for (int i = 0; i < COUNT; ++i)
        {
            isPossible[i] = 1;
        }

        int command, num;
        while (n--)
        {
            cin >> command >> num;

            if (isPossible[STACK])
            {
                if (command == 1)
                {
                    s.push(num);
                }
                else
                {
                    if (num == s.top())
                    {
                        s.pop();
                    }
                    else
                    {
                        isPossible[STACK] = 0;
                    }
                }
            }

            if (isPossible[QUEUE])
            {
                if (command == 1)
                {
                    q.push(num);
                }
                else
                {
                    if (num == q.front())
                    {
                        q.pop();
                    }
                    else
                    {
                        isPossible[QUEUE] = 0;
                    }
                }
            }

            if (isPossible[PRIORITY_QUEUE])
            {
                if (command == 1)
                {
                    pq.push(num);
                }
                else
                {
                    if (num == pq.top())
                    {
                        pq.pop();
                    }
                    else
                    {
                        isPossible[PRIORITY_QUEUE] = 0;
                    }
                }
            }
        }

        int sum = isPossible[STACK] + isPossible[QUEUE] + isPossible[PRIORITY_QUEUE];

        if (sum == 3 || sum == 2)
        {
            cout << "not sure\n";
        }
        else if (sum == 0)
        {
            cout << "impossible\n";
        }
        else
        {
            if (isPossible[STACK])
            {
                cout << "stack\n";
            }
            else if (isPossible[QUEUE])
            {
                cout << "queue\n";
            }
            else
            {
                cout << "priority queue\n";
            }
        }
    }
}
