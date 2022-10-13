#include <iostream>
#include <string>

using namespace std;

const int N = 100010; //字符串长度
int son[N][26], cnt[N];
char str[N]; //每一位有26中可能
int idx;     //记录不同的字符串

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx; //创建新的节点
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0; // p代表当前节点的字符串
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char op[2];
        cin >> op >> str;
        if (op[0] == 'I')
            insert(str);
        else
        {
            int x = query(str);
            printf("%d\n", x);
        }
    }
    return 0;
}
