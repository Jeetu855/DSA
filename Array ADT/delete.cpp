#include <iostream>

using namespace std;
// * while deleteting if we delete an element in the middle of an array
// * we dont leave the space blank,instead we shift all the elements

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

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // Append(&arr, 10);
    // Display(arr);
    // Insert(&arr, 0, 10);
    // Display(arr);

    cout << Delete(&arr, 0) << endl;
    cout << "---------------" << endl;
    Display(arr);
    return 0;
}