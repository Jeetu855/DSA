
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

// we need our own stack for iterative traversal
// push the address of visited nodes onto the stack
// for post order need to push address 2 times, to differentiate between them, push one address as negative
// but address are not negative, store address in integer, when needed, typecast it back to address

void Preorder(Node *p){
    Stack st(100);

    while(p || !st.isEmptyStack()){
        if(p){
            // here we are printing before going to left child
            cout<<p->data<<", ";
            st.Push(p);
            p=p->lchild;
        }
        else{// if p is null but stack is not empty
            p=st.Pop();
            p=p->rchild;
        }
    }
}

void Inorder(Node *p){
    Stack st(100);
// here we print before going to right child
    while(p || !st.isEmptyStack()){
        if(p){
            st.Push(p);
            p=p->lchild;
        }
        else{// if p is null but stack is not empty
            p=st.Pop();
            cout<<p->data<<", ";
            p=p->rchild;
        }
    }
}

int main(){
    createTree();

    cout<<"Preorder Traversal: ";
    Preorder(root);

    cout<<"\n";

    cout<<"Inorder Traversal: ";
    Inorder(root);

    return 0;
}