#include <iostream>

using namespace std;

const int N = 100010, M = 10010;
int n, m;
char s[N], p[M];
int ne[M];

int main()
{
    cin >> m >> (p + 1) >> n >> (s + 1);
    // ne数组
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    // kmp算法
    //如果不匹配，模式串后移ne[j]位置
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == m)
        {
            printf("%d ", i - m); //打印起始位置
            j = ne[j];            //匹配是否存在第二个模式串
        }
    }
    puts("");
}
