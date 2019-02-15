#include <cstdio>
#include <cstring>

int V[26];
int colored[26];
int G[26][26];
int colorCount[26];
char buffer[64];

void DFS(int vertex, int color)
{
    colored[vertex] = color;
    ++colorCount[color];

    for (int i = 0; i < 26; ++i)
    {
        if (G[vertex][i] == 1 && colored[i] == -1)
        {
            DFS(i, color);
        }
    }
}

int main(void)
{
    int testCase;
    scanf("%d", &testCase);
    while (testCase--)
    {
        memset(V, 0, sizeof(V));
        memset(colored, -1, sizeof(colored));
        memset(G, 0, sizeof(G));
        memset(colorCount, 0, sizeof(colorCount));

        while (scanf("%s", buffer), buffer[0] != '*')
        {
            int v1 = buffer[1] - 'A';
            int v2 = buffer[3] - 'A';
            G[v1][v2] = G[v2][v1] = 1;
        }

        scanf("%s", buffer);
        int i = 0;
        while (buffer[i] != '\0')
        {
            if (buffer[i] != ',')
            {
                int vertex = buffer[i] - 'A';
                V[vertex] = 1;
            }
            ++i;
        }

        int color = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (V[i] == 1 && colored[i] == -1)
            {
                DFS(i, color);
                ++color;
            }
        }

        int treeCount = 0;
        int acornCount = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (colorCount[i] > 1)
            {
                ++treeCount;
            }
            else if (colorCount[i] == 1)
            {
                ++acornCount;
            }
        }

        printf("There are %d tree(s) and %d acorn(s).\n", treeCount, acornCount);
    }
}