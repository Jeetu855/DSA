#include <iostream>
#include <stdio.h>

using namespace std;

/*
compares adjacent pair of elements at the same time
after first pass(iterating through all the pairs 1 time) largest element is sorted
if n elements then
in first pass (n-1) comparisons; atmost (n-1) swaps; largest sorted
in second pass (n-2) comparisons; after second pass, 2nd largest element also sorted; atmost (n-2) swaps
in last pass  1 comparison; all sorted; atmost 1 swap
maximum (n-1) pass
comparison : O(n^2)
swaps : O(n^2)
lighter elements slowly move up like bubbles
if already sorted : time O(n)
bubble sort is adaptive, we made it adaptive using a flag variable
stable
*/

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n)
{
    int flag = 0;
    for (size_t i = 0; i < n - 1; i++) //* i<n-1 and not i<n because no need to perform any operation on last element(n is size of array)
    {                                  // outer for loop for pass: 1st pass: 2nd pass and so on
        for (size_t j = 0; j < n - 1 - i; j++)
        {
            flag = 0;
            // inner for loop for comparison and swaps
            // *since after each pass, list getting sorted from end, number of comaprisons should also reduce, so, j<n-1-i
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "Already sorted\n";
            break;
        }
        // after 1st pass, check if flag=0, if yes then return already sorted
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

    return 0;
}