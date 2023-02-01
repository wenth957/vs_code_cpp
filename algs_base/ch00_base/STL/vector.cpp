/*
size() empty() clear() 某些容器没有
auto 可以遍历所有容器

vector 变长数组
    倍增的思想：当数组长度不足时，倍增，然后将旧数组拷贝到新数组上
    系统为某个程序分配空间时，所需要的时间和空间大小无关，与申请次数有关，所以需要尽量减少申请次数
    [] 索引
    front() / back()  返回第一个数/最后一个数
    push_back()/ pop_back() 添加一个数/删除最后一个数
    begin()/end() 第1个数 最后一个数的后面一个数
    比较运算 3333 < 444 字典序
pair<int,string>
    存储一对元素
    p.first
    p.second
    支持比较运算 以first为第一个关键字，second为第二个关键字 字典序
string 字符串 substr(), c_str()
queue 队列 push() front() pop()
priority_queue 优先队列 push() top() pop()
stack 栈 push() top() pop()
deque 双端队列
set, map, multiset, multimap 基于平衡二叉树（红黑树），动态维护有序序列
unordered_set, unordered_map,unordered_multiset,unordered_multimap 哈希表
bitset 压位
list
*/
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    bool flag = a.empty();
    cout << flag << endl;
    // 插入
    for (int i = 0; i < 10; i++)
        a.push_back(i);
    int size_ = a.size();
    cout << size_ << endl;
    // 循环遍历
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    // 范围遍历
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    // 迭代器：类似指针，解引用
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
        cout << *i << " ";
    cout << endl;
    // pair
    pair<int, string> p;//只有两个元素，可以放在vector中
    p = make_pair(10, "wpw");//第一种初始化的方式
    p = {20, "abc"};//第二种初始化的方式
    cout << p.first << " " << p.second << endl;
    return 0;
}
