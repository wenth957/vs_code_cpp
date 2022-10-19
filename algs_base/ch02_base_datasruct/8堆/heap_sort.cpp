#include <iostream>

using namespace std;

const int N = 100010;

int h[N], size_;

void down(int d)
{
    int t = d;
    if (d * 2 <= size_ && h[t] > h[d * 2])
        t = d * 2;
    if (d * 2 + 1 <= size_ && h[t] > h[d * 2 + 1])
        t = d * 2 + 1;
    if (d != t)
    {
        swap(h[d], h[t]);
        down(t);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    //建堆
    size_ = n;
    for (int j = n / 2; j > 0; j--)
        down(j);
    while (m--)
    {
        cout << h[1] << " ";
        swap(h[1], h[size_]);
        size_--;
        down(1);
    }
    cout << endl;
    return 0;
}
