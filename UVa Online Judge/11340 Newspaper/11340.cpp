#include <cstdio>

int main(void)
{
    int tc, K, M, value, values[256];
    char c, str[10005];
    long long int total;

    scanf("%d", &tc);
    while (tc--)
    {
        total = 0;
        for (int i = 0; i < 256; i++)
            values[i] = 0;

        scanf("%d", &K);
        while (K--)
        {
            scanf(" %c %d", &c, &value);
            values[c + 128] = value;
        }

        scanf("%d ", &M);
        while (M--)
        {
            fgets(str, sizeof(str), stdin);
            for (int i = 0; i < sizeof(str); i++)
            {
                if (str[i] == '\0')
                    break;
                total += values[str[i] + 128];
            }
        }

        printf("%lld.%02lld$\n", total / 100, total % 100);
    }
    return 0;
}