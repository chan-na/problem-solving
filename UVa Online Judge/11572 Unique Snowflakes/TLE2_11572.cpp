#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
    vector<int> snowflakes;
    snowflakes.reserve(10000000);

    unordered_map<int, int> occurrence;
    occurrence.reserve(100000);

    int testCase;
    scanf("%d", &testCase);
    while (testCase--)
    {
        snowflakes.clear();

        int numOfSnowflakes;
        scanf("%d", &numOfSnowflakes);

        int snowflake;
        for (int i = 0; i < numOfSnowflakes; ++i)
        {
            scanf("%d", &snowflake);
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
        printf("%d\n", maxPackage);
    }

    return 0;
}