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

void RDisplay(struct Node *p) // O(n) both space and time
{
    if (p) // or (p!=nullptr) //*tail recursion
    {
        cout << p->data << "\n";
        RDisplay(p->next);
    }
}

void rDisplay(struct Node *p) // O(n) both space and time
{
    if (p) // or (p!=nullptr) //*head recursion
    {
        rDisplay(p->next);
        cout << p->data << "\n";
    }
}

int main()
{
    int A[]{3, 5, 7, 10, 15};
    Create(A, 5);
    // RDisplay(first);
    rDisplay(first); //*reverse order printing
    return 0;
}
