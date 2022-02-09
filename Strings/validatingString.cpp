#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

bool Valid(char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!(name[i] >= 65 && name[i] <= 90) && !(name[i] >= 97 && name[i] <= 122) && !(name[i] >= 48 && name[i] <= 57))
            return false;
    }
    return true;
}
int main()
{
    cout << boolalpha;
    char *name = "Ani?321";

    cout << Valid(name) << "\n";
    return 0;
}
