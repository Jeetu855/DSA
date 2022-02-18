#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} * first, *second, *third;

void create(Node **p, int *A, int n)
{
    Node *t, *last;
    *p = new Node;
    (*p)->data = A[0];
    (*p)->next = NULL;
    last = *p;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void concat(Node *p, Node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int B[7] = {11, 12, 13, 14, 15, 16, 17};
    create(&first, A, 5);
    create(&second, B, 7);
    display(first);
    display(second);
    concat(first, second);
    display(third);
    return 0;
}