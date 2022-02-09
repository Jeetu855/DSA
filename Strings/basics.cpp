#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    char temp = 'a';
    // char temp="a";//*wrong
    // char temp=a;//*wrong
    // char temp='ab';//*wrong
    // cout << temp << "\n"; //a
    // printf("%d\n", temp); //97 ascii value
    // printf("%c\n", temp); //a

    char x[5]{'a', 'b', 'c', 'd', 'e'};
    char y[5]{'A', 'B', 'C', 'D', 'E'};
    char z[5]{65, 66, 67, 68, 69}; //same as above
    // for (size_t i = 0; i < 5; i++)
    //     cout << z[i] << " ";
    int score[10]{1, 2, 3, 4, 5};
    char name[10] = {'J', 'O', 'H', 'N'}; //* is array of characters
    cout << score << "\n";                //address
    cout << name << "\n";                 //value,as c++ treats array of characters as strings
    // printf("%c\n", name);//*some unicode

    // *\0 :string delimeter or end of string character or null char or string terminator

    printf("%d\n", name[4]); //ascii value of \0=0 and name[4] is null character
    // *without \0 its array of characters but with it its a string
    char name_string[10] = {'J', 'O', 'H', 'N', '\0'}; //*is a string
    cout << name_string << "\n";
    // * \0 also consumes space
    char name_str[] = "JOHN"; //* includes \0 at end and is a string
    printf("%s\n", name_str);
    printf("%s\n", name_string);
    // gets() == getlinc(cin,)//* smilar,gets in c
    return 0;
}