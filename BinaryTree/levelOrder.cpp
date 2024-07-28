#include "Queue.h"
#include "Stack.h"

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
 
        cout << "Enter value of right child " << p->data << ": " << flush;
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

void levelOrder(Node *root){
    Queue q(100);
    cout<<root->data<<", ";
    q.enqueue(root);

    while(!q.isEmpty()){
        root=q.dequeue();
        if(root->lchild){
            cout<<root->lchild->data<<", ";
            q.enqueue(root->lchild);
        }
        if(root->rchild){
            cout<<root->rchild->data<<", ";
            q.enqueue(root->rchild);
        }
    }
}

int main(){

    createTree();

    cout<<"Level order Traversal : ";
    levelOrder(root);

    return 0;
}