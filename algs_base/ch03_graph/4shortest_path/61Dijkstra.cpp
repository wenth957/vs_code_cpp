#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        //寻找路径最短的下一个点（可用堆优化）
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        //贪心策略：局部最短
        st[t] = true;
        //更新所有点的最短距离
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    //从1号点走向N号点的最短路，如果不可达，return -1
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //存在重边和自环
        g[a][b] = min(g[a][b], c);
    }
    int t = dijkstra();
    printf("%d\n", t);
    return 0;
}
