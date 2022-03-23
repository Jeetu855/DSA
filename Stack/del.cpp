#include <iostream>
#include <stdlib.h>
#include<string.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = nullptr;

void Push(int x)
{
    Node *t = new Node;
    if (t)
    {
        t->data = x;
        t->next = top;
        top = t;
    }
    else
    {
        cout << "No space\n";
    }
}

int Pop()
{
    int x = -1;
    Node *t;
    if (top)
    {
        t = top;
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    char a[]="Hello";
    cout<<strlen(a)<<"\n";
    // Push(1);
    // Push(2);
    // Push(3);
    // Push(4);
    // Display();
    // Pop();
    // Pop();
    // Pop();
    // Display();
    // Pop();
    // Display();
    return 0;
}