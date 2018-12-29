#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
    char code[51], tmp;
    int len, firstIndex, secondIndex;

    while (scanf("%s", code), code[0] != '#')
    {
        len = strlen(code);

        firstIndex = len - 1;
        secondIndex = -1;
        for (int i = 1; i < len; i++)
        {
            if (code[len - i - 1] == code[firstIndex])
            {
                firstIndex = len - i - 1;
            }
            else
            {
                for (int j = i; j < len; j++)
                {
                    if (code[firstIndex] - code[len - j - 1] > 0)
                    {
                        secondIndex = len - j - 1;
                        goto FOR_LOOP_END;
                    }
                }
                firstIndex = len - i - 1;
            }
        }

    FOR_LOOP_END:
        if (secondIndex == -1)
        {
            printf("No Successor\n");
        }
        else
        {
            tmp = code[firstIndex];
            code[firstIndex] = code[secondIndex];
            code[secondIndex] = tmp;
            sort(code + secondIndex + 1, code + len);
            printf("%s\n", code);
        }
    }

    return 0;
}