#include <iostream>

using namespace std;

const int N = 1000010, M = 100010;
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
        // 使用模式串的前缀去匹配模式串的后缀：如果相等，直接返回j+1
        // 如果不相等，必须匹配i
        // 所以使用kmp的思路：回退到ne[j] 看下一个字符是否匹配（前缀的后缀变短，后缀的前缀变短）
            j = ne[j];
        if (p[i] == p[j + 1])// 如果相等，那么ne[i] = ne[i-1] + 1
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
