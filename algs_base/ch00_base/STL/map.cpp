#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    /*
    map/multimap  logn| unordered_map/unordered_multi_map  1 但不支持lower_bound() upper_bound() ++ --
    size() empty() clear() begin() end()
    insert() 插入的数是一个pair
    erase() 输入参数是pair或者迭代器
    find()
    [] 索引 logn
    lower_bound()/upper_bound()
    */
    map<string, int> a;
    a["wpw"] = 18;
    cout << a["wpw"] << endl;
}
