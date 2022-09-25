#include <iostream>


using namespace std;
void printbit(int n)
{
	// n�Ķ����Ʊ�ʾ�е�kλ�Ƕ���  1111 3 2 1 0λ
	for (int k = 3; k >= 0; k--) cout << (n >> k & 1);
	cout << endl;
	/* ˼·:
	��kλ�ƶ������һλ n>>k
	����(0)λ�Ǽ� & 1
	*/
}

int lowbit(int n)
{
	// n�Ķ����Ƶ����1λ1����Ķ�������                          1010...10000 ->10000
	// n & -n(����) ȡ�� ~x + 1       ~x  0101...01111 + 1-> 0101...10000
	//   -> ǰ��ȫ��ȡ�� 0000010000
	return n & (-n);

}

int main()
{
	int n;
	cin >> n;
	//printbit(n);
	// ��ÿ�����Ķ�������1�ĸ���
	while (n--)
	{
		int x;
		cin >> x;
		int res = 0;
		// ʮ���Ʊ������ص��Ƕ����Ƶļ��� һһ��Ӧ
		while (x) x -= lowbit(x), res++;
		cout << res << " ";
	}
	cout << endl;
	return 0;
}