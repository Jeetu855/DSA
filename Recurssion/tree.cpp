#include <iostream>

using namespace std;
void fun(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1);
        fun(n - 1);
    }
}

int main()
{
    fun(3); //* 2^(n-1) number of calls made, Time complexity : O(2^n)
    return 0;
}