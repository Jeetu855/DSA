#include <iostream>

using namespace std;
// * size of hash table=value of max element+1
// * last index of hash table=max value

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        cout << arr.A[i] << endl;
};

void findDuplicate(struct Array arr)
{
    int lastDuplicate{};
    for (size_t i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == arr.A[i + 1] && arr.A[i] != lastDuplicate)
        {
            cout << "There is a duplicate at " << i << " and its value is " << arr.A[i] << "\n";
            lastDuplicate = arr.A[i];
        }
    }
}

void numberOfDuplicates(struct Array arr)
{

    int i{}, j{};
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            j = i + 1;
            while (arr.A[j] == arr.A[i])
            {
                j++;
            }
            cout << "The number " << arr.A[i] << " is appearing " << j - i << " times\n";
            i = j - 1;
        }
    }
}

int main()
{
    struct Array arr1
    {
        {3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 10, 10
    };
    // findDuplicate(arr1);
    numberOfDuplicates(arr1);
    return 0;
}