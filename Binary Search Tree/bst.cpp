#include<iostream>

using namespace std;

struct Node{
    Node *lchild;
    int data;
    Node *rchild;
};

Node *root=nullptr;

void Insert(int key){
    Node* t = root;
    Node* p;
    Node* r;
 
    // root is empty
     if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
 
    while(t){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }
 
    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
 
    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
}

void Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<", ";
        Inorder(p->rchild);
    }
}

Node * Search(int key){
    Node *t=root;
    while(t){
        if(key==t->data){
            return t;
        }else if(t->data>key){
            t=t->lchild;
        }else{
            t=t->rchild;
        }
    }
    return nullptr;
}

Node * RInsert(Node *p,int key){
    
    if(p==nullptr){
        Node *t=new Node;
        t->data=key;
        t->lchild=t->rchild=nullptr;
        return t;
    }
    if(key< p->data){
        p->lchild=RInsert(p->lchild,key);
    }else if(key>p->data){
        p->rchild=RInsert(p->rchild,key);
    }
    return p;
}

int Height(Node *p){
    int x,y;
    if(p==nullptr){
        return 0;
    }
    x=Height(p->lchild); 
    y=Height(p->rchild);
    return x>y?x+1:y+1; 
}

Node * InPre(Node *p){
    while(p && p->rchild!=nullptr){
        p=p->rchild;
    }
    return p;
}

Node * InSucc(Node *p){
       while(p && p->lchild!=nullptr){
        p=p->lchild;
    }
    return p;
}

Node * Delete(Node *p,int key){

    Node *q;

    if(p==nullptr){
        return nullptr;
    }

    if(p->lchild==nullptr && p->rchild==nullptr){
        if(p==root){
            root=nullptr;
        }
        delete p;
        return nullptr;
    }

    if(p->data<key){
        p->rchild=Delete(p->rchild,key);
    }else if(p->data>key){
        p->lchild=Delete(p->rchild,key);
    }else{
        if(Height(p->lchild) > Height(p->rchild)){
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main(){
    Node *temp;

    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Delete(root,10);

    cout<<"Inorder traversal is :";
    Inorder(root);
    cout<<"\n";

    temp=Search(2);
    if(temp){
        cout<<"Element "<< temp->data <<" is found\n";
    }else{
        cout<<"Element not found";
    }
    return 0;
}