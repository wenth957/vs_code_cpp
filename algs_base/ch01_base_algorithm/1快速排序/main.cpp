#include <iostream>
using namespace std;

const int N = 1000001;
int n;
int arr[N];

void quick_sort(int arr[], int left, int right)
{
	if (left >= right)
		return;
	int pivot = left;
	int i = left, j = right;
	while (i <= j)
	{
		while (arr[i] < arr[pivot])
			i++;
		while (arr[j] > arr[pivot])
			j--;
		if (i <= j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	quick_sort(arr, left, j);
	quick_sort(arr, i, right);
}
int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}
