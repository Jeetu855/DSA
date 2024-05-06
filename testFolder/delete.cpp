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
            cout << "already sorted";
            break;
        }
    }
    cout << "\n";
}

void InsertionSort(int A[], int n)
{
    int i{}, j{}, x{};
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

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    int B[] = {3, 7, 9, 10, 11, 15, 22, 24, 31, 32};

    BubbleSort(A, n);
    BubbleSort(B, n);

    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << "\n";
    for (auto x : B)
    {
        cout << x << " ";
    }
    cout << "\n";

    int C[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    InsertionSort(C, 10);
    for (auto x : C)
    {
        cout << x << " ";
    }
    cout << "\n";
    int D[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    SelectionSort(D, n);
    for (auto x : D)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}