#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    char s[] = "Welcome"; //*== {'w','e','l','c','o','m','e','\0'}; //array size 8
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
    };
    cout << i << " is the length of string\n";

    return 0;
}