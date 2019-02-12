#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main(void)
{
    priority_queue<int, vector<int>, greater<int>> pQueue;

    int N;
    while (scanf("%d", &N), N != 0)
    {
        priority_queue<int, vector<int>, greater<int>>().swap(pQueue);

        int num;
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &num);
            pQueue.push(num);
        }

        long long result = 0;
        int min1, min2, sum;
        while (pQueue.size() != 1)
        {
            min1 = pQueue.top();
            pQueue.pop();

            min2 = pQueue.top();
            pQueue.pop();

            sum = min1 + min2;
            result += sum;
            pQueue.push(sum);
        }

        printf("%lld\n", result);
    }

    return 0;
}