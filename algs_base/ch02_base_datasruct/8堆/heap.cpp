#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
const int N = 100010;

int n, m;
int h[N], ph[N], hp[N], size_;

void heap_swap(int a, int b)
{
    // 堆数组下标交换后，改变两个映射数组
    // 插入数组-堆数组映射关系
    swap(ph[hp[a]], ph[hp[b]]);
    // 堆数组-插入数组映射关系
    swap(hp[a], hp[b]);
    // 交换堆数组中的元素
    swap(h[a], h[b]);
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        // 从下往上插入，从上往下依次建好堆
        heap_swap(u, u / 2);
        u /= 2;
    }
}

void down(int u)
{
    int t = u;
    if (u * 2 <= size_ && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= size_ && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t); //递归交换t节点与其子节点
    }
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n--)
    {
        char op[5];
        int k, x;
        scanf("%s", &op);
        if (!strcmp(op, "I"))
        {
            //插入操作
            scanf("%d", &x);
            size_++;
            m++;           //当前的堆节点id
            ph[m] = size_; // 记录映射关系
            hp[size_] = m;
            h[size_] = x;
            up(size_); // up操作
        }
        else if (!strcmp(op, "PM"))
            // 打印最小值
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            // 删除最小值
            heap_swap(1, size_);
            size_--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            // 删除第k个插入的值
            scanf("%d", &k);
            k = ph[k];           //插入数组映射到堆数组下标
            heap_swap(k, size_); //交换堆中元素
            size_--;
            down(k), up(k);
        }
        else
        { //覆盖第k个结点
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++)
//         scanf("%d", &h[i]);
//     size_ = n;
//     for (int i = n / 2; i > 0; i--)
//         // 从上往下插入,从下往上依次建好堆
//         down(i);
//     //从第一个非叶节点开始下降（可以推导）
//     while (m--)
//     {
//         // 输出前m个数
//         printf("%d", h[1]);
//         //删除堆顶元素
//         h[1] = h[size_];
//         size_--;
//         down(1);
//     }
//     return 0;
// }
