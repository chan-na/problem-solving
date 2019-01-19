#include <cstdio>
#include <cstring>

#define MAX 1001

int order[MAX];

int main(void)
{
    int N;
    while (scanf("%d", &N), N != 0)
    {
        memset(order, 0, MAX);

        while (scanf("%d", &order[0]), order[0] != 0)
        {
            for (int i = 1; i < N; i++)
            {
                scanf("%d", &order[i]);
            }

            bool isPossible = true;
            int next;
            for (int i = 0; i < N - 1; i++)
            {
                next = order[i];
                for (int j = i + 1; j < N; j++)
                {
                    if (order[j] < order[i])
                    {
                        if (order[j] < next)
                        {
                            next = order[j];
                        }
                        else
                        {
                            isPossible = false;
                            goto FOR_END;
                        }
                    }
                }
            }

        FOR_END:
            if (isPossible)
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }

        putchar('\n');
    }

    return 0;
}