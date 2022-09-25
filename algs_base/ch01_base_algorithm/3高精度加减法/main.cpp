#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &A, vector<int> &B)
{
	// 比较两个长整数的大小，第一个是否大于第二个数
	if (A.size() != B.size()) //长的更大
		return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (A[i] != B[i]) //从个位开始比较
			return A[i] > B[i];
	}
	return true;
}

vector<int> add(vector<int> &A, vector<int> &B)
{
	vector<int> C;

	int t = 0;

	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		if (i < A.size()) //从个位开始相加
			t += A[i];
		if (i < B.size()) //从个位开始相加，如果一个不满足，只加另一个即可
			t += B[i];
		C.push_back(t % 10); //保存余数
		t /= 10;			 //记录进位
	}
	if (t)
		C.push_back(1); //如果最后进位=1，那么添一位
	return C;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
	vector<int> C;
	for (int i = 0, t = 0; i < A.size(); i++)
	{
		t = A[i] - t;	  // 减去借位
		if (i < B.size()) //做减法直到A没有位，默认A大
			t -= B[i];
		C.push_back((t + 10) % 10); // > 0 t || <0  t + 10   10%10不影响
		if (t < 0)
			t = 1; //借位
		else
			t = 0; //不借
	}
	while (C.size() > 1 && C.back() == 0) // 前面位数==0，去掉
		C.pop_back();
	return C;
}

int main()
{
	/*
	A+B
	A-B
	A/a
	*/
	string a, b;
	vector<int> A, B;

	cin >> a >> b; // a = '123456'
	for (int i = a.size() - 1; i >= 0; i--)
		A.push_back(a[i] - '0'); // A [6 5 4 3 2 1]
	for (int j = b.size() - 1; j >= 0; j--)
		B.push_back(b[j] - '0');

	auto C = add(A, B);

	printf("\nadd\n");
	for (int i = C.size() - 1; i >= 0; i--)
		printf("%d", C[i]);
	printf("\nsub\n");
	if (cmp(A, B))
	{
		auto D = sub(A, B);
		for (int i = D.size() - 1; i >= 0; i--)
			printf("%d", D[i]);
	}
	else
	{
		auto D = sub(B, A);
		printf("-");
		for (int i = D.size() - 1; i >= 0; i--)
			printf("%d", D[i]);
	}
	return 0;
}
