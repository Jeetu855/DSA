#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    // *A=65, a=97,a-A=32, all alphabets difference is 32

    char A[] = "WELCOME"; //* include \0
    int i;
    for (i = 0; A[i] != '\0'; i++)
        A[i] += 32;
    cout << A << "\n";

    char B[] = "welcome";
    int j;
    for (j = 0; B[j] != '\0'; j++)
        B[j] -= 32;
    cout << B << "\n";

    // *toggle
    char C[] = "wElCome";
    int k;
    for (k = 0; C[k] != '\0'; k++)
    {
        if (C[k] >= 65 && C[k] <= 90) //if uppercase
        {
            C[k] += 32;
        }
        else if (C[k] >= 97 && C[k] <= 122)
        {
            C[k] -= 32;
        }
    }
    cout << C << "\n";
    printf("%s\n", C);

    return 0;
}