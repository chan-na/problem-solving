#include <cstdio>
#include <cstring>

int f[512];
int check[512];

int TransformGridForm(int (*g)[3])
{
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (g[i][j] == 1)
                result |= (1 << ((i * 3) + j));
        }
    }
    return result;
}

int CalculateF(int g)
{
    int grid[3][3];
    int fGrid[3][3];

    for (int i = 0; i < 9; i++)
    {
        if ((g & (1 << i)) > 0)
            grid[i / 3][i % 3] = 1;
        else
            grid[i / 3][i % 3] = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fGrid[i][j] = ((i - 1 >= 0 ? grid[i - 1][j] : 0) +
                           (j + 1 < 3 ? grid[i][j + 1] : 0) +
                           (i + 1 < 3 ? grid[i + 1][j] : 0) +
                           (j - 1 >= 0 ? grid[i][j - 1] : 0)) %
                          2;
        }
    }

    return TransformGridForm(fGrid);
}

void InitializeF(void)
{
    for (int i = 0; i < 512; i++)
        f[i] = CalculateF(i);
}

int GridSuccessors(int (*g)[3])
{
    memset(check, -1, sizeof(check));
    int next = TransformGridForm(g);
    check[next] = 0;
    int loopStart;

    for (int i = 1; i <= 512; i++)
    {
        next = f[next];
        if (check[next] > -1)
        {
            loopStart = check[next];
            break;
        }
        else
        {
            check[next] = i;
        }
    }

    return loopStart - 1;
}

int main(void)
{
    int tc, g[3][3], input;

    InitializeF();

    scanf("%d", &tc);
    while (tc--)
    {
        for (int i = 0; i < 3; i++)
        {
            scanf("%d", &input);
            g[i][0] = input / 100;
            g[i][1] = (input % 100) / 10;
            g[i][2] = (input % 10);
        }

        printf("%d\n", GridSuccessors(g));
    }
}