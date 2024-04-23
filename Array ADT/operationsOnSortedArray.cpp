#include <iostream>

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

bool isSorted(struct Array arr)
{
    for (size_t i = 0; i < arr.length - 2; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
    cout << "\n";
}

void InsertInSorted(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
    {
        return; //*no space left to insert
    }
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    };
    arr->A[i + 1] = x;
    arr->length++;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Rearrange(struct Array *arr) // negative elements on left and positive on right
{
    int i{0}, j{arr->length - 1};
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

int main()
{
    cout << boolalpha;
    struct Array arr1
    {
        {4, 8, 13, 16, 20, 25, 28, 33}, 10, 8
    };
    // cout << isSorted(arr1) << "\n";
    struct Array arr2
    {
        {-6, 3, -8, 10, 5, -7, -9, 12, -4, 2}, 10, 10
    };
    struct Array arr3
    {
        {2, 3, 5, 10, 15}, 10, 5
    };
    // InsertInSorted(&arr3, 11);
    // Display(arr3);
    // Rearrange(&arr2);
    // Display(arr2);
    cout << isSorted(arr1) << "\n";
    cout << isSorted(arr2) << "\n";
    cout << isSorted(arr3) << "\n";
    return 0;
}