#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
};
struct Node *first = nullptr;

void Create(int A[], int n)
{
    struct Node *t{nullptr}, *last{nullptr};
    int i{};

    first = new Node;
    first->data = A[0];
    first->previous = nullptr;
    first->next = nullptr;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next; // or =nullptr
        t->previous = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

void InsertatFirst(int x)
{
    struct Node *t = new Node;
    t->data = x;
    t->previous = nullptr;
    t->next = first;
    first->previous = t;
    first = t;
}

void InsertatPosition(struct Node *p, int position, int x)
{
    struct Node *t = new Node;
    t->data = x;
    for (int i = 0; i < position - 1; i++)
    {
        p = p->next;
    }
    t->next = p->next;
    t->previous = p;
    if (p->next)
    {
        p->next->previous = t;
    }
    p->next = t;
}
// min=O(1), max=O(n)
int main()
{
    int A[]{5, 7, 15, 18, 22};
    Create(A, 5);
    Display(first);
    InsertatFirst(1);
    Display(first);
    InsertatPosition(first, 3, 10);
    Display(first);
    return 0;
}