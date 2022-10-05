#include <iostream>
#include <string>


using namespace std;

const int N = 1000010;

int stack[N];
int tt;

void push(int x)
{
    tt ++;
    stack[tt] = x;
}

void pop()
{
    if (tt) tt -= 1;
}

bool empty()
{
    if (!tt) return true;
    return false;
}

int query()
{
    if (tt) return stack[tt];
    return -1;

}
int main()
{
    int m;
    cin >> m;
    while (m --)
    {
        string op;
        int x;
        cin >> op;
        if (op == "push")
        {
            cin >> x;
            push(x);
        }
        else if (op == "query")
        {
            int t = query();
            printf("%d\n",t);
        }
        else if (op == "pop")
        {
            pop();
        }
        else
        {
            if (empty()) printf("Yes\n");
            else printf("No\n");
        }
    }
}
