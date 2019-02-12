#include <iostream>
#include <queue>
#include <string>

struct MyDataType
{
    std::string name;
    int studentID;
};

class MyComparison
{
  public:
    bool operator()(const MyDataType &lhs, const MyDataType &rhs)
    {
        if (lhs.name == rhs.name)
        {
            return lhs.studentID > rhs.studentID;
        }
        return lhs.name > rhs.name;
    }
};

int main(void)
{
    std::priority_queue<MyDataType, std::vector<MyDataType>, MyComparison> pQueue;

    MyDataType data1;
    data1.name = "A";
    data1.studentID = 1;

    MyDataType data2;
    data2.name = "A";
    data2.studentID = 2;

    MyDataType data3;
    data3.name = "B";
    data3.studentID = 3;

    MyDataType data4;
    data4.name = "C";
    data4.studentID = 4;

    pQueue.push(data1);
    pQueue.push(data2);
    pQueue.push(data3);
    pQueue.push(data4);

    while (!pQueue.empty())
    {
        MyDataType data = pQueue.top();
        pQueue.pop();

        std::cout << "name: " << data.name << "  ID: " << data.studentID << std::endl;
    }

    return 0;
}