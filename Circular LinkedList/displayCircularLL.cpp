#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *Head;
//* we use do while loop coz
//*initiallly head=p so if we use while loop it wont enter the loop
// * thats why we use do-while so it changes the condition then goes into loop

void Create(struct Node **p, int A[], int n)
{
    struct Node *last{nullptr}, *t{nullptr};
    *p = new Node;
    (*p)->data = A[0];
    (*p)->next = (*p); //*next should point on itself
    last = new Node;
    last = (*p);

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next; // or t->next=Head;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    cout << "\n";
}

void RDisplay(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
}

int main()
{
    int A[]{2, 3, 4, 5, 6};
    Create(&Head, A, 5);
    Display(Head);
    RDisplay(Head);
    // struct Node *t1 = Head->next;
    // struct Node *t3 = Head->next->next;
    // struct Node *t2 = Head->next->next->next->next;
    // cout << Head << "\n";
    // cout << t1->next << "\n";
    // cout << t3 << "\n";
    // cout << t2->next << "\n";
    return 0;
}