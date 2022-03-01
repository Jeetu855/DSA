#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
};

Node *head;

void Create(int A[],int n){
    struct Node *last=new Node;
    struct Node *t{nullptr};

    head=new Node;
    head->data=A[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
    head->prev=last;
};

void Display(Node *p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<"\n";
}

int main(){
    int A[]{2,5,7,11,16};
    Create(A,5);
    Display(head);
    return 0;
}