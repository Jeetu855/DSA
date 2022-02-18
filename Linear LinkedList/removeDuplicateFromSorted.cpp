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

void RemoveDuplicate()
{ //* always O(n)
    struct Node *p = new Node;
    struct Node *q = new Node;
    q = first->next;
    p = first;
    while (q)
    {
        if (q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{
    cout << boolalpha;
    int A[]{3, 11, 11, 15, 20, 22};
    Create(A, 6);
    Display(first);
    RemoveDuplicate();
    Display(first);

    return 0;
}