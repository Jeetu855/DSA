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

int Count(struct Node *p) // O(n);
{
    int c{}; // space complexity=O(1)
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int RCount(struct Node *p) // recusion uses stack
{
    // space complexity=O(n) coz recursion uses stack
    if (!p) // same as (p==nullptr)
    {
        return 0;
    }
    else
    {
        return RCount(p->next) + 1; // addition done at return time
    }
}

int main()
{
    int A[]{2, 5, 9, 11, 15};
    Create(A, 5);
    cout << Count(first) << "\n";
    cout << RCount(first) << "\n";
    return 0;
}