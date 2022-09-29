#include <iostream>
#include <algorithm>

using namespace std;
const int M = 100010, N = M * M;
int h[N], ne[N], e[N], idx;
bool used[N];

void add(int a, int b)
{
    //插入a指向b的一条边
    e[idx] = b;     //当前的值
    ne[idx] = h[a]; //指向头
    h[a] = idx++;   //头左移
}

void dfs(int u)
{
    used[u] = true;
    //遍历单链表
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!used[j])
            dfs(j);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    dfs(1);
}
