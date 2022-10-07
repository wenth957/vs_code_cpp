#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct Edge
{
    int a, b, w;
} edges[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        // 第i次更新表示经过i条边的最短路，动态规划的思想
        // 每次更新需要备份旧数组,更新时将到dist数组拷贝备份数组
        // 防止1-2-3更新受到1-2更新的影响
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            //更新所有边
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[n];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    int t = bellman_ford();
    if (t > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d\n", t);
    return 0;
}
