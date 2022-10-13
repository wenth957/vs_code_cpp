#include <iostream>

using namespace std;
const int N = 100010;
int queue[N], hh, tt = -1;

void push(int x)
{
    queue[++tt] = x;
}

void pop(int x)
{
    tt--;
}

bool empty()
{
    if (tt != -1 && hh <= tt)
        return false;
    return true;
}

int query()
{
    if (tt != -1 && hh <= tt)
        return queue[hh];
    else
        return -1;
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (op == "pop")
            hh++;
        else if (op == "empty")
        {
            if (empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << query() << endl;
    }
    return 0;
}
