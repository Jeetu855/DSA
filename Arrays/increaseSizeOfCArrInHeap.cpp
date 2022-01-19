#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //*once array size is given it cannot be changed for the array in stack
    // *the array created on the heap, its size can be changed

    int *p = new int[5]; //previous size
    for (size_t i = 0; i < 5; i++)
        p[i] = i + 1;
    int *q = new int[10]; //updated size that we want
    for (size_t i = 0; i < 5; i++)
        q[i] = p[i]; //*copying data of p to q, after that delete p then make p=q
    // cout << p[2] << endl;
    // cout << q[2] << endl;
    delete[] p;  //removes the values inside the array(//*see debugger)
    p = q;       //this means array is pointed at by both p and q
    q = nullptr; //now only p points to the array
    // * now p array size is 10
    // ********the reason why array size cannot be changed is coz memory is contigious so the next memory might be used by something else
    // ********so no guarantee that the next consecutive locations are free or not

    return 0;
}