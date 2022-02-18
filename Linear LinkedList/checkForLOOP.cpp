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
struct Node *second;
struct Node *third;

void Create(struct Node **p, int A[], int n)
{
    struct Node *last{nullptr}, *t{nullptr};

    *p = new Node;
    (*p)->data = A[0];
    (*p)->next = nullptr;
    last = (*p);

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

bool isLoop(struct Node *p)
{
    struct Node *q{nullptr}, *r{nullptr};
    q = r = p;
    do
    {
        q = q->next;
        r = r->next;
        r = r != nullptr ? r->next : r;
    } while (q && r && q != r);
    if (q == r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << boolalpha;
    struct Node *t1{nullptr}, *t2{nullptr};
    int A[]{3, 11, 15, 20, 28};
    int B[]{2, 7, 18, 22, 25};
    Create(&first, A, 5);
    Create(&second, B, 5);
    // *making first a loop LL
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    // Display(first);//*infinite loop
    // Display(second);
    cout << isLoop(first) << "\n";
    cout << isLoop(second) << "\n";
    return 0;
}