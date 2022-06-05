#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *front{nullptr},*rear{nullptr};

void enqueue(int x){
    Node *t=new Node;
    if(t){
        t->data=x;
        t->next=nullptr;
        if(front==nullptr){
            front=rear=t;
        }else{
            rear->next=t;
            rear=t;
        }
    }else{
        cout<<"Heap memory full\n";
    }
}

int dequeue(){
    int x=-1;
    if(front){
        Node *p=new Node;
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }else{
        cout<<"Queue is empty\n";
    }
    return x;
}

void Display(){
    Node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    cout<<dequeue()<<"\n";
    cout<<dequeue()<<"\n";
    cout<<dequeue()<<"\n";
    cout<<dequeue()<<"\n";
    Display();
    return 0;
}