#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
    map<string, int> table;
    int course[5];

    int numOfFrosh;
    while (cin >> numOfFrosh, numOfFrosh != 0)
    {
        table.clear();

        int studentCountMax = 0;
        for (int i = 0; i < numOfFrosh; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cin >> course[j];
            }
            sort(course, course + 5);

            string temp("");
            for (auto code : course)
            {
                temp += to_string(code);
            }

            ++table[temp];
            if (table[temp] > studentCountMax)
            {
                studentCountMax = table[temp];
            }
        }

        int result = 0;
        for (auto &combination : table)
        {
            if (combination.second == studentCountMax)
            {
                result += combination.second;
            }
        }

        cout << result << '\n';
    }

    return 0;
}