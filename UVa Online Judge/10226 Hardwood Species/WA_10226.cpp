#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    map<string, int> table;
    cout << fixed << setprecision(4);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        cin >> ws;
        table.clear();

        int treeCount = 0;
        string species;
        while (true)
        {
            getline(cin, species);
            species.pop_back();

            if (species == "" || cin.fail())
            {
                break;
            }

            ++table[species];
            ++treeCount;
        }

        for (auto it = table.begin(); it != table.end(); ++it)
        {
            cout << (*it).first << ' ' << (*it).second * 100 / (double)treeCount << '\n';
        }

        if (testCase != 0)
        {
            cout << '\n';
        }
    }
}