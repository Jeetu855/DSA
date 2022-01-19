#include <iostream>
#include <string>
#include <vector>

using namespace std;
// * fun1 calling fun2
// *fun2 calling fun3
// * fun3 calling fun1
void fun1(int n);
void fun2(int n);

void fun1(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun2(n - 1);
    }
}

void fun2(int n)
{
    if (n > 1)
    {
        cout << n << endl;
        fun1(n / 2);
    }
}

int main()
{
    fun1(20);
    return 0;
}