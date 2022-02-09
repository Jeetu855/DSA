#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    char A[]{"Painter"};
    char B[]{"Painter"};
    int i{}, j{};
    for (i, j; A[i] != '\0', B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
        {
            break;
        }
    }
    if (A[i] == B[j])
        cout << "Equal";
    else if (A[i] < B[j])
        cout << "String A comes first in dictionary\n";
    else
        cout << "String B comes first in dictionary\n";

    // *pallindrome
    // *reverse copy then compare
    return 0;
}