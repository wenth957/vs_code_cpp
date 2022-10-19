#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int idx, size_;         // idx为插入下标 size_为堆大小
int h[N], ph[N], hp[N]; // ph 插入下标映射到堆下标  hp堆下标映射到插入下标
// 只存ph，交换时只能找到交换对象的堆下标，找不到插入下标

void swap_heap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]); //堆下标
    swap(hp[a], hp[b]);         //插入下标
    swap(h[a], h[b]);           //交换堆中元素
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        swap_heap(u, u / 2);
        u /= 2;
    }
}

void down(int d)
{
    int t = d;
    if (d * 2 <= size_ && h[t] > h[d * 2])
        t = d * 2;
    if (d * 2 + 1 <= size_ && h[t] > h[d * 2 + 1])
        t = d * 2 + 1;
    if (d != t)
    {
        swap_heap(d, t);
        down(t);
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char op[5];
        int x, k, i;
        cin >> op;
        if (!strcmp(op, "I"))
        {
            cin >> x;
            size_++;
            h[size_] = x;
            hp[size_] = ++idx;
            ph[idx] = size_;
            up(size_);
        }
        else if (!strcmp(op, "PM"))
            cout << h[1] << endl;
        else if (!strcmp(op, "DM"))
        {
            swap_heap(1, size_);
            size_--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {

            cin >> k;
            i = ph[k];
            swap_heap(i, size_);
            size_--;
            down(i);
            up(i);
        }
        else
        {
            cin >> k >> x;
            i = ph[k];
            h[i] = x;
            down(i);
            up(i);
        }
    }
    return 0;
}
