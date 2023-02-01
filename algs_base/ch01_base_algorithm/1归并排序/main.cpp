#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N], tmp[N]; //数组，归并数组

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    //划分
    int mid = l + (r - l) / 2;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    //合并：归并排序核心代码
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++]; // 先赋值后右移一位,返回值为k，区别于++k
        else
            tmp[k++] = q[j++];
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j]; //将归并好的有序数组赋值给原数组
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    // sort(q,q+n);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}
