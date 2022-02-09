#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    char A[] = {"How are you"};
    int i{}, vcount{}, ccount{};
    // for (i = 0; A[i] != 32; i++)//* print till first space
    //     cout << A[i] << " ";

    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'A' || A[i] == 'e' || A[i] == 'E' || A[i] == 'i' || A[i] == 'I' || A[i] == 'o' || A[i] == 'O' || A[i] == 'u' || A[i] == 'U')
        {
            vcount++;
        }
        else if (A[i] >= 65 && A[i] <= 90)
        {
            ccount++;
        }
        else if (A[i] >= 97 && A[i] <= 122)
        {
            ccount++;
        }
    }
    cout << "Number of vowels is : " << vcount << "\n";
    cout << "Number of consonents is : " << ccount << "\n";

    // *count number of wrods
    // *number of words= number of spaces+1
    // * only applicable if 1 space is present

    int word{}, j{};
    for (j = 0; A[j] != '\0'; j++)
    {
        if (A[j] == 32) //* or if(A[j]==' ')
        {
            word++;
        }
    }
    cout << "Number of words is : " << word + 1 << "\n";

    // *but if we have continuous set of spaces its called white space
    // *so if we have white space

    int num_word{}, k{};
    char B[] = {"How are   u"};
    for (k = 0; B[k] != '\0'; k++)
    {
        if (B[k] == 32 && B[k - 1] != 32)
        {
            num_word++;
        }
    }
    cout << "Number of words is : " << num_word + 1 << "\n";

    return 0;
}