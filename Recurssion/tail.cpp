#include <iostream>

using namespace std;
// *if recursive call is last statement in function
void fun(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1); // if function dosent do anything in return time //*also this is a recursive call and is the last statement of function
        // here it is pritning the num then calling fun(n-1), everything done during calling time, nothing done in returning time
        // its not waiting for response from next function like in factorial recusion
        //  fun(n-1)+n  //* not tail recursion since addition requires the value of fun(n-1) as well which can only be known at
        // *return time and not calling time so not tail recursion
    }
}

int main()
{
    fun(3);
    return 0;
} // for tail recursion better to writte it as loop coz loop takes less space complexity