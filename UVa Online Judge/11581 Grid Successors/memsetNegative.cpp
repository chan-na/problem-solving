#include <cstdio>
#include <cstring>

int main(void)
{
    int arr[10];

    // int형 0으로 초기화 가능
    // unsigned char의 0은 0x00이고 int형의 0은 0x000000이므로
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    // int형 -1으로 초기화 가능
    // -1 is 0xff (=255) in int8_t and 0xffffffff in int32_t
    memset(arr, -1, sizeof(arr));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    memset(arr, 1, sizeof(arr));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    return 0;
}