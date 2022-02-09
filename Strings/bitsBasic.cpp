#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    char h = 'A';
    h = h << 1;
    // cout << h << "\n";
    // printf("%d\n", h);
    char a = 10, b = 6, c{}; //*a=1010,b=0110,c=0010
    c = a & b;               //*therefore c=2;
    // cout << static_cast<int>(c) << "\n";
    // printf("%d\n", c);
    char d = a | b; //*1110=14
    // cout << static_cast<int>(d) << "\n";
    // printf("%d\n", d);

    // *masking(perform 'and' to check if on)//checking if the bit is on
    // *merging (perform 'or')//setting the bit on
    return 0;
}