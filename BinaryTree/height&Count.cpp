#include<iostream>
#include "Queue.h"

using namespace std;

Node *root = new Node;

void createTree(){
    Node* p;//temporary node
    Node* t;//temporary node
    int x;
    Queue q(10);
 
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
 
    while (!q.isEmpty()){
        p = q.dequeue();
 
        cout << "Enter value of left child " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
 
        cout << "Ente value of right child " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

int Count(Node *p){
    int x{0},y{0};

    if(p){
        x=Count(p->lchild);
        y=Count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int height(Node *p){
    
    int x{0},y{0};
    if(!p){
        return 0;
    }else{
        x=height(p->lchild);
        y=height(p->rchild);
    }
    if(x>y){
        return x+1;
    }else{
        return y+1;
    }
}

int sumOfElements(Node *p){
    int x{0},y{0};

    if(p){
        x=sumOfElements(p->lchild);
        y=sumOfElements(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

int countDegreeTwoNodes(Node *p){
        int x{0},y{0};

    if(p){
        x=countDegreeTwoNodes(p->lchild);
        y=countDegreeTwoNodes(p->rchild);
        if(p->lchild && p->rchild){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}

int countLeafNodes(Node *p){
    int x{0},y{0};
    if(p){
        x=countLeafNodes(p->lchild);
        y=countLeafNodes(p->rchild);
        if(p->lchild==nullptr && p->rchild==nullptr){
            return x+y+1;
        }else{
            return x+y;
        }
        return 0;
    }
}

int countInternalNodes(Node *p){
    int x{0},y{0};
    if(p){
        x=countInternalNodes(p->lchild);
        y=countInternalNodes(p->rchild);
        if(p->lchild==nullptr || p->rchild==nullptr){
            return x+y+1;
        }else{
            return x+y;
        }
        return 0;
    }
}

int countDegreeOndeNodes(Node *p){ // for this we need to XOR
    int x{0},y{0};
    if(p){
        x=countDegreeOndeNodes(p->lchild);
        y=countDegreeOndeNodes(p->rchild);
        // if((p->lchild==nullptr && p->rchild!=nullptr)|| (p->lchild!=nullptr && p->rchild==nullptr))
        if(p->lchild!=nullptr ^ p->rchild!=nullptr){ // ^ symbol used for xor
            return x+y+1;
        }else{
            return x+y;
        }
        return 0;
    }
}

int main(){
    createTree();

    cout<<"Count :";
    cout<<Count(root);
    cout<<"\n";

    cout<<"Height :";
    cout<<height(root);
    cout<<"\n";

    return 0;
}