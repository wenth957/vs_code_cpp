#include <iostream>

using namespace std;

const int N = 10100;

int a[N][N], S[N][N];

int n, m, q;

int main()

{
	scanf_s("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf_s("%d", &a[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			S[i][j] = a[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
	while (q--)
	{
		int x1, y1, x2, y2;
		scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1]);
	}
	return 0;
}
