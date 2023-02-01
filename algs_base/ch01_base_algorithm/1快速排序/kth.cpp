#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

void findk(int a[], int l, int r, int k)
{
    if (l >= r)
        return;
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (a[k - 1] <= pivot)
        findk(a, l, j, k);
    else
        findk(a, i, r, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    findk(a, 0, n - 1, k);
    cout << a[k - 1];
    return 0;
}
