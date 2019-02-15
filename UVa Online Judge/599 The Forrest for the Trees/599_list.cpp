#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int V[26];
int colored[26];
vector<vector<int>> G;
int colorCount[26];
char buffer[64];

void DFS(int vertex, int color)
{
    colored[vertex] = color;
    ++colorCount[color];

    for (size_t i = 0; i < G[vertex].size(); ++i)
    {
        if (colored[G[vertex][i]] == -1)
        {
            DFS(G[vertex][i], color);
        }
    }
}

int main(void)
{
    G.reserve(26);

    int testCase;
    scanf("%d", &testCase);
    while (testCase--)
    {
        memset(V, 0, sizeof(V));
        memset(colored, -1, sizeof(colored));
        memset(colorCount, 0, sizeof(colorCount));
        for (size_t i = 0; i < 26; ++i)
        {
            G[i].clear();
        }

        while (scanf("%s", buffer), buffer[0] != '*')
        {
            int v1 = buffer[1] - 'A';
            int v2 = buffer[3] - 'A';
            G[v1].push_back(v2);
            G[v2].push_back(v1);
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