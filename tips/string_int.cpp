#include <string>
#include <iostream>

void PrintString(const std::string &str)
{
    std::cout << "^" << str << "$" << std::endl;
}

int main(void)
{
    int num = 65; // ASCII 'A'

    std::string str("");
    PrintString(str);

    str = str + std::to_string(65);
    PrintString(str);

    return 0;
}