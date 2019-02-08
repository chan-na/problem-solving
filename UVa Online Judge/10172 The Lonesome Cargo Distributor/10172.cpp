#include <iostream>
#include <deque>
using namespace std;

deque<int> carrier;
deque<int> platforms[101];

bool isFinish(int numOfStations)
{
    for (int i = 1; i <= numOfStations; ++i)
    {
        if (!platforms[i].empty())
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int numOfStations, carrierCapacity, platformCapacity;
        cin >> numOfStations >> carrierCapacity >> platformCapacity;

        carrier.clear();
        for (int i = 1; i <= numOfStations; ++i)
        {
            platforms[i].clear();
        }

        int numOfCargoes, cargo;
        for (int i = 1; i <= numOfStations; ++i)
        {
            cin >> numOfCargoes;
            while (numOfCargoes--)
            {
                cin >> cargo;
                platforms[i].push_back(cargo);
            }
        }

        int workingTime = 0;
        int currentStation = 1;
        while (true)
        {
            while (!carrier.empty())
            {
                if (carrier.back() == currentStation)
                {
                    carrier.pop_back();
                    workingTime += 1;
                }
                else if (platforms[currentStation].size() != platformCapacity)
                {
                    platforms[currentStation].push_back(carrier.back());
                    carrier.pop_back();
                    workingTime += 1;
                }
                else
                {
                    break;
                }
            }

            while (!platforms[currentStation].empty() && (carrier.size() != carrierCapacity))
            {
                carrier.push_back(platforms[currentStation].front());
                platforms[currentStation].pop_front();
                workingTime += 1;
            }

            if (carrier.empty() && isFinish(numOfStations))
            {
                break;
            }

            if (currentStation == numOfStations)
            {
                currentStation = 1;
            }
            else
            {
                ++currentStation;
            }
            workingTime += 2;
        }

        cout << workingTime << '\n';
    }

    return 0;
}