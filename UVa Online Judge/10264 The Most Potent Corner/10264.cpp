#include <cstdio>
#include <cstring>

#define CORNER_MAX (1 << 14)

int weights[CORNER_MAX];
int potencies[CORNER_MAX];

int main(void)
{
    int N;
    while (scanf("%d", &N) == 1)
    {
        memset(weights, 0, CORNER_MAX);
        memset(potencies, 0, CORNER_MAX);

        for (int i = 0; i < 1 << N; i++)
        {
            scanf("%d", &weights[i]);
        }

        for (int i = 0; i < 1 << N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                potencies[i] += weights[i ^ (1 << j)];
            }
        }

        int max = 0;
        for (int i = 0; i < 1 << N; i++)
        {
            int neigbour_max = 0;
            for (int j = 0; j < N; j++)
            {
                int potency = potencies[i ^ (1 << j)];
                if (potency > neigbour_max)
                {
                    neigbour_max = potency;
                }
            }

            if (potencies[i] + neigbour_max > max)
            {
                max = potencies[i] + neigbour_max;
            }
        }

        printf("%d\n", max);
    }

    return 0;
}