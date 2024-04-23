#include <iostream>
#include <string>
#include <vector>

using namespace std;
// * elements should not have a copy or we may get one of the copy
// *value that we are searching is called key

// *hashing takes constant time but space required is a lot
// *hasing best when searching something
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

void Append(struct Array *arr, int x)
{ // x is the value we r gonna append
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
};

void Insert(struct Array *arr, int index, int x)
{ // index is at which index we wanna put x
    int i;
    if (index >= 0 && index < arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
};

int Delete(struct Array *arr, int index)
{
    int x = 0, i; // value that is going to be deleted ,initialised to 0
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
};

int linear_search(struct Array *arr, int x)
{
    for (size_t i = 0; i < arr->length; i++)
    {
        if (x == arr->A[i])
        {
            return i;
        }
    }
    return -1; // invalid index if no match found
    // *best case O(1);//found elemen at first index
    // *worst case O(n);//found element at last index
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int improved_linear_search(struct Array *arr, int key)
{ // transposition
    for (size_t i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(arr->A[i], arr->A[i - 1]); // swap the element we found with the element b4 it
            // in the array to reduce the time for subsequent searches
            return i;
        }
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // Append(&arr, 10);
    // Display(arr);
    // Insert(&arr, 0, 10);
    // Display(arr);

    // cout << Delete(&arr, 0) << endl;
    // cout << "---------------" << endl;
    // Display(arr);
    // cout << linear_search(&arr, 6);
    // cout << "\n"
    //      << linear_search(&arr, 11);
    // cout << "\n";
    cout << improved_linear_search(&arr, 5); // index 3
    cout << "\n";
    cout << improved_linear_search(&arr, 5); // index 2

    return 0;
}