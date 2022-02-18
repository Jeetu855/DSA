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

int main()
{
    // struct Node *p;
    // p = new Node;
    // p->data = 10;
    // p->next = nullptr;

    struct Node *p, *q;
    p = new Node;
    p->data = 10;
    p->next = q;

    return 0;
}