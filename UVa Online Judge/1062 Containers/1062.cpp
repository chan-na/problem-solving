#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int stack[26];
int numOfStack;

int main(void)
{
    string input;
    int caseNum = 1;
    while (cin >> input, input != "end")
    {
        memset(stack, -1, sizeof(stack));
        numOfStack = 0;

        for (int i = 0; i < input.size(); ++i)
        {
            int index = -1;
            for (int j = 0; j < numOfStack; ++j)
            {
                if (stack[j] >= input[i])
                {
                    if (index == -1)
                    {
                        index = j;
                    }
                    else
                    {
                        if (stack[index] > stack[j])
                        {
                            index = j;
                        }
                    }
                }
            }

            if (index == -1)
            {
                stack[numOfStack] = input[i];
                ++numOfStack;
            }
            else
            {
                stack[index] = input[i];
            }
        }

        cout << "Case " << caseNum++ << ": " << numOfStack << endl;
    }

    return 0;
}