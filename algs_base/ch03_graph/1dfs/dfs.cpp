#include <iostream>

using namespace std;
const int N = 10;

int n;
int path[N];
bool used[N];

void dfs(int u)
{
    if (u == n)
    {
        // 叶子结点
        for (int i = 0; i < n; i++)
            printf("%d", path[i]);
        printf("\n");
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        if (!used[j])
        {
            path[u] = j;
            used[j] = true;
            dfs(u + 1);
            path[u] = 0;
            used[j] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
