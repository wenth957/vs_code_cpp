#include <iostream>
#include <vector>
using namespace std;
const int N = 100010;
int n;
int nums[N];
int target;
int binary_search(int [], int left, int right, int target)
{
    while (left < right)
    {
        int mid = (left + right + 1) / 2; // �߽�����
        if (nums[mid] <= target) left = mid;
        else right = mid - 1;

    }
    if (nums[left] == target) return left;
    return -1;
}
int main()
{
    cin >> n >> target;
    for (int i = 0; i < n; i ++) scanf("%d", &nums[i]);
    int res = binary_search(nums, 0, n - 1, target);
    cout << res << endl;
}
