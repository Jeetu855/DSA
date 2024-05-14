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

void Create(struct Node **p, int A[], int n)
{
    struct Node *last{nullptr}, *t{nullptr};
    *p = new Node;
    (*p)->data = A[0];
    (*p)->next = nullptr;
    last = (*p);
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

void Reverse(struct Node **head)
{
    struct Node *q{nullptr}, *r{nullptr}, *current = *head;
    while (current)
    {
        r = q;
        q = current;
        current = current->next;
        q->next = r;
    }
    *head = q;
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
    else
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
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }
    // *if one LL's elements finished but other LL's elements remaining then
    while (p)
    {
        last->next = p;
        last = p;
        p = p->next;
        last->next = nullptr;
    }
    while (q)
    {
        last->next = q;
        last = q;
        q = q->next;
        last->next = nullptr;
    }
}

int main()
{
    int A[]{3, 11, 15, 20, 28};
    int B[]{2, 7, 18, 22, 25};
    Create(&first, A, 5);
    Create(&second, B, 5);
    Display(first);
    Display(second);
    // Reverse(&first);
    // Reverse(&second);
    // Display(first);
    // Display(second);
    Merge(first, second);
    Display(third);

    return 0;
}