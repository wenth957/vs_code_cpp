#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010;

int a[N];

int main()
{
    // 按位拷贝
    memset(a, -1, sizeof a); //-1
    memset(a, 1, sizeof a);  // 16843009  00000001 00000001 00000001 00000001
    // 按字节拷贝，但是因为整数1占4个字节，如果按拷贝4次1，就会成为一个很大的数
    memset(a, 0, sizeof a); // 0
    cout << a[0] << endl;
    return 0;
}
