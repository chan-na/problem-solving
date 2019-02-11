#include <iostream>
#include <set>
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
    multiset<int> greenArmy;
    multiset<int> blueArmy;

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
            greenArmy.insert(power);
        }
        while (blueNum--)
        {
            cin >> power;
            blueArmy.insert(power);
        }

        while (!greenArmy.empty() && !blueArmy.empty())
        {
            winner.clear();

            int available = Min(battleFieldNum, greenArmy.size(), blueArmy.size());
            int fight;
            auto greenIt = greenArmy.end();
            --greenIt;
            auto blueIt = blueArmy.end();
            --blueIt;
            for (int i = 0; i < available; ++i)
            {
                fight = *greenIt - *blueIt;
                greenArmy.erase(greenIt--);
                blueArmy.erase(blueIt--);
                if (fight != 0)
                {
                    winner.push_back(fight);
                }
            }

            for (int i = 0; i < winner.size(); ++i)
            {
                if (winner[i] < 0)
                {
                    blueArmy.insert(-winner[i]);
                }
                else
                {
                    greenArmy.insert(winner[i]);
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
            for (auto it = blueArmy.rbegin(); it != blueArmy.rend(); ++it)
            {
                cout << *it << '\n';
            }
            blueArmy.clear();
        }
        else
        {
            cout << "green wins\n";
            const int SIZE = greenArmy.size();
            for (auto it = greenArmy.rbegin(); it != greenArmy.rend(); ++it)
            {
                cout << *it << '\n';
            }
            greenArmy.clear();
        }

        if (testCase != 0)
        {
            cout << '\n';
        }
    }

    return 0;
}