#include <iostream>
using namespace std;
const int N = 100010;
// head 头指针指向的下标
// idx 当前用到哪一个点
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
    ne[idx] = head; // ne[0] = -1 next指针指向上一个头结点
    head = idx;     // head = 0 head移动到新插入的最新节点上
    idx++;
    // idx 自增
}

void add(int k, int x)
{
    // 在idx=k的后面插入一个元素
    e[idx] = x;      // 记录第idx个节点
    ne[idx] = ne[k]; // idx的next指向k的next
    ne[k] = idx;   // k的next指向idx
    idx++; // idx自增
}

void remove(int k)
{
    // 移除idx=k后面的元素 k.next = k.next.next
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
                remove(k - 1); // 移除插入的第k个元素
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
