#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

const int N = 150010; //邻接表存储
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;     //第idx插入的点是b
    w[idx] = c;     //第idx条边的权重是c
    ne[idx] = h[a]; //头插法
    h[a] = idx++;   //更新头
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    //定义小根堆  数据类型|容器类型|升序 存[dist，idx]
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1}); // dist[1] = 0 根据距离排序
    while (heap.size())
    {
        // 取出最近节点
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver])
            continue;
        st[ver] = true;
        // 贪心策略：更新所有的节点路径长度
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            //从ver的邻接点开始遍历，类似宽搜
            int j = e[i];
            dist[j] = min(dist[j], distance + w[i]);
            heap.push({dist[j], j});
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int t = dijkstra();
    printf("%d\n", t);
    return 0;
}
