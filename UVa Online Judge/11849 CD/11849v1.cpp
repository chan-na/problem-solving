#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> table;

    int N, M;
    while (cin >> N >> M, N != 0 && M != 0)
    {
        table.clear();

        int cd;
        while (N--)
        {
            cin >> cd;
            table.insert(cd);
        }

        int result = 0;
        while (M--)
        {
            cin >> cd;
            if (table.find(cd) != table.end())
            {
                ++result;
            }
        }

        cout << result << '\n';
    }

    return 0;
}