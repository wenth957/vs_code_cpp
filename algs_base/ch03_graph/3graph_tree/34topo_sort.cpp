#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;
int q[N], d[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx, idx++;
}

bool toposort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            //队列中放topo序列
            q[++tt] = i;
    while (hh <= tt)
    {
        int t = q[hh++]; // 队头拿出来
        for (int i = h[t]; i != -1; i = ne[i])
        {
            //从入度为0的点开始遍历
            int j = e[i]; //看邻接表节点
            d[j]--;//删掉这条边，即入度-1
            if (d[j] == 0)
                q[++tt] = j;
        }
    }
    return tt == n - 1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if (toposort())
    {
        for (int i = 0; i < n; i++)
            printf("%d ", q[i]);
        puts("");
    }
    else
        puts("-1");
    return 0;
}
