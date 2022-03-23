#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = nullptr;
//*here if heap is full then stack is full otherwise sice LL
// *is dynamic size there is no set size

void Push(int x)
{
    Node *t = new Node;
    if (t == nullptr)
    { // heap memory is full cannot add new node
        cout << "Stack is full\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop()
{
    int x = -1;
    Node *t;
    if (top == nullptr)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        t = top;
        top = top->next;
        x=t->data;
        delete t;
    }
    return x;
}

void Display(){
    Node *p;
    p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Display();
    
    cout<<Pop()<<"\n";
    Display();
    return 0;
}