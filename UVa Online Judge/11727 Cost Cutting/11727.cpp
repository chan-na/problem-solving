#include <cstdio>

int calculateMiddle(int s1, int s2, int s3)
{
    if (s1 < s2)
    {
        if (s1 < s3)
            return s2 < s3 ? s2 : s3;
        else
            return s1;
    }
    else
    {
        if (s2 < s3)
            return s1 < s3 ? s1 : s3;
        else
            return s2;
    }
}

int main(void)
{
    int tc, s1, s2, s3, c = 1;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d %d %d", &s1, &s2, &s3);
        printf("Case %d: %d\n", c++, calculateMiddle(s1, s2, s3));
    }
    return 0;
}