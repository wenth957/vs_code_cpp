#include <iostream>

using namespace std;
const int N = 100010;

int n, m;
int p[N], size_[N]; //只有根节点的size有意义

int find(int x)
{
    if (p[x] != x)
        // 路径压缩,如果不是根节点，继续向上寻找
        p[x] = find(p[x]);
    //返回根节点即标签
    return p[x];
}

int main()
{ 
    scanf("%d%d", &n, &m);
    // 每个点都是一个集合，其父节点=自己
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        size_[i] = 1;
    }

    while (m--)
    {
        char op[5];
        scanf("%s", op);
        int a, b;
        if (op[0] == 'C')
        {
            scanf("%d%d", &a, &b);
            // 已经在一个集合中了
            if (find(a) == find(b))
                continue;
            // 新的根节点上
            size_[find(b)] += size_[find(a)];
            // a的根节点链接到新的根节点上
            p[find(a)] = find(b);
        }

        else if (op[1] == '1')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", size_[find(a)]);
        }
    }
    return 0;
}
