#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int N = 20;
typedef pair<int, int> PII;

int n, m;
int g[N][N];
int d[N][N];
PII q[N * N], pred[N][N]; //存储坐标

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0, 0};
    memset(d, -1, sizeof d); //距离初始化-1
    d[0][0] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    // 上 右 下 左
    while (hh <= tt)
    {
        auto t = q[hh++]; // 队头
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                // 上下路径可以走，并且没走过，往外走，离+1
                d[x][y] = d[t.first][t.second] + 1;
                // 当前节点加入队列
                pred[x][y] = t;
                q[++tt] = {x, y};
            }
        }
    }
    //打印路径
    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << ' ' << y << endl;
        auto t = pred[x][y];
        x = t.first, y = t.second;
    }
    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    cout << bfs() << endl;
    return 0;
}
