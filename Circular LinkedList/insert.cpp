#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *Head;

void Create(struct Node **p, int A[], int n)
{
    struct Node *last{nullptr}, *t{nullptr};
    *p = new Node;
    (*p)->data = A[0];
    (*p)->next = (*p); //*next should point on itself
    last = new Node;
    last = (*p);

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next; // or t->next=Head;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    cout << "\n";
}

void InsertatPosition(struct Node *h, int position, int x)
{
    struct Node *t = new Node;
    for (int i = 0; i < position - 1; i++)
    {
        h = h->next;
    }

    t->data = x;
    t->next = h->next;
    h->next = t;
}

void InsertatFirst(struct Node *h, int x)
{
    struct Node *t = new Node;

    t->data = x;
    t->next = h;
    while (h->next != Head)
    {
        h = h->next;
    }
    h->next = t;
    Head = t;
}

int main()
{
    int A[]{2, 3, 4, 5, 6};
    Create(&Head, A, 5);
    Display(Head);
    InsertatPosition(Head, 4, 11);
    Display(Head);
    InsertatFirst(Head, 15);
    Display(Head);
    return 0;
}