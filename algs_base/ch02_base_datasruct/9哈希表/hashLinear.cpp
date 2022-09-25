#include <iostream>
#include <cstring>
/*
哈希表：关键是解决哈希冲突问题
 - 开放寻址法：如果冲突，寻找下一个位置
*/

using namespace std;
const int N = 200003, null = 0x3f3f3f3f;
int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        // 如果下标为k的地方已经有值，寻下一个地址
        k++;
        if (k == N)
            // 如果k到达了末尾，那么从头开始寻找
            k = 0;
    }
    // 返回寻址下标
    return k;
}

int main()
{
    int n;
    scanf("%d", &n);
    // 按字节memset
    memset(h, 0x3f, sizeof h); //清空槽位
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if (*op == 'I')
            h[k] = x;
        else
        {
            if (h[k] != null)
                puts("yes");
            else
                puts("no");
        }
    }
}
