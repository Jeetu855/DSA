#include <iostream>
#include <vector>
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
//*move to head
struct Node *ISearch(struct Node *p, int key)
{
    struct Node *q{nullptr};
    while (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
};

void Display(struct Node *p) // O(n) both space and time
{
    while (p != nullptr)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
};

int main()
{
    int A[]{2, 5, 22, 11, 15};
    Create(A, 5);
    Display(first);
    ISearch(first, 11);
    Display(first); // now 11 is first
    return 0;
}