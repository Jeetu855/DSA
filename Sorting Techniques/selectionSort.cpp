#include <iostream>
#include <stdio.h>

using namespace std;

/*
n-1 passes like insertion and bubble sort
after each pass 1 element sorted like bubble sort
after 1st pass, smallest element in place
select smallest element and swap it with element at current index
in first pass, max comparisons (n-1) and 1 swap
second pass, max (n-2) comparisons and 1 swap
last pass, max 1 comparison and 1 swap
total comparisons = O(n^2)
//*max swaps = O(n) : so performs least number of swaps in worst case
not adaptive
not stable
*/

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Selectionsort(int A[], int n)
{
    int i{}, j{}, k{};
    for (i = 0; i < n - 1; i++) // for passes
    {
        for (j = k = i; j < n; j++) //  for swapping, once this for loop ends, k will be pointing on the smallest element
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

    Selectionsort(A, n);
    for (auto x : A)
    {
        cout << x << " ";
    }
    return 0;
}