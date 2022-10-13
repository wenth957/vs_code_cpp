#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
/*
（1+1）*（2 + 2）
优先处理括号
*/

using namespace std;

stack<int> nums;
stack<char> ops;
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval()
{
    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    char c = ops.top();
    ops.pop();
    if (c == '+')
        nums.push(a + b);
    else if (c == '-')
        nums.push(a - b);
    else if (c == '*')
        nums.push(a * b);
    else
        nums.push(a / b);
}

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        auto v = s[i];
        if (isdigit(v))
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j++] - '0';
            }
            i = j - 1;
            nums.push(x);
        }
        else if (v == '(')
            ops.push(v);
        else if (v == ')')
        {
            while (ops.top() != '(')
                eval();
            ops.pop();
        }
        else
        {
            //如果是运算符，判断是否顺序小于栈顶元素
            while (ops.size() && pr[ops.top()] >= pr[v])
                eval();
            ops.push(v);
        }
    }
    while (ops.size())
        eval();
    cout << nums.top() << endl;
    return 0;
}
