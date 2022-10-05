#include <iostream>

//求滑动窗口最小值或者最大值
/*
优化了暴力做法，将每一段区间用一个队列来维护，单调递增队列求滑动窗口最小值，单调递减队列求滑动窗口最大值
队头元素为最大最小值
队列里面存储下标 idx - head  = k - 1 时， head ++
当head >= k - 1时 print
*/

using namespace std;
const int N = 1000010;

int nums[N], que[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", k);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - que[hh] > k - 1)
            hh++;
        //最小值，单调递增序列
        while (hh <= tt && nums[que[tt]] >= nums[i])
            tt--;
        que[++tt] = i;
        if (hh <= tt && i >= k - 1)
            printf("%d ", nums[que[hh]]);
    }
    puts("");
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - que[hh] > k - 1)
            hh++;
        //最小值，单调递增序列
        while (hh <= tt && nums[que[tt]] <= nums[i])
            tt--;
        que[++tt] = i;
        if (hh <= tt && i >= k - 1)
            printf("%d ", nums[que[hh]]);
    }
    puts("");

    return 0;
}
