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
struct Node *second;
struct Node *third;

void Create(struct Node **head, int A[], int n)
{
    struct Node *last{nullptr}, *t{nullptr};
    *head = new Node;
    (*head)->data = A[0];
    (*head)->next = nullptr;
    last = (*head);

    for (size_t i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "\n";
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last = new Node;
    third = new Node;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = nullptr;
    }
    if (p->data > q->data)
    {
        third = last = q;
        q = q->next;
        last->next = nullptr;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {

            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        }
        if (p->data > q->data)
        {

            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }
    if (p)
    {
        last->next = p;
        last = p;
        p = p->next;
        last->next = nullptr;
    }
    if (q)
    {
        last->next = q;
        last = q;
        q = q->next;
        last->next = nullptr;
    }
}

void Reverse(struct Node *p)
{
    struct Node *q{nullptr}, *r{nullptr};

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    third = q;
}

int main()
{
    int A[]{3, 11, 15, 20, 28};
    int B[]{2, 7, 18, 22, 25};
    Create(&first, A, 5);
    Create(&second, B, 5);
    Display(first);
    Display(second);
    Merge(first, second);
    Display(third);
    Reverse(third);
    Display(third);
    return 0;
}