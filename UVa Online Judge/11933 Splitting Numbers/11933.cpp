#include <cstdio>

int main(void)
{
    int n, a, b, isOdd;
    while (scanf("%d", &n), n != 0)
    {
        a = 0;
        b = 0;
        isOdd = 1;
        for (int i = 0; i < 31; i++)
        {
            if (n & (1 << i))
            {
                if (isOdd)
                {
                    a = a | (1 << i);
                    isOdd = 0;
                }
                else
                {
                    b = b | (1 << i);
                    isOdd = 1;
                }
            }
        }

        printf("%d %d\n", a, b);
    }

    return 0;
}