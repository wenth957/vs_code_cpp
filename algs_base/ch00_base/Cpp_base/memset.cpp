#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010;

int a[N];

int main()
{
    //按位拷贝

    memset(a, -1, sizeof a); //-1
    memset(a, 1, sizeof a);  // 16843009  0x00000001 00000001 00000001 1占一个字节，但是整数拷贝了4个字节
    memset(a, 0, sizeof a);  // 0
    cout << a[0] << endl;
    return 0;
}
