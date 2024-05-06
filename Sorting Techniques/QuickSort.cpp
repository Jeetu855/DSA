#include <iostream>
#include <stdio.h>

using namespace std;

/*
in a line of people where we need to arrange the line on height bases, we are the pivot since we need to make sure
people ahead of us are shorter and people behind us are taller than us
1 loop variable looking for elements larger than pivot and other loop variable looking for elements smaller then pivot

loop varibale starting from beginning of array looks for greater than or equal to elements and
loop variable iterating from end to beginning looks for elements smaller than pivot
swapping pivot with the element that is pointed at by second varibale that is looking for elements smaller than pivot
for sorted list takes O(n^2) time, can be sorted either in ascending or descending order
If partitioning done at leftmost or rightmost position then worst case for quick sort
1) Put pivot in place
2) Get partitions
3) Apply quick sort on partitions again
4) If a 1 partiotion has 1 element and other has remaining (n-1) elements then worst case for quick sort
5) This happens if list is sorted either in ascending or descending order and time is o(n^2)
Not adaptive
Best case time complexity is O(nlogn) if partitioning done in the middle
Worst case time complexity is O(n^2) when partitioning done at one end(already sorted)
Average time complexity is O(nlogn)
This is if first element is selected as pivot

If middle element selected as pivot
1) Best case when list already sorted = O(nlogn)
2) Worst case = O(n^2)
3) This happens cause partitioning happens at either begining or end in this case

By changing the pivot, performance of quicksort changes
Quick sort also called : Selection Exchange/Partition Exchange sort
*/
// *In selection sort, we pick a position and find an element for than position
// *In quick sort, we pick element and find position for that element

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    swap(&A[l], &A[j]); // after completion of partitioning, swap pivot with j to put pivot in position
    return j;
}

void Quicksort(int A[], int l, int h)
{
    int j;
    if (l < h) // check if atleast 2 elements
    {
        j = partition(A, l, h); // get the index of pivot, partitioning position
        Quicksort(A, l, j);     // the last element acts as infinity
        Quicksort(A, j + 1, h);
    }
}

int main()
{

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT32_MAX}, n = 11;

    Quicksort(A, 0, 10);

    for (auto x : A)
    {
        cout << x << " ";
    }
    return 0;
}