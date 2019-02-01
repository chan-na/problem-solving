#include <cstdio>
#include <cstring>

#define MAX_LENGTH (32)

char source[MAX_LENGTH];
char target[MAX_LENGTH];
char stack[MAX_LENGTH];

int sourceAlphaNum[26];
int targetAlphaNum[26];

void PrintSequence(int seq, int length)
{
    for (int i = 2 * length - 1; i >= 0; i--)
    {
        if ((seq & (1 << i)) > 0)
        {
            printf("i ");
        }
        else
        {
            printf("o ");
        }
    }
    putchar('\n');
}

void Process()
{
    const int SOURCE_LEN = strlen(source);
    const int TARGET_LEN = strlen(target);
    if (SOURCE_LEN != TARGET_LEN)
    {
        return;
    }

    memset(sourceAlphaNum, 0, sizeof(sourceAlphaNum));
    memset(targetAlphaNum, 0, sizeof(targetAlphaNum));
    for (int i = 0; i < SOURCE_LEN; i++)
    {
        ++sourceAlphaNum[source[i] - 'a'];
        ++targetAlphaNum[target[i] - 'a'];
    }
    if (memcmp(sourceAlphaNum, targetAlphaNum, 26) != 0)
    {
        return;
    }

    int source_pointer;
    int target_pointer;
    int top;
    for (int seq = (1 << (2 * SOURCE_LEN)) - 1; seq >= 0; seq--)
    {
        // end with push
        if ((seq & 1) == 1)
        {
            continue;
        }

        source_pointer = 0;
        target_pointer = 0;
        top = -1;
        for (int i = 2 * SOURCE_LEN - 1; i >= 0; i--)
        {
            if ((seq & (1 << i)) > 0) // push
            {
                if (source_pointer == SOURCE_LEN) // too many push
                {
                    break;
                }

                ++top;
                stack[top] = source[source_pointer];
                ++source_pointer;
            }
            else // pop
            {
                // stack is empty
                if (top == -1)
                {
                    break;
                }

                // not matching
                if (stack[top] != target[target_pointer])
                {
                    break;
                }

                --top;
                ++target_pointer;
            }
        }

        if (target_pointer == TARGET_LEN) // anagram!
        {
            PrintSequence(seq, SOURCE_LEN);
        }
    }
}

int main(void)
{
    while (true)
    {
        memset(source, 0, sizeof(source));
        memset(target, 0, sizeof(target));

        if (fgets(source, MAX_LENGTH, stdin) == NULL)
        {
            break;
        }
        if (fgets(target, MAX_LENGTH, stdin) == NULL)
        {
            break;
        }
        source[strlen(source) - 1] = '\0';
        target[strlen(target) - 1] = '\0';

        printf("[\n");

        Process();

        printf("]\n");
    }
}