#ifndef Stack_h
#define Stack_h
#include "Queue.h"

class Stack{
    private:
    int size;
    int top;
    struct Node **S;
    public:
    Stack(int size);
    ~Stack();
    void Push( Node *x);
    Node * Pop();
    int isEmptyStack();
    int isFullStack();
};

Stack::Stack(int size){
    this->size=size;
    this->top=-1;
    //this->S=(Node **)malloc(size*sizeof(Node*));
    this->S= new Node *[size];
}

Stack::~Stack(){
    delete S;
}

void Stack::Push(Node *x){
    if(this->top==this->size==-1){
        cout<<"Stack overflow\n";
    }else{
        this->top++;
        this->S[this->top]=x;
    }
}

Node * Stack::Pop(){
    Node *x=nullptr;
    if(this->top==-1){
        cout<<"Stack underflow\n";
    }else{
        x=this->S[this->top--];
    }
}

int Stack::isEmptyStack(){
    if(this->top==-1){
        return 1;
    }
    return 0;
}

int Stack::isFullStack(){
    return this->top=this->size-1;
}

#endif
