#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    // *method 1 using hash table
    char A[] = "finding";
    // *size of hash table 26-from 0 to 25 index
    // *all alphabets lower case so subtract -97 to fit in 0-25

    int H[26]{}, i{};
    for (i; A[i] != '\0'; i++)
    {
        H[A[i] - 97] += 1; //*that index in hash table is incrementted
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("%c ", i + 97);
            printf("%d\n", H[i]);
        }
    }
    return 0;
}