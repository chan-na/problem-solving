#include <cstdio>

int main(void)
{
    int input;

    // 001 형태로 입력되면 1로 인식되고
    // 010 형태로 입력되면 10으로 인식된다
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &input);
        printf("%d\n", input);
    }
    return 0;
}