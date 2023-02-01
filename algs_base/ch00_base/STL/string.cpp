#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    /*size() length() empty() clear()*/
    string a = "wpw";
    a += "def";
    a += 'c';
    cout << a << endl;
    // 返回子串,第二个参数可以缺省,注意是数组长度
    cout << a.substr(1, 2) << endl;
    printf("%s\n", a.c_str()); // c_str 存储字符数组的起始地址
}
