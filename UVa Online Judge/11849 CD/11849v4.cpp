#include <cstdio>
#include <unordered_set>
using namespace std;

int main(void)
{
    unordered_set<int> table;
    table.reserve(1000000);

    int N, M;
    while (scanf("%d%d", &N, &M), N != 0 && M != 0)
    {
        table.clear();

        int cd;
        while (N--)
        {
            scanf("%d", &cd);
            table.insert(cd);
        }

        int result = 0;
        while (M--)
        {
            scanf("%d", &cd);
            if (table.find(cd) != table.end())
            {
                ++result;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}