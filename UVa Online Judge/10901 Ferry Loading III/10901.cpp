#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

struct Car
{
    Car(int a, int b, int n)
        : arrivalTime(a), bank(b), num(n)
    {
    }
    int arrivalTime;
    int bank;
    int num;
};

const int LEFT_BANK = 1;
const int RIGHT_BANK = 2;

int main(void)
{
    deque<Car> ferry;
    deque<Car> carQueue;
    deque<Car> letfBankQueue;
    deque<Car> rightBankQueue;
    vector<int> result;
    result.reserve(10001);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        ferry.clear();
        carQueue.clear();
        letfBankQueue.clear();
        rightBankQueue.clear();
        result.clear();

        int ferryCapacity, crossTime, numOfCars;
        cin >> ferryCapacity >> crossTime >> numOfCars;

        int arrivalTime;
        string arrivalBank;
        for (int i = 0; i < numOfCars; ++i)
        {
            cin >> arrivalTime >> arrivalBank;
            if (arrivalBank == "left")
            {
                carQueue.push_back(Car(arrivalTime, LEFT_BANK, i));
            }
            else
            {
                carQueue.push_back(Car(arrivalTime, RIGHT_BANK, i));
            }
        }

        int currentTime = 0;
        int currentBank = LEFT_BANK;
        while (true)
        {
            while (!ferry.empty())
            {
                result[ferry.front().num] = currentTime;
                ferry.pop_front();
            }

            while (!carQueue.empty() && carQueue.front().arrivalTime <= currentTime)
            {
                if (carQueue.front().bank == LEFT_BANK)
                {
                    letfBankQueue.push_back(carQueue.front());
                }
                else
                {
                    rightBankQueue.push_back(carQueue.front());
                }
                carQueue.pop_front();
            }

            if (currentBank == LEFT_BANK)
            {
                while (!letfBankQueue.empty() && ferry.size() < ferryCapacity)
                {
                    ferry.push_back(letfBankQueue.front());
                    letfBankQueue.pop_front();
                }
            }
            else
            {
                while (!rightBankQueue.empty() && ferry.size() < ferryCapacity)
                {
                    ferry.push_back(rightBankQueue.front());
                    rightBankQueue.pop_front();
                }
            }

            if (ferry.empty())
            {
                if (currentBank == LEFT_BANK)
                {
                    if (rightBankQueue.empty())
                    {
                        if (carQueue.empty())
                        {
                            break;
                        }
                        else
                        {
                            currentTime = carQueue.front().arrivalTime;
                            continue;
                        }
                    }
                }
                else
                {
                    if (letfBankQueue.empty())
                    {
                        if (carQueue.empty())
                        {
                            break;
                        }
                        else
                        {
                            currentTime = carQueue.front().arrivalTime;
                            continue;
                        }
                    }
                }
            }

            currentTime += crossTime;
            currentBank = currentBank == LEFT_BANK ? RIGHT_BANK : LEFT_BANK;
        }

        for (int i = 0; i < numOfCars; ++i)
        {
            cout << result[i] << '\n';
        }

        if (testCase != 0)
        {
            cout << '\n';
        }
    }
}