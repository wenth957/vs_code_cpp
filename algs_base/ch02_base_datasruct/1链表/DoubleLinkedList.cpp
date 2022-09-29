#include <iostream>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

void init()
{
	r[0] = 1;//双链表的第一个点
	l[1] = 0;//双链表的第二个点
	idx = 2;//从下标2开始插入
}

void add(int k, int x)
{
	//在k的右边插入一个点

	e[idx] = x;//存储数值
	r[idx] = r[k];//idx的后继指针指向k的后继指针
	l[idx] = k;//idx的前驱指针指向k
	l[r[k]] = idx;//原来k的后继指针的前驱指针指向idx
	r[k] = idx;//原来k的后继指针指向idx
}

void remove(int k)
{
	// 删除k后面的节点
	l[r[k]] = l[k];//k右边的前驱指针指向k的前一个节点
	r[l[k]] = r[k];//k的前一个节点的后继指针指向k右边的节点
}
int main()
{
	return 0;
}
