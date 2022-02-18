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

// *deleting first node
// O(1);
void DeleteFirst()
{
    struct Node *p = new Node;
    p = first;
    first = first->next;
    int x = p->data;
    delete p;
}

// *deleting from given position
// O(n), min=O(1), max=O(n)
void DeletePosition(int position)
{ // move for position-1 times
    struct Node *p = new Node;
    p = first;
    struct Node *q = new Node;
    q = nullptr;
    for (int i = 0; i < position - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    int x = p->data;
    delete p;
}

int main()
{
    int A[]{3, 11, 15, 22, 26};
    Create(A, 5);
    Display(first);
    DeleteFirst();
    Display(first);
    return 0;
}