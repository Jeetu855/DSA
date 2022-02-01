#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
        cout << arr.A[i] << " ";
    cout << "\n";
};

void Reverse(struct Array *arr)
{ //using an auxilarry array
    int b[10]{};
    for (size_t i = arr->length - 1, j = 0; i >= 0, j < arr->length; i--, j++)
    {
        b[j] = arr->A[i]; //O(n)
    }
    for (size_t i = 0; i < arr->length; i++)
        arr->A[i] = b[i]; //O(n)
                          //*total =2n
}

void Better_Reverse(struct Array *arr)
{
    //no auxilaryy array
    for (size_t i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    } //O(n)
    // *better as less time
}

int main()
{
    struct Array arr
    {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10
    };
    Display(arr);
    Reverse(&arr);
    Display(arr);
    Better_Reverse(&arr);
    Display(arr);
    return 0;
}