#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    stack<int> stk;
    void eval(string s)
    {
        int a = stk.pop();
        int b = stk.pop();
        if (s == "+")
            stk.push(a + b);
        else if (s == "-")
            stk.push(a - b);
        else if (s == "*")
            stk.push(a * b);
        else
            stk.push(a / b);
    }

    int evalRPN(vector<string> &tokens)
    {
        unordered_set<string> S{"+","-","*","/"};
        for (auto& s: tokens){
            if (S.count(s)) eval(s);
            else stk.push(stoi(s));
        }
    }
    return stk.pop();
}
