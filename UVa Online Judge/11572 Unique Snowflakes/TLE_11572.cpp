#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> snowflakes;
    snowflakes.reserve(1000000);

    unordered_map<int, int> occurrence;
    occurrence.reserve(100000);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        snowflakes.clear();

        int numOfSnowflakes;
        cin >> numOfSnowflakes;

        int snowflake;
        for (int i = 0; i < numOfSnowflakes; ++i)
        {
            cin >> snowflake;
            snowflakes.push_back(snowflake);
        }

        int maxPackage = 0;
        for (int i = 0; i < numOfSnowflakes - maxPackage; ++i)
        {
            int currentPackage = 0;
            occurrence.clear();

            for (int j = i; j < numOfSnowflakes; ++j)
            {
                if (++occurrence[snowflakes[j]] == 1)
                {
                    ++currentPackage;
                    if (currentPackage > maxPackage)
                    {
                        maxPackage = currentPackage;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        cout << maxPackage << '\n';
    }

    return 0;
}