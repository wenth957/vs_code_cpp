#include <iostream>


using namespace std;
void printbit(int n)
{
	// n的二进制表示中第k位是多少  1111 3 2 1 0位
	for (int k = 3; k >= 0; k--) cout << (n >> k & 1);
	cout << endl;
	/* 思路:
	第k位移动到最后一位 n>>k
	看个(0)位是几 & 1
	*/
}

int lowbit(int n)
{
	// n的二进制的最后1位1后面的二进制数                          1010...10000 ->10000
	// n & -n(补码) 取反 ~x + 1       ~x  0101...01111 + 1-> 0101...10000
	//   -> 前面全部取反 0000010000
	return n & (-n);

}

int main()
{
	int n;
	cin >> n;
	//printbit(n);
	// 求每个数的二进制中1的个数
	while (n--)
	{
		int x;
		cin >> x;
		int res = 0;
		// 十进制背后隐藏的是二进制的减法 一一对应
		while (x) x -= lowbit(x), res++;
		cout << res << " ";
	}
	cout << endl;
	return 0;
}