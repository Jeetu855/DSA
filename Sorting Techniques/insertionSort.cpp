#include <iostream>
#include <stdio.h>

using namespace std;
/*
inserting an element in a sorted array at a sorted position
like in a deck of cards we insert a new card in sorted position
start shifting the last element
divide array in 2 parts, 1st array only has first element of main array and 2nd array has the remaining elements
since only 1 element in first part, it is sorted, 2nd part of array not sorted, so take them out and put them in first part in sorted manner
1st pass, insert 1 element : max comparisons 1 and max swaps also 1
2nd pass, insert second element : max comparisons 2 and max swaps also 2
n-1 pass, insert the last element : max comparison (n-1) and max swaps also (n-1)//n-1 coz first element already part of array
max comparsions and max swaps = (n(n-1))/2 : time complexity is O(n^2)
In this intermediate result dont give any useful info like after first pass, it is not necessary that list is sorted from start or end
Insertion sort more compatible with linked list since we dont have to shift any elements is linked list
Adaptive since only takes O(n) for sorted list, no need of flag variable, also no swaps if already sorted
stable
*/

void InsertionSort(int A[], int n)
{
    int i{}, j{0}, x{};

    for (i = 1; i < n; i++) // loop for passes, also notice loop starts from 1 and not 0 because the first element already part of first part of array
    {
        j = i - 1; // comapring the element we want to insert with all elements in first part of list
        x = A[i];  // the element that we have to insert

        while (j > -1 && A[j] > x) // for shifting the elements
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;

    InsertionSort(A, n);
    for (auto x : A)
    {
        cout << x << " ";
    }
    return 0;
}