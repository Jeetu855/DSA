#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    int length;
    char name[] = "Jitesh";
    int i{};
    for (i = 0; name[i] != '\0'; i++)
    {
    }
    cout << "The length is " << i << "\n";

    char A[] = "JITESH";
    int j{};
    for (j = 0; A[j] != '\0'; j++)
    {
        A[j] += 32;
    }
    cout << A << "\n";

    return 0;
}