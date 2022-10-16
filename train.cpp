#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 100010, M = 1000010;
char p[N], s[M];
int ne[N];
int n, m;

int main()
{
    cin >> n >> p >> m >> s;

    //ne数组
    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i ++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n)
        {
            printf("%d", i - n);
            j = ne[j];
        }
    }
    return 0;
}
