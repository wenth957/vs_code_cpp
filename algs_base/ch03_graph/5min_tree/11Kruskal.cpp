#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge
{
    int a, b, w;
    //结构体内重载<
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edges[N];

int find(int x)
{
    //并查集,查找根节点，根节点的父亲是自己
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(p, -1, sizeof p);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        // 如果当前两个集合不连通，那么合并两个集合，在这里就是加一条边
        // 如果存在边一定是最小的
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1)
        puts("impossible");
    else
        printf("%d\n", res);
    return 0;
}
