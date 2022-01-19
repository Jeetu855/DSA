#include <iostream>
#include <string>
#include <vector>

using namespace std;
// *if recursive call is last statement in function
void fun(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1); //if function dosent do anything in return time //*also this is a recursive call and is the last statement of function
        //here it is pritning the num then calling fun(n-1)
        // its not waiting for response from next function like in factorial recusion
    }
}

int main()
{
    fun(3);
    return 0;
} //for tail recursion better to writte it as loop coz loop takes less space complexity