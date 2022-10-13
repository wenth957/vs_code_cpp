#include <iostream>

using namespace std;

const int N = 1000010, M = 100010;
int n, m;
char s[N], p[M];
int ne[M];

int main()
{
    cin >> m >> p + 1 >> n >> s + 1;
    // ne数组:模式串前后缀相等的最大长度,kmp思路不用全部匹配完
    for (int i = 2, j = 0; i <= m; i++)
    {
        // 如果下一位ij匹配ne[i] = ne[i-1] + 1 = j + 1
        // 如果下一位ij不匹配，要想找到最长前后子缀，必须找到次长然后+1
        while (j && p[i] != p[j + 1])
        // 回退到ne[j] ne[j]之前的前后缀匹配->看下一个字符是否匹配->直到匹配（需要以i为后缀）
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
