#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sumN(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (sumN(n - 1) + n);
    }
}

int sum(int n)
{
    int s{}, i = 0;
    for (i = 0; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}
// *better to use n(n+1)/2 or simple for loop coz less time and space

int main()
{
    cout << sumN(5) << endl;
    cout << sum(5) << endl;

    return 0;
}