#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    // *method 1:taking an auxilarry array
    // char A[] = {"javascript"};
    // char B[11]{};
    // int i{}, j{};
    // for (i = 0; A[i] != '\0'; i++)
    // {
    // }
    // i = i - 1;
    // for (j = 0; i >= 0; i--, j++)
    // {
    //     B[j] = A[i];
    // }
    // B[j] = '\0';
    // cout << A << "\n";
    // cout << B << "\n";

    // *method2;
    char A[]{"javascript"};
    int i{}, j{};
    for (j; A[j] != '\0'; j++)
    {
    }
    j = j - 1; //*-1 to remove numm char space
    for (i = 0, j; i < j; i++, j--)
    {
        char temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    cout << A << "\n";
    return 0;
}