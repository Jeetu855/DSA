#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // initilisation
    // *method 1
    int arr[3][4]; //3 rows 4 cols

    // *method 2
    int *a[3]; //array of 3 pointers
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
    int **A; //pointer to a pointer which is pointing to an int

    A = new int *[3]; //array of pointer in heap
    // * A=(int **)malloc(3*sizeof(int *));
    //*  A[0]=(int *)malloc(4*sizeof(int));
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    // *accessing data
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << endl; //will have garbage vals
        }
    }

    return 0;
}