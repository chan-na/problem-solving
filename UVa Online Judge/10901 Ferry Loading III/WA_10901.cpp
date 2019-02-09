#include <iostream>
#include <string>
#include <deque>
using namespace std;

const int LEFT_BANK = 1;
const int RIGHT_BANK = 2;

int main(void)
{
    deque<int> ferry;
    deque<int> leftBankCars;
    deque<int> rightBankCars;

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        ferry.clear();
        leftBankCars.clear();
        rightBankCars.clear();

        int ferryCapacity, crossTime, numOfCars;
        cin >> ferryCapacity >> crossTime >> numOfCars;

        int arrivalTime;
        string arrivalBank;
        while (numOfCars--)
        {
            cin >> arrivalTime >> arrivalBank;
            if (arrivalBank == "left")
            {
                leftBankCars.push_back(arrivalTime);
            }
            else
            {
                rightBankCars.push_back(arrivalTime);
            }
        }

        int currentState = LEFT_BANK;
        int currentTime = 0;
        while (true)
        {
            while (!ferry.empty())
            {
                ferry.pop_front();
                cout << currentTime << '\n';
            }

            if (leftBankCars.empty() && rightBankCars.empty())
            {
                break;
            }

            if (currentState == LEFT_BANK)
            {
                if (!leftBankCars.empty() && leftBankCars.front() <= currentTime)
                {
                    while (leftBankCars.front() <= currentTime && ferry.size() < ferryCapacity)
                    {
                        ferry.push_back(leftBankCars.front());
                        leftBankCars.pop_front();
                        if (leftBankCars.empty())
                        {
                            break;
                        }
                    }
                    currentTime += crossTime;
                    currentState = RIGHT_BANK;
                }
                else if (!rightBankCars.empty() && rightBankCars.front() <= currentTime)
                {
                    currentTime += crossTime;
                    currentState = RIGHT_BANK;
                }
                else
                {
                    if (!leftBankCars.empty() && rightBankCars.empty())
                    {
                        currentTime = leftBankCars.front();
                    }
                    else if (leftBankCars.empty() && !rightBankCars.empty())
                    {
                        currentTime = rightBankCars.front();
                    }
                    else
                    {
                        currentTime = leftBankCars.front() < rightBankCars.front() ? leftBankCars.front() : rightBankCars.front();
                    }
                }
            }
            else
            {
                if (!rightBankCars.empty() && rightBankCars.front() <= currentTime)
                {
                    while (rightBankCars.front() <= currentTime && ferry.size() < ferryCapacity)
                    {
                        ferry.push_back(rightBankCars.front());
                        rightBankCars.pop_front();
                        if (rightBankCars.empty())
                        {
                            break;
                        }
                    }
                    currentTime += crossTime;
                    currentState = LEFT_BANK;
                }
                else if (!leftBankCars.empty() && leftBankCars.front() <= currentTime)
                {
                    currentTime += crossTime;
                    currentState = LEFT_BANK;
                }
                else
                {
                    if (!leftBankCars.empty() && rightBankCars.empty())
                    {
                        currentTime = leftBankCars.front();
                    }
                    else if (leftBankCars.empty() && !rightBankCars.empty())
                    {
                        currentTime = rightBankCars.front();
                    }
                    else
                    {
                        currentTime = leftBankCars.front() < rightBankCars.front() ? leftBankCars.front() : rightBankCars.front();
                    }
                }
            }
        }
        if (testCase != 0)
        {
            cout << '\n';
        }
    }
}