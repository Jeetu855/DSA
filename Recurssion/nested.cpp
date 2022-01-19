#include <iostream>
#include <string>
#include <vector>

using namespace std;
// recursive function taking recursive function as a parameter

int fun(int n)
{
    if (n > 100)
    {
        return (n - 10);
    }
    else
    {
        return fun(fun(n + 11));
    }
}

int main()
{
    cout << fun(95) << endl;
    return 0;
}