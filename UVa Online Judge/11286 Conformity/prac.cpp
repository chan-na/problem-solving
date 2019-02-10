#include <iostream>
#include <string>
using namespace std;

void PrintString(const string &str)
{
    cout << "^" << str << "$" << endl;
}

int main(void)
{
    string temp("");
    PrintString(temp);

    temp += to_string(123);
    PrintString(temp);

    return 0;
}