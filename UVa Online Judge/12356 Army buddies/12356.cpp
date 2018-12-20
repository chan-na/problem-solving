#include <cstdio>
#include <utility>

int main(void)
{
    int S, B, L, R, left, right;
    int leftBuddies[1000005], rightBuddies[1000005];

    while (scanf("%d %d", &S, &B), S != 0)
    {
        for (int i = 1; i <= S; i++)
        {
            leftBuddies[i] = i - 1;
            rightBuddies[i] = i + 1;
        }

        while (B--)
        {
            scanf("%d %d", &L, &R);
            left = right = -1;

            if (leftBuddies[L] == 0 && rightBuddies[R] == S + 1)
            {
                ;
            }
            else if (leftBuddies[L] == 0)
            {
                right = rightBuddies[R];
                leftBuddies[right] = 0;
            }
            else if (rightBuddies[R] == S + 1)
            {
                left = leftBuddies[L];
                rightBuddies[left] = S + 1;
            }
            else
            {
                left = leftBuddies[L];
                right = rightBuddies[R];
                rightBuddies[left] = right;
                leftBuddies[right] = left;
            }

            if (left == -1 && right == -1)
                printf("* *\n");
            else if (left == -1)
                printf("* %d\n", right);
            else if (right == -1)
                printf("%d *\n", left);
            else
                printf("%d %d\n", left, right);
        }
        printf("-\n");
    }
}