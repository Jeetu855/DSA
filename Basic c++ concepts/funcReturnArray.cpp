#include <iostream>

using namespace std;

int *fun(int n)
{
    int *p;
    p = new int[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    return p;
    delete p;
}

int main()
{

    int *ptr, size;
    size = 5;
    ptr = fun(5);
    for (int i = 0; i < 5; i++)
    {
        cout << ptr[i] << endl;
    }
    return 0;
}