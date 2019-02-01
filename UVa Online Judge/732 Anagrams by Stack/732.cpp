#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string source;
string target;
int length;

void FindAnagram(string result, string op_seq, string stack, int source_index, int target_index)
{
    if (result.size() == length && result == target)
    {
        op_seq.pop_back();
        cout << op_seq << endl;
        return;
    }

    if (source_index < length)
    {
        FindAnagram(result, op_seq + "i ", stack + source[source_index], source_index + 1, target_index);
    }

    if (!stack.empty())
    {
        if (stack.back() == target[target_index])
        {
            char pop = stack.back();
            stack.pop_back();
            FindAnagram(result + pop, op_seq + "o ", stack, source_index, target_index + 1);
        }
    }
}

int main(void)
{
    while (cin >> source >> target, !cin.fail())
    {
        cout << "[" << endl;

        if (source.size() == target.size())
        {
            string temp1(source);
            string temp2(target);
            sort(temp1.begin(), temp1.end());
            sort(temp2.begin(), temp2.end());
            if (temp1 == temp2)
            {
                length = source.size();
                FindAnagram(string(""), string(""), string(""), 0, 0);
            }
        }

        cout << "]" << endl;
    }

    return 0;
}