#include <iostream>
/*
字符串哈希：abcd
前缀的hash值：
    1 看作4位的P进制数 1234 映射时从1开始
    2 转化位10进制数： h[4] = P^3+2P^2+3P+4  第4位的字母直接加在前3位的hash值上即h[4] = h[3]*p + str[4]
    3 h[4] % Q 映射位 0 ~ Q-1  Q=2<<64 P=131
    4 假设不存在冲突
*/

using namespace std;
typedef unsigned long long ULL;

const int N = 100010, P = 131;
int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
    // unsined long long 会自动对结果进行取模操作
    return h[r] - h[l] * p[r - l + 1];
}
int main()
{
    scanf("%d%d%s", &n, &m, str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i + 1] * P;          // 提前存储p的幂
        h[i] = h[i - 1] * P + str[i]; // 前缀哈希值计算，类比二进制
    }
    while (m--)
    {
        int l1, l2, r1, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
