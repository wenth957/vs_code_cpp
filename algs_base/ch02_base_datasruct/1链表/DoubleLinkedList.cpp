#include <iostream>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

void init()
{
	r[0] = 1;
	l[1] = 0;
	idx = 2;
}

void add(int k, int x)
{

	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx;
	r[k] = idx;
}

void remove(int k)
{
	l[r[k]] = l[k];
	r[l[k]] = r[k];
}
int main()
{
	return 0;
}
