#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    //邻接表
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        // 遍历相邻节点
        int j = e[i];
        if (!color[j])
        {
            // 如果没有被染色，染成其他颜色
            if (!dfs(j, 3 - c))
                return false;
        }
        else if (color[j] == c)
            // 如果颜色和相邻节点相同，返回false
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    if (flag)
        puts("Yes");
    else
        puts("No");
    return 0;
}