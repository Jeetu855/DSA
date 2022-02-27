#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
    struct Node *previous;
    int data;
    struct Node *next;
};
struct Node *first=nullptr;

void Create(int A[],int n){
    struct Node *t{nullptr},*last{nullptr};
    int i{};

    first=new Node;
    first->data=A[0];
    first->previous=nullptr;
    first->next=nullptr;
    last=first;

    for(i=1;i<n;i++){
       t=new Node;
       t->data=A[i];
       t->next=last->next;//or =nullptr
       t->previous=last;
       last->next=t; 
       last=t;
    }
}

void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }

    return len;
}

int main(){
    int A[]{5,7,15,18,22};
    Create(A,5);
    Display(first);
    cout<<Length(first)<<"\n";
    return 0;
}