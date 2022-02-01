#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int *a, int *b);

class Array
{
private:
    int *A;
    int length;
    int size;

public:
    Array(int l, int s);
    ~Array();
    void Display();
    void Insert(int x, int index);
    void Append(int x);
    void Delete(int index);
    bool isSorted();
    void InsertInSorted(int x);
    void Reverse();
    void betterReverse();
    int BinarySearch(int key);
    Array *Merge(Array arr);
};

Array::Array(int l, int s)
{
    length = l;
    size = s;
    A = new int[s];
    for (size_t i = 0; i < l; i++)
        A[i] = i + 1;
    for (size_t i = l; i < s; i++)
        A[i] = 0;
}

Array::~Array()
{
    delete[] A;
}

void Array::Display()
{
    for (size_t i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::Append(int x)
{
    if (length < size)
    {
        A[length] = x;
        length++;
    }
}

void Array::Insert(int x, int index)
{
    if (length < size && index < length)
    {
        for (size_t i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

void Array::Delete(int index)
{
    if (index < length)
    {
        int x{}, i{};
        x = A[index];
        // cout << A[index] << "\n";
        for (i = index; i < length; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
}

bool Array::isSorted()
{
    for (size_t i = 0; i < length - 2; i++)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
    }
    return true;
    cout << "\n";
}

void Array::InsertInSorted(int x)
{
    int i = length - 1;
    if (length < size)
    {
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }
}

void Array::Reverse()
{
    int b[length]{};
    for (size_t i = length - 1, j = 0; i >= 0, j < length; i--, j++)
    {
        b[j] = A[i];
    }
    for (size_t i = 0; i < length; i++)
    {
        A[i] = b[i];
    }
}

void Array::betterReverse()
{
    for (size_t i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(A[i], A[j]);
    }
}

int Array::BinarySearch(int key)
{
    int l = 0;
    int h = A[length - 1];
    int mid{};
    while (l < h)
    {
        mid = (l + h) / 2;
        if (A[mid] == key)
        {
            return mid;
        }
        else if (A[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

Array *Array::Merge(Array arr)
{
    Array *arr_1 = new Array(length + arr.length, size);
    int i, j, k;
    i = j = k = 0;
    while (i < length && j < arr.length)
    {
        if (A[i] < arr.A[j])
        {
            arr_1->A[k] = A[i];
            k++, i++;
        }
        else
        {
            arr_1->A[k] = arr.A[j];
            k++, j++;
        }
    }
    for (; i < length; i++)
    {
        arr_1->A[k] = A[i];
        k++;
    }
    for (; j < arr.length; j++)
    {
        arr_1->A[k] = arr.A[j];
        k++;
    }

    return arr_1;
}

int main()
{
    cout << boolalpha;
    Array arr1{6, 10};
    Array arr2{5, 10};
    Array arr3{10, 10};
    Array arr4{4, 10};
    Array arr5{5, 10};
    // arr1.Display();
    // arr1.Append(11);
    // arr1.Display();
    // arr1.Insert(15, 3);
    // arr1.Display();
    // arr1.Delete(2);
    // arr1.Display();
    // cout << arr1.isSorted();
    // cout << "\n";
    // cout << arr2.isSorted();
    // cout << "\n";
    // arr2.Append(11);
    // arr2.Append(15);
    // arr2.Display();
    // arr2.InsertInSorted(8);
    // arr2.Display();
    // arr3.Display();
    // arr3.Reverse();
    // arr3.Display();
    // arr3.betterReverse();
    // arr3.Display();
    // cout << arr3.BinarySearch(9) << "\n";
    // cout << arr3.BinarySearch(12);

    Array *arr = arr4.Merge(arr5);
    arr->Display();
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}