#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int A[], int n)
{
    int i{}, j{}, k{};
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

void BubbleSort(int A[], int n)
{
    int flag{};
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - 1 - i; j++)
        {
            flag = 0;
            if (A[j] > A[j + 1])
            {
                swap(&A[j + 1], &A[j]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "Sorted\n";
            break;
        }
    }
}

void InsertionSort(int A[], int n)
{
    int i{}, j{0}, x{};
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j{};
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    int B[] = {3, 7, 9, 10, 11, 15, 22, 24, 31, 32};

    BubbleSort(A, n);
    BubbleSort(B, n);

    // for (auto x : A)
    // {
    //     cout << x << " ";
    // }

    int C[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    cout << "\n";
    SelectionSort(C, n);
    // for (auto x : C)
    // {
    //     cout << x << " ";
    // }

    int D[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    cout << "\n";
    InsertionSort(D, n);
    // for (auto x : D)
    // {
    //     cout << x << " ";
    // }

    int E[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT32_MAX};
    cout << "\n";
    QuickSort(E, 0, 10);

    for (auto x : E)
    {
        cout << x << " ";
    }
    return 0;
}