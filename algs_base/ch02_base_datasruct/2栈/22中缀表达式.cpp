#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<int> op;

void eval()
{
    auto b = num.top();
    num.pop();
    auto a = num.top();
    num.pop();
    auto c = op.top();
    op.pop();
    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x);
}

int main()
{
    unordered_map<char, int> pr{
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        auto c = str[i];
        if (isdigit(c))
        {
            // 处理多位数
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';
            i = j - 1; //更新i到最后一位数字
            num.push(x);
        }
        // 优先处理括号
        else if (c == '(')
            op.push(c);
        else if (c == ')')
        {
            //一直处理到左括号/当成一个新表达式即可
            while (op.top() != '(')
                eval();
            op.pop(); //弹出左括号
        }
        else
        {
            while (op.size() && pr[op.top()] >= pr[c])
                eval();
            op.push(c); //新的运算符入栈
        }
    }
    while (op.size())
        eval(); //处理中间结果
    cout << num.top() << endl;
    return 0;
}
