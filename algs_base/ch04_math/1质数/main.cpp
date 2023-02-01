#include <iostream>

using namespace std;
const int N = 100010;
int primers[N], cnt;
bool st[N];

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int j = 2; j <= n / j; j++)
    {
        if (n % j == 0)
            return false;
    }
    return true;
}

void divide(int n)
{
    for (int j = 2; j <= n / j; j++)
    {
        if (n % j == 0)
        {
            int s = 0;
            while (n % j == 0)
            {
                n /= j;
                s++;
            }
            printf("%d %d\n", j, s);
        }
    }
    if (n > 1)
        printf("%d %d\n", n, 1);
    puts(" ");
}

void get_primers_(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primers[cnt++] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}

void get_primers(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primers[cnt++] = i;
        for (int j = 0; primers[j] <= n / i; j++)
        {
            st[i * primers[j]] = true;
            if (i % primers[j] == 0)
                break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    divide(n);
    get_primers(n);
    bool res = is_prime(n);
    for (int i = 0; i < cnt; i++)
        cout << primers[i] << endl;
    if (res)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
