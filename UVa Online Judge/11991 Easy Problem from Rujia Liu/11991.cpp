#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, vector<int>> occurrenceMap;
    occurrenceMap.reserve(10000);

    int numOfElements, numOfQueries;
    while (cin >> numOfElements >> numOfQueries, !cin.eof())
    {
        occurrenceMap.clear();

        int num;
        for (int i = 1; i <= numOfElements; ++i)
        {
            cin >> num;
            occurrenceMap[num].push_back(i);
        }

        int k, v;
        while (numOfQueries--)
        {
            cin >> k >> v;

            auto it = occurrenceMap.find(v);

            if (it == occurrenceMap.end())
            {
                cout << 0 << '\n';
                continue;
            }

            if (it->second.size() < k)
            {
                cout << 0 << '\n';
                continue;
            }

            cout << it->second[k - 1] << '\n';
        }
    }
}