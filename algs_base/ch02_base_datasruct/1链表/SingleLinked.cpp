#include <iostream>
using namespace std;
const int N = 100010;
int head, e[N], ne[N], idx;
void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{
    // 头插法 a->-1 插入a
    e[idx] = x;     // e[0] = a
    ne[idx] = head; // ne[0] = -1
    head = idx;     // head = 0 head移动到插入的最新节点上
    idx++;
    // idx 自增
}

void add(int k, int x)
{
    // 在idx=k的地方插入
    e[idx] = x;      // a->b->c e[2] = b
    ne[idx] = ne[k]; // ne[2] = ne[1] = 0 当前元素指向下一个元素
    ne[k] = idx;
    // 上一个元素 指向 idx
    idx++; // idx自增
}

void remove(int k)
{
    // 移除元素 k.next = k.next.next
    ne[k] = ne[ne[k]];
}
int main()
{
    int m;
    cin >> m;
    init();
    while (m--)

    {
        int k, x;
        char op;
        cin >> op;
        if (op == 'H')

        {
            cin >> x;
            add_to_head(x); // e[idx]=x ne[idx]=head head=idx idx++
        }
        else if (op == 'D')

        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    cout << endl;
    return 0;
}
