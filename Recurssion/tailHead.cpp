#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1);
    }
};

int fun1(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return (x + fun1(n - 1));
    }
}

int main()
{
    int x = 5;
    // fun(x);
    cout << fun1(x) << endl; //result 25

    return 0;
}