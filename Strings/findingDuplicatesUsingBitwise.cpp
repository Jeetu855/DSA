#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    // cout << sizeof(int) << "\n";//*4bytes

    char A[] = "finding";
    int H = 0, x = 0, i{}; //*all bits set to 0
    for (i = 0; A[i] != '\0'; i++)
    {
        x = 1;                //*
        x = x << (A[i] - 97); //() are necessary
        //*left shift 1 to position
        if ((x & H) > 1) //*since > has higher precendece
        {                // masking //*'anding'
            printf("%c is duplicate\n", A[i]);
        }
        else
        { //*merging
            H = x | H;
        }
    }

    return 0;
}