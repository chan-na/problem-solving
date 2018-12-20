#include <cstring>
#include <cstdio>

int main(void)
{
    char str[10];
    memset(str, 'a', sizeof(str));
    printf("char memset 'a' : ");
    for (int i = 0; i < sizeof(str) / sizeof(char); i++)
        printf("%c ", str[i]);
    printf("\n");

    int arr[10];
    memset(arr, 4, sizeof(arr));
    printf("int memset 4 : ");
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);
    printf("\n");

    bool is[10];
    memset(is, 0, sizeof(is));
    printf("bool memset 0 : ");
    for (int i = 0; i < sizeof(is) / sizeof(bool); i++)
        printf("%d ", is[i]);
    printf("\n");

    memset(is, 1, sizeof(is));
    printf("bool memset 1 : ");
    for (int i = 0; i < sizeof(is) / sizeof(bool); i++)
        printf("%d ", is[i]);
    printf("\n");

    return 0;
}