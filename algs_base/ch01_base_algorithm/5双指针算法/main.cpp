#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int N = 1000010;
int a[N], s[N], n;

int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	int res = 0;
	for (int i = 0, j = 0; i < n; i++)
	{

		s[a[i]]++;
		while (s[a[i]] > 1)
		{
			s[a[j]]--;
			j++;
		}

		res = max(res, i - j + 1);
	}
	cout << res << endl;
	return 0;
}
