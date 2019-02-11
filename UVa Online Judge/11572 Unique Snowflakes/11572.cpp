#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
    vector<int> snowflakes;
    unordered_map<int, int> occurrence;

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
                auto it = occurrence.find(snowflakes[j]);
                if (it == occurrence.end())
                {
                    occurrence[snowflakes[j]] = j;
                    ++currentPackage;
                    if (currentPackage > maxPackage)
                    {
                        maxPackage = currentPackage;
                    }
                }
                else
                {
                    i = occurrence[snowflakes[j]];
                    break;
                }
            }
        }
        printf("%d\n", maxPackage);
    }

    return 0;
}