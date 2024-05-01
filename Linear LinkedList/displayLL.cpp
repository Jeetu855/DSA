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
struct Node *first; // global//*stores address of first node(called head node)

void Create(int A[], int n)
{ // n=number of elements
    int i{};
    struct Node *t, *last; // help to create a new node,is a temporary pointer
    first = new Node;
    last = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (i = 1; i < n; i++)
    { // i from 1 coz 0 already assigned to
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
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
    // struct Node *p = new Node;
    // *pseudo code------------------------------------------

    // p=first
    // while(p!=nullptr){
    //     printf("%d\n",p->data)
    //     p=p->next
    // }

    int A[]{3, 5, 7, 10, 15};
    Create(A, 5);
    Display(first);
    return 0;
}