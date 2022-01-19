#include <iostream>
#include <string>
#include <vector>

using namespace std;
// *first statement is recusive call
// everything performed at return time when getting activation records out of stack

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        cout << n << endl;
    }
}
int main()
{
    fun(3);
    return 0;
}