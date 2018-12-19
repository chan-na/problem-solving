#include <cstdio>
#include <cmath>

int main(void)
{
    int n, seq[3001], diff;
    bool check[3001], isJolly;

    while (scanf("%d", &n) == 1)
    {
        // initialize
        isJolly = true;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", seq + i);
            check[i] = false;
        }

        // calculate diff
        for (int i = 0; i < n - 1; i++)
        {
            diff = abs(seq[i] - seq[i + 1]);
            if (diff == 0 || diff > n - 1)
            {
                isJolly = false;
                break;
            }

            if (check[diff] == true)
            {
                isJolly = false;
                break;
            }
            else
            {
                check[diff] = true;
            }
        }

        if (isJolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}