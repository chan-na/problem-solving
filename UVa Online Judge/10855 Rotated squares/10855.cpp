#include <cstdio>
#include <vector>
using namespace std;

int main(void)
{
    int N, n;
    char buffer[1024];
    int result[4];
    bool flag;

    while (scanf("%d %d", &N, &n), N != 0)
    {
        for (int i = 0; i < 4; i++)
            result[i] = 0;
        vector<vector<char>> big(N, vector<char>(N));
        vector<vector<char>> small(n, vector<char>(n));

        for (int i = 0; i < N; i++)
        {
            scanf("%s", buffer);
            for (int j = 0; j < N; j++)
                big[i][j] = buffer[j];
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%s", buffer);
            for (int j = 0; j < n; j++)
                small[i][j] = buffer[j];
        }

        for (int i = 0; i <= N - n; i++)
        {
            for (int j = 0; j <= N - n; j++)
            {
                // 0
                flag = true;
                for (int x = 0; x < n; x++)
                {
                    if (!flag)
                        break;
                    for (int y = 0; y < n; y++)
                    {
                        if (big[i + x][j + y] != small[x][y])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                    result[0]++;

                // 90
                flag = true;
                for (int x = 0; x < n; x++)
                {
                    if (!flag)
                        break;
                    for (int y = 0; y < n; y++)
                    {
                        if (big[i + x][j + y] != small[n - 1 - y][x])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                    result[1]++;

                // 180
                flag = true;
                for (int x = 0; x < n; x++)
                {
                    if (!flag)
                        break;
                    for (int y = 0; y < n; y++)
                    {
                        if (big[i + x][j + y] != small[n - 1 - x][n - 1 - y])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                    result[2]++;

                // 270
                flag = true;
                for (int x = 0; x < n; x++)
                {
                    if (!flag)
                        break;
                    for (int y = 0; y < n; y++)
                    {
                        if (big[i + x][j + y] != small[y][n - 1 - x])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                    result[3]++;
            }
        }

        printf("%d %d %d %d\n", result[0], result[1], result[2], result[3]);
    }

    return 0;
}