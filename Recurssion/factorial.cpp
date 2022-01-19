#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (fact(n - 1) * n);
    }
}
// *can be done with loop as well

int fact_loop(int n)
{
    int s{1}, i = 1;
    for (i = 1; i <= n; i++)
    {
        s = s * i;
    }
    return s;
}

int main()
{
    cout << fact(5) << endl;
    cout << fact_loop(5) << endl;
    return 0;
}