A heap is a complete binary tree meaning, if a binary tree is represented in an array
there should not be any empty spaces in the array
Node at index : i 
Left child at index : 2*i
Right child at index : 2*i + 1

Max heap : every element should be greater than or equal to its descendants
Duplicates are allowed, this is not a BST, its a heap

Height will always be logn since it is a complete binary tree


Inserting in a max heap

Insert the new element in the next free space in the array
Compare the newly inserted element with its parent
Time to insert = O(logn)

Time taken to create a heap = time taken to insert all elements
for 1 element insert time = O(log n)
for n elements insert time = O(n logn)
**Time to create a heap is O(nlogn)**

Deleting from max heap
From heap we can only delete the root(we  can delete highest priority element)
Copy the last element in the roots place
To make it max heap again, compare the children and swap to maintain the max heap
Then compare the child that is greater with the new parent
Compare the children again and go on until we get heap again

Keep deleting from max heap and storing deleted element at the last places, this creates a sorted array
This is heap sort
As we delete elements,  we get free space at the end of the array, use that space to store the deleted elements

Heap sort: 
1) Create heap of n elements (nlogn)
2) Go on deleting the elements from the heap 1 by 1 and start copying deleted element in free space we get(deletion = logn for 1 element)

Deleting all elements = nlogn
Time = 2nlogn
O(nlogn)


**Heapify : Faster method of creating heaps (O(n) time)**

Direction of adjustment in Insert is from bottom to top
Direction of adjustment in Delete is from top to bottom


Heap as priority Queue
Highest priority element deleted
Number itself is the priority
Decide beforehand if hte largest number is the priority or tha smallest number
Lets assume, larger the element, higher the priority
Insert and Delete take O(logn)