#include <iostream>

#include <string>
#include <stdlib.h>

using namespace std;

// *2) reversing links

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

// void SlideReverse(struct Node *p) // O(n)
// {                                 //*this method better
//     struct Node *q{nullptr}, *r{nullptr};

//     while (p)
//     {
//         r = q;
//         q = p;
//         p = p->next;
//         q->next = r;
//     }

//     first = q;
// }

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

int main()
{
    int A[]{3, 11, 15, 20, 22};
    Create(A, 5);
    Display(first);
    Reverse(&first);
    Display(first);
    return 0;
}