#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    // initilisation
    // *method 1
    int arr[3][4]; // 3 rows 4 cols

    // *method 2
    int *a[3]; // array of 3 pointers
    // cout << a[0] << endl;
    // cout << a[1] << endl;
    // cout << a[2] << endl;
    // cout << a << endl;
    a[0] = new int[4];
    a[1] = new int[4];
    a[2] = new int[4];
    // eg:we have to store a value in 1,2
    a[1][2] = 15;

    // *method 3 (everything in heap) //only double ptr in stack
    int **A; // pointer to a pointer which is pointing to an int

    A = new int *[3]; // array of pointer in heap
    //*  A=(int **)malloc(3*sizeof(int *));
    //*  A[0]=(int *)malloc(4*sizeof(int));
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    // *accessing data
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << endl; // will have garbage vals
        }
    }

    //**************Static vs Dynamic Array

    int Arr[5]{2, 4, 6, 8, 10};
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int *p{nullptr}; //* the variable p is in stack and the array is in heap
    p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for (size_t i = 0; i < 5; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << "\n";

    for (size_t i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}
//! Size of array in c++ can be decided at run time as well but in c it needs to be provided at compile time
// This array in stack only not heap