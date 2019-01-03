#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {1, 4, 7, 12, 23};
    vector<int> v(arr, arr + 5);

    cout << *(lower_bound(v.begin(), v.end(), 10)) << endl; // 12
    cout << *(upper_bound(v.begin(), v.end(), 10)) << endl; // 12

    cout << *(lower_bound(v.begin(), v.end(), 7)) << endl; // 7
    cout << *(upper_bound(v.begin(), v.end(), 7)) << endl; // 12

    v.clear();
    v.insert(lower_bound(v.begin(), v.end(), 10), 10);
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << endl;

    return 0;
}