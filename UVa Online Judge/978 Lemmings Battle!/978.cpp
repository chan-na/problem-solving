#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int Min(int a, int b, int c)
{
    int min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    return min;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> winner;
    priority_queue<int> greenArmy;
    priority_queue<int> blueArmy;

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int battleFieldNum, greenNum, blueNum;
        cin >> battleFieldNum >> greenNum >> blueNum;

        int power;
        while (greenNum--)
        {
            cin >> power;
            greenArmy.push(power);
        }
        while (blueNum--)
        {
            cin >> power;
            blueArmy.push(power);
        }

        while (!greenArmy.empty() && !blueArmy.empty())
        {
            winner.clear();

            int available = Min(battleFieldNum, greenArmy.size(), blueArmy.size());
            int fight;
            for (int i = 0; i < available; ++i)
            {
                fight = greenArmy.top() - blueArmy.top();
                greenArmy.pop();
                blueArmy.pop();
                if (fight != 0)
                {
                    winner.push_back(fight);
                }
            }

            for (int i = 0; i < winner.size(); ++i)
            {
                if (winner[i] < 0)
                {
                    blueArmy.push(-winner[i]);
                }
                else
                {
                    greenArmy.push(winner[i]);
                }
            }
        }

        if (greenArmy.empty() && blueArmy.empty())
        {
            cout << "green and blue died\n";
        }
        else if (greenArmy.empty())
        {
            cout << "blue wins\n";
            const int SIZE = blueArmy.size();
            for (int i = 0; i < SIZE; ++i)
            {
                cout << blueArmy.top() << '\n';
                blueArmy.pop();
            }
        }
        else
        {
            cout << "green wins\n";
            const int SIZE = greenArmy.size();
            for (int i = 0; i < SIZE; ++i)
            {
                cout << greenArmy.top() << '\n';
                greenArmy.pop();
            }
        }

        if (testCase != 0)
        {
            cout << '\n';
        }
    }

    return 0;
}