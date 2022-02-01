#include <iostream>
#include <string>
#include <vector>

using namespace std;
//*elements should be sorted(ascending)

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

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l < h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
    // * time =logn(worst case)base 2 of log
    // *best case=O(1);
    // in unsuccessful search=logn//*always logn//same for recursive
}

int RBinarySearch(int a[], int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return RBinarySearch(a, l, mid - 1, key);
        }
        else
        {
            return RBinarySearch(a, mid + 1, h, key);
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    cout << BinarySearch(arr, 5);
    cout << "\n";
    cout << BinarySearch(arr, 11);
    cout << "\n";
    cout << RBinarySearch(arr.A, 0, arr.length, 5);
    cout << "\n";
    cout << RBinarySearch(arr.A, 0, arr.length, 11);

    return 0;
}