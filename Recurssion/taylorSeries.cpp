#include <iostream>

using namespace std;

double taylor(int x, int n)
{ // x is num n is power
    static double p = 1, f = 1;
    // p is numerator f is denominator
    double result{};
    if (n == 0)
    {
        return 1;
    }
    else
    {
        result = taylor(x, n - 1);
        p = p * x;
        f = f * n;
        return result + p / f;
    }
}

// *taylor iterative method

double it_taylor(int x, int n)
{
    double s = 1;
    int i;
    double numerator = 1, denominator = 1;
    for (i = 1; i <= n; i++)
    {
        numerator *= x;
        denominator *= i;
        s += numerator / denominator;
    }
    return s;
}

int main()
{
    cout << taylor(1, 10) << endl;
    cout << it_taylor(1, 10) << endl;
    return 0;
}
