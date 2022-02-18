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

bool isSorted(struct Node *p)
{

    int x = -32768; // lowest val of 16 bit int

    while (p)
    {
        if (p->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

int main()
{
    cout << boolalpha;
    int A[]{3, 11, 15, 22, 26};
    int B[]{3, 17, 15, 22, 26};
    Create(B, 5);
    // Create(B, 5);
    Display(first);
    cout << isSorted(first) << "\n";

    return 0;
}