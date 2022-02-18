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

int Add(struct Node *p)
{
    int sum{};
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
};

int main()
{
    int A[]{2, 5, 9, 11, 15};
    Create(A, 5);
    cout << Add(first) << "\n";
    return 0;
}