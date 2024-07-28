
#include<stdio.h>
#include "Queue.h"

using namespace std;

Node* root = new Node;
 
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
 
    while (! q.isEmpty()){
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
 
void preorder(Node* p){
    if (p){
        cout << p->data << ", " << flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
 
void inorder(Node* p){
    if (p){
        inorder(p->lchild);
        cout << p->data << ", " << flush;
        inorder(p->rchild);
    }
}
 
void postorder(Node* p){
    if (p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}
 
 
int main() {
 
    createTree();
    
    cout<<"Preorder Traversal: ";
    preorder(root); //* at a given moment, number of activation records will be height + 2
    cout <<"\n";
    
    cout<<"Inorder Traversal: ";
    inorder(root); //* at a given moment, number of activation records will be height + 2
    cout <<"\n";
    
    cout<<"Postorder Traversal: ";
    postorder(root); //* at a given moment, number of activation records will be height + 2
    cout <<"\n"; 
 
    return 0;
}