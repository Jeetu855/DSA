#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

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
    last = new Node;
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

// *insert before first element

void InsertatFirst(struct Node **p, int x) // O(1)
{
    /* double pointer
 (**p). This allows the function to modify the actual head
 pointer stored in the memory location pointed to by p.
 This is necessary for insertion at the beginning, as
 the new node becomes the new head.*/

    /*
    single pointer (*p). This function can only access
    the data pointed to by the head pointer, not the
    head pointer itself. Modifying the head pointer
    within this function would require additional
    logic to update the pointer stored elsewhere.*/
    struct Node *t = new Node;
    t->data = x;
    t->next = *p;
    *p = t; // modifying the head node itself so need pointer to it
};

// *inset at a position

void InsertatPosition(int x, int position) // O(n)//*depends on position
{
    // minimum=O(1) max=O(n)
    struct Node *p{nullptr}, *t{nullptr};
    // p for moving throught LL and t to insert at given position
    p = new Node;
    t = new Node;
    t->data = x;
    p = first;
    for (int i = 0; i < position - 1; i++)
    {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
}

void InsertinSorted(int x) // min=O(1), max=O(n)
{
    struct Node *p = new Node;
    struct Node *q = nullptr;

    p = first;
    while (p && p->data < x)
    {
        q = p;
        p = p->next;
    }
    struct Node *t = new Node;
    t->data = x;
    t->next = q->next;
    q->next = t;
};

int main()
{
    int A[]{3, 11, 15, 22};
    Create(A, 4);
    Display(first);
    // InsertatFirst(&first,1);
    // Display(first);
    // InsertatPosition(18, 4);
    // Display(first);
    InsertinSorted(18);
    Display(first);
    return 0;
}