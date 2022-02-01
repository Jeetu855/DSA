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
//merging sorted array
// result is sorted merged array
struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i{}, j{}, k{};
    struct Array *arr3 = new Array();
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k] = arr1->A[i]; //*first assign then increment
            i++;
            k++;
        }
        else
        {
            arr3->A[k] = arr2->A[j];
            k++;
            j++;
        }
    }
    for (; i < arr1->length; i++) //*for leftover element
    {
        arr3->A[k] = arr1->A[i];
        k++;
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k] = arr2->A[j];
        k++;
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1
    {
        {2, 6, 10, 15, 25}, 10, 5
    };
    struct Array arr2
    {
        {3, 4, 7, 18, 20}, 10, 5
    };
    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3); //call by value so first derefrence it
    return 0;
}