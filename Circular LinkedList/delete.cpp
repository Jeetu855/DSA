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

void DeleteFromPosition(int position)
{
    struct Node *p = new Node;
    struct Node *q = new Node;
    p = Head;
    for (int i = 0; i < position - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
}

void DeleteFirstNode()
{
    struct Node *p = new Node;
    p = Head;
    while (p->next != Head)
    {
        p = p->next;
    }
    p->next = Head->next;
    delete Head;
    Head = p->next;
}

int main()
{
    int A[]{2, 3, 4, 5, 6};
    Create(&Head, A, 5);
    Display(Head);
    DeleteFromPosition(4);
    Display(Head);
    DeleteFirstNode();
    Display(Head);
    return 0;
}