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

struct Array *Union(struct Array *arr1, struct Array *arr2) // logic same as merge
{
    int i{}, j{}, k{};
    struct Array *arr3 = new Array();
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++]; //*first assign then increment
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else // both r equal case
        {
            arr3->A[k++] = arr1->A[i++]; // copy only one element and increment both
            j++;
        }
    }
    for (; i < arr1->length; i++) //*for leftover element
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2) // logic same as merge
{
    int i{}, j{}, k{};
    struct Array *arr3 = new Array();
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else // both are equal case
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2) // logic same as merge
{
    int i{}, j{}, k{};
    struct Array *arr3 = new Array();
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++]; //*first assign then increment
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else // both equal case
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++) //*for leftover element
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
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
        {3, 4, 6, 7, 15, 18, 20}, 10, 7
    };
    struct Array *arr3, *arr4, *arr5;
    arr3 = Union(&arr1, &arr2);
    Display(*arr3);
    arr4 = Intersection(&arr1, &arr2);
    Display(*arr4);
    arr5 = Difference(&arr1, &arr2);
    Display(*arr5);
    return 0;
}