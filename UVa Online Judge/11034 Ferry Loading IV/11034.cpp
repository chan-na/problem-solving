#include <iostream>
#include <string>
#include <deque>
using namespace std;

const int LEFT_BANK = 1;
const int RIGHT_BANK = 2;

int main(void)
{
    deque<int> leftBankQueue;
    deque<int> rightBankQueue;

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        leftBankQueue.clear();
        rightBankQueue.clear();

        int ferryLength, numOfCars;
        cin >> ferryLength >> numOfCars;
        ferryLength *= 100; // m -> cm

        int carLength;
        string arriavalBank;
        while (numOfCars--)
        {
            cin >> carLength >> arriavalBank;
            if (arriavalBank == "left")
            {
                leftBankQueue.push_back(carLength);
            }
            else
            {
                rightBankQueue.push_back(carLength);
            }
        }

        int currentBank = LEFT_BANK;
        int loadedLength = 0;
        int crossCount = 0;
        while (!leftBankQueue.empty() || !rightBankQueue.empty())
        {
            if (currentBank == LEFT_BANK)
            {
                while (!leftBankQueue.empty() && ((ferryLength - loadedLength) >= leftBankQueue.front()))
                {
                    loadedLength += leftBankQueue.front();
                    leftBankQueue.pop_front();
                }
                currentBank = RIGHT_BANK;
                ++crossCount;
                loadedLength = 0;
            }
            else
            {
                while (!rightBankQueue.empty() && ((ferryLength - loadedLength) >= rightBankQueue.front()))
                {
                    loadedLength += rightBankQueue.front();
                    rightBankQueue.pop_front();
                }
                currentBank = LEFT_BANK;
                ++crossCount;
                loadedLength = 0;
            }
        }

        cout << crossCount << '\n';
    }
}