#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
    /*
    使用的空间是正常的bool数组的1/8
    ~ & | ^ >> <<
    == !=
    [] 取某一位
    count 返回有多少个1
    any  判断是否有一个1
    none  判断是否全为空
    set  把所有位置成1
    set(k,v) 第k为变为v
    reset   所有位置变为0
    flip()  取反等价于~
    flip(k) 第k位取反
    */
    bitset<10000> s;
    s.set();
    cout << s.none() << endl;
}
