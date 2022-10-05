#include <iostream>
#include <stack>

using namespace std;
stack<int> stk;

int main()
{
    //输出该数左边第一个小于该数的数
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        // 如果当前数字小于栈顶元素，那么pop
        cin >> x;
        while (!stk.empty() && stk.top() >= x)
            stk.pop();
        if (!stk.empty())
            cout << stk.top() << ' ';
        else
            cout << -1 << ' ';
        stk.push(x);
    }
    cout << endl;
    return 0;
}
