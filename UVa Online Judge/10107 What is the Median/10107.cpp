#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int X, len = 0, result;
    vector<int> v;

    while (scanf("%d ", &X) != EOF)
    {
        ++len;
        v.insert(upper_bound(v.begin(), v.end(), X), X);

        if (len % 2 == 0)
            result = (v[len / 2] + v[len / 2 - 1]) / 2;
        else
            result = v[len / 2];
        printf("%d\n", result);
    }
    return 0;
}