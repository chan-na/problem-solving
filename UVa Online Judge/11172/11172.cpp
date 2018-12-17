#include <cstdio>

int main(void)
{
    int tc, a, b, ans;
    scanf("%d", &tc);

    while (tc--)
    {
        scanf("%d %d", &a, &b);
        ans = a > b ? '>' : (a < b ? '<' : '=');
        printf("%c\n", ans);
    }
    return 0;
}