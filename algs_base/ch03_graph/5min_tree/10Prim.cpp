#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                //集合外的点到集合最近的点更新为t
                //根据上一次迭代结果直接遍历一遍O(N)
                t = j;
        if (i && dist[t] == INF)
            //无连通
            return INF;
        if (i)
            res += dist[t];
        for (int j = 1; j <= n; j++)
            //更新所有点到新集合的距离，即旧集合与t的取最小,更新m次
            dist[j] = min(dist[j], g[t][j]);
        st[t] = true;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        // 无向图 + 重边
        g[a][b] = g[b][a] = min(g[a][b], w);
    }
    int t = prim();
    if (t == INF)
        puts("impossible");
    else
        printf("%d\n", t);
    return 0;
}
