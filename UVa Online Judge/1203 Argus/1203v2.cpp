#include <iostream>
#include <string>
#include <queue>
using namespace std;

int intervals[3001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queries;

    string str;
    int queryID;
    int interval;
    while (cin >> str, str != "#")
    {
        cin >> queryID >> interval;
        intervals[queryID] = interval;
        queries.push(pair<int, int>(interval, queryID));
    }

    int numOfTasks;
    cin >> numOfTasks;
    while (numOfTasks--)
    {
        auto query = queries.top();
        queries.pop();

        cout << query.second << '\n';

        query.first += intervals[query.second];
        queries.push(query);
    }

    return 0;
}