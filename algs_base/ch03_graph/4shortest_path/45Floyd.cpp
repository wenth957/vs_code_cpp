#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;
int n, m, q;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
    while (m--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        d[a][b] = min(d[a][b], w);
    }
    floyd();
    while (q--)
    {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        if (d[c1][c2] > INF / 2)
            puts("impossible");
        else
            printf("%d\n", d[c1][c2]);
    }
    return 0;
}
