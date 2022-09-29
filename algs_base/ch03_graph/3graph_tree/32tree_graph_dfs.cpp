#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100010, M = N * 2;

int h[N], ne[M], e[M], idx;
int n, ans = N;
bool used[N];

void add(int a, int b)
{
    //插入a指向b的一条边
    e[idx] = b;     //当前的值
    ne[idx] = h[a]; //指向头
    h[a] = idx++;   //头左移
}

int dfs(int u)
{
    //返回以u为根节点的子树中节点个数
    used[u] = true;
    //遍历单链表
    int sum_ = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!used[j])
        {
            int s = dfs(j);    //记录遍历子树的节点数
            res = max(res, s); //所有子树的节点数取最大值
            sum_ += s;         //所有子节点节点数相加
        }
    }
    res = max(res, n - sum_); //计算最大的节点数
    ans = min(res, ans);      //记录最小的最大值
    return sum_;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
}
