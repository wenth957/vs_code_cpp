#include <iostream>
#include <cstring>
/*
哈希表：关键是解决哈希冲突问题
 - 拉链法:取余时一般是一个质数
*/
using namespace std;
const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k]; //新的点的next指针指向当前头节点h[k]
    h[k] = idx++;   // h[k]指向新的idx
}

bool find(int x)
{
    int k = (x % N + N) % N;
    // 遍历单链表，从最新插入的idx开始，头插法下一个结点指向旧节点
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof h); //清空槽位
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I')
            insert(x);
        else
        {
            if (find(x))
                puts("yes");
            else
                puts("no");
        }
    }
}
