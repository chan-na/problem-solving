#include <cstdio>

int main(void)
{
    int SZ;
    int X, Y;
    int start, offset, step;
    long long int square, P;

    while (scanf("%d%lld", &SZ, &P), SZ != 0)
    {
        for (int i = 0; i < SZ; i++)
        {
            square = (long long int)(i * 2 + 1) * (i * 2 + 1);

            if (P == square)
            {
                start = i;
                step = 0;
                X = SZ / 2 - start;
                Y = SZ / 2 + start;
                break;
            }
            if (P < square)
            {
                start = i;
                offset = P - (i * 2 - 1) * (i * 2 - 1);
                step = i * 2;
                X = SZ / 2 - start;
                Y = SZ / 2 + start;
                break;
            }
        }

        if (step == 0)
        {
            ;
        }
        else if (offset / step == 0)
        {
            Y -= offset;
        }
        else if (offset / step == 1)
        {
            Y -= step;
            X += offset % step;
        }
        else if (offset / step == 2)
        {
            X += step;
            Y = Y - step + offset % step;
        }
        else if (offset / step == 3)
        {
            X = X + step - offset % step;
        }

        printf("Line = %d, column = %d.\n", SZ - X, Y + 1);
    }
}