#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mul(vector<int>& A, int b)
{

	vector<int> C;

	int t = 0;
	for (int i = 0; i < A.size() || t; i++)
	{
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	return C;
}

vector<int> div(vector<int>& A, int b, int &r)
{
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main()
{
	string a;
	int b;
	cin >> a >> b;
	vector<int> A;

	for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

	auto C = mul(A, b);
	printf("mul\n");
	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	printf("\ndiv\n");
	int r;//除法从高位算
	auto D = div(A, b, r);
	for (int i = D.size() - 1; i >= 0; i--) printf("%d", D[i]);
	cout << endl << "mod: " << r << endl;
	return 0;


}