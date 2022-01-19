#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 2) + fib(n - 1);
    }
}

int it_fib(int n)
{
    int t0 = 0, t1 = 1;
    int sum, i;
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        for (i = 2; i <= n; i++)
        {
            sum = t0 + t1;
            t0 = t1;
            t1 = sum;
        }
    }
    return sum;
}

int main()
{
    cout << fib(6) << endl; //inside the parenthesis is the term number
    cout << it_fib(6) << endl;
    return 0;
}