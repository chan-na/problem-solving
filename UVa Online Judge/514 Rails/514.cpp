#include <cstdio>
#include <cstring>

#define MAX 1001

int stack[MAX];
int out_order[MAX];

int main()
{
    int N;
    while (scanf("%d", &N), N != 0)
    {
        memset(stack, 0, MAX);
        memset(out_order, 0, MAX);

        while (scanf("%d", &out_order[0]), out_order[0] != 0)
        {
            for (int i = 1; i < N; i++)
            {
                scanf("%d", &out_order[i]);
            }

            int out_index = 0;
            int current_in = 1;
            int top = -1;
            while (current_in <= N)
            {
                if (top == -1)
                {
                    top++;
                    stack[top] = current_in;
                    current_in++;
                }
                else if (out_order[out_index] == stack[top])
                {
                    top--;
                    out_index++;
                }
                else
                {
                    top++;
                    stack[top] = current_in;
                    current_in++;
                }
            }

            bool isPossible = true;
            while (out_index < N)
            {
                if (out_order[out_index] == stack[top])
                {
                    top--;
                    out_index++;
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }

            if (isPossible)
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
        putchar('\n');
    }

    return 0;
}