#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    /*
    empty() size()
    push 插入一个元素
    top 返回堆顶元素
    pop 弹出堆顶元素
    默认大根堆
    */
    int x = 1;
    priority_queue<int> heap;
    //定义小根堆插入负数
    heap.push(-x);
    //定义小根堆
    priority_queue<int, vector<int>, greater<int>> heap_min;
    return 0;
}
