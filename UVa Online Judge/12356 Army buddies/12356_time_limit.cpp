#include <cstdio>

int main(void)
{
    int S, B, L, R, left, right;
    bool isAlive[100005];

    while (scanf("%d %d", &S, &B), S != 0)
    {
        for (int i = 1; i <= S; i++)
            isAlive[i] = true;

        while (B--)
        {
            scanf("%d %d", &L, &R);
            left = right = -1;

            for (int i = L; i <= R; i++)
            {
                isAlive[i] = false;
            }

            for (int i = L - 1; i > 0; i--)
            {
                if (isAlive[i] == true)
                {
                    left = i;
                    break;
                }
            }

            for (int i = R + 1; i <= S; i++)
            {
                if (isAlive[i] == true)
                {
                    right = i;
                    break;
                }
            }

            if (left == -1 && right == -1)
                printf("* *\n");
            else if (left == -1)
                printf("* %d\n", right);
            else if (right == -1)
                printf("%d *\n", left);
            else
                printf("%d %d\n", left, right);
        }
        printf("-\n");
    }
}