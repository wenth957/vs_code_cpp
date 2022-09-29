#include <iostream>

using namespace std;
const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s)
{
    if (y == n)
        y = 0, x++;
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
                puts(g[i]);
            puts("");
        }
        return;
    }
    // 不放皇后,继续向右
    dfs(x, y + 1, s);
    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[y + n - x])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n + y - x] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[n + y - x] = false;
        g[x][y] = '.';
    }
}

void dfs(int u)
{
    if (u == n)
    {
        // 叶子结点
        for (int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (!col[j] && !dg[u + j] && !udg[j - u + n])
        {
            g[u][j] = 'Q';
            col[j] = dg[u + j] = udg[n + j - u] = true;
            dfs(u + 1);
            col[j] = dg[u + j] = udg[n + j - u] = false;
            ;
            g[u][j] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    printf("%s", "----------\n");
    dfs(0, 0, 0);
    return 0;
}
