#include <cstdio>
#include <cstring>
#include <algorithm>

int seq[5000];

int main(void)
{
    int N;
    while (scanf("%d", &N), N != 0)
    {
        memset(seq, 0, N);

        int num;
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &num);
            seq[i] = num;
        }

        int sum = seq[0] + seq[1];
        long long result = sum;
        for (int i = 2; i < N; ++i)
        {
            sum = sum + seq[i];
            result += sum;
        }

        printf("%lld\n", result);
    }

    return 0;
}