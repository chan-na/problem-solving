#include <cstdio>
#include <cstring>

#define MAX 1000001

char memo[MAX];

int main(void)
{
    int n, m;
    while (scanf("%d%d", &n, &m), !(n == 0 && m == 0))
    {
        memset(memo, 0, MAX);

        int start, end, interval;
        int isConflict = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &start, &end);
            if (!isConflict)
            {
                for (int j = start; j < end; j++)
                {
                    if (memo[j] != 0)
                    {
                        isConflict = true;
                        break;
                    }
                    else
                    {
                        memo[j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &start, &end, &interval);
            if (!isConflict)
            {
                while (start < MAX)
                {
                    for (int j = start; j < end && j < MAX; j++)
                    {
                        if (memo[j] != 0)
                        {
                            isConflict = true;
                            break;
                        }
                        else
                        {
                            memo[j] = 1;
                        }
                    }
                    start += interval;
                    end += interval;

                    if (isConflict)
                    {
                        break;
                    }
                }
            }
        }

        if (isConflict)
        {
            puts("CONFLICT");
        }
        else
        {
            puts("NO CONFLICT");
        }
    }

    return 0;
}