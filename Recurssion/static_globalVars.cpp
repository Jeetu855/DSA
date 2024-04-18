#include <iostream>

using namespace std;

int staticFun(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return staticFun(n - 1) + x;
    }
    return 0;
}

int fun(int n)
{
    if (n > 0)
    {
        return fun(n - 1) + n; // +n done at return time
    }
    return 0;
}

int main()
{
    int ans = fun(5);
    int ans2 = staticFun(5);
    cout << ans << "\n";
    cout << ans2 << "\n";
    return 0;
}