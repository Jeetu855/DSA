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

void DeleteFirst()
{
    struct Node *p = first;
    first = first->next;
    delete p;
    if (p)
    {
        first->previous = nullptr;
    }
}

void DeleteatPosition(struct Node *p, int position)
{
    for (int i = 0; i < position - 1; i++)
    {
        p = p->next;
    }
    p->previous->next = p->next;
    if (p->next)
        p->next->previous = p->previous;
    delete p;
}

int main()
{
    int A[]{5, 7, 15, 18, 22};
    Create(A, 5);
    Display(first);
    DeleteFirst();
    Display(first);
    DeleteatPosition(first,3);
    Display(first);
    return 0;
}