#include <cstdio>

int main(void)
{
    int K, M, N, X, Y;
    while (scanf("%d", &K), K != 0)
    {
        scanf("%d %d", &M, &N);
        while (K--)
        {
            scanf("%d %d", &X, &Y);
            if (X == M || Y == N)
            {
                printf("divisa\n");
            }
            else
            {
                if (X < M && Y > N)
                    printf("NO\n");
                else if (X > M && Y > N)
                    printf("NE\n");
                else if (X > M && Y < N)
                    printf("SE\n");
                else
                    printf("SO\n");
            }
        }
    }
    return 0;
}