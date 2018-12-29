#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool GetSuccessor(char *code, int len, int bound)
{
    int firstIndex = len - 1;
    int secondIndex = -1;
    for (int i = len - 2; i >= bound; i--)
    {
        if (code[i] == code[firstIndex])
        {
            firstIndex = i;
        }
        else
        {
            for (int j = i; j >= bound; j--)
            {
                if (code[firstIndex] - code[j] > 0)
                {
                    secondIndex = j;
                    goto FOR_LOOP_END;
                }
            }
            firstIndex = i;
        }
    }

FOR_LOOP_END:
    if (secondIndex == -1)
    {
        return false;
    }
    else
    {
        char tmp = code[firstIndex];
        code[firstIndex] = code[secondIndex];
        code[secondIndex] = tmp;
        sort(code + secondIndex + 1, code + len);
        return true;
    }
}

int main(void)
{
    char code[51];
    int len;
    bool hasSuccessor;

    while (scanf("%s", code), code[0] != '#')
    {
        len = strlen(code);

        hasSuccessor = false;
        for (int i = len - 1; i >= 0; i--)
        {
            if (GetSuccessor(code, len, i))
            {
                hasSuccessor = true;
                break;
            }
        }

        if (hasSuccessor)
            printf("%s\n", code);
        else
            printf("No Successor\n");
    }

    return 0;
}