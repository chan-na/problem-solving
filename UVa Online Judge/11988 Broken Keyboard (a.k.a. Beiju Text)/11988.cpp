#include <cstdio>
#include <list>
using namespace std;

#define LENGTH 100002
char text[LENGTH];

int main(void)
{
    list<char> beigu_text;
    while (fgets(text, LENGTH, stdin) != NULL)
    {
        beigu_text.clear();
        auto it = beigu_text.begin();
        int i = 0;
        while (text[i] != '\0')
        {
            if (text[i] == '[')
            {
                it = beigu_text.begin();
            }
            else if (text[i] == ']')
            {
                it = beigu_text.end();
            }
            else if (text[i] == '\n')
            {
                ;
            }
            else
            {
                beigu_text.insert(it, text[i]);
            }
            i++;
        }

        for (it = beigu_text.begin(); it != beigu_text.end(); it++)
        {
            putchar(*it);
        }
        putchar('\n');
    }

    return 0;
}