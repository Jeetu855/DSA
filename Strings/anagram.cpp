#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
//*anagram are set of strings formed using same set of characters
int main()
{
    // *first check if they have same size
    // *if they have diffrent size then they cant be anagrams
    char A[] = "decimal";
    char B[] = "medical";
    int i{};
    int H[26]{}; //*hash table
    for (i = 0; A[i] != '\0'; i++)
    {
        H[(A[i] - 97)] += 1;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97] -= 1;
        if (H[B[i] - 97] < 0)
        {
            cout << "Not an anagram\n";
        }
    }
    if (B[i] == '\0')
    {
        cout << "It is an anagram\n";
    }

    // another eg
    // *verbose and observe where alphabets are repeating
    // *above technique will work
    return 0;
}