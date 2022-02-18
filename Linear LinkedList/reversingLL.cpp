#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

// **after deleting , reallocate memory as well

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first;

void Create(int A[], int n)
{
    struct Node *last{nullptr}, *t{nullptr};
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p) // O(n) both space and time
{
    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    cout << "\n";
};

// *1 reversing elements(data)
// *2 reversing links(prefered)

// *reversing elements
// method 1 (using an array)

void Reverse(struct Node *p)
{ // takes space for array and time is O(n)
    int A[4]{}, i{};
    while (p) // copy from LL to array
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while (p) // copy from array to LL
    {
        p->data = A[i];
        i--;
        p = p->next;
    }
}

int main()
{

    int A[]{3, 6, 9, 12};
    Create(A, 4);
    Display(first);
    Reverse(first);
    Display(first);
    return 0;
}