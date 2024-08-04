#include "Queue.h"  

Node *root=new Node;

void createTree(){
    Node *p{nullptr},*t{nullptr};
    Queue q(100);
    int x{-1};
    std::cout<<"Enter root nodes data :";
    std::cin>>x;
    root->data=x;
    root->lchild=root->rchild=nullptr;

    q.enqueue(root);
    while(!q.isEmpty()){
        p=q.dequeue();

        std::cout<<"Enter the value of left child of "<<p->data<<" :"<<std::flush;
        std::cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.enqueue(t);
        }

        std::cout<<"Enter value of right child of "<<p->data<<" :"<<std::flush;
        std::cin>>x;

        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        std::cout<<p->data<<", ";
        Inorder(p->rchild);
    }
}

void Preorder(Node *p){
    if(p){
        std::cout<<p->data<<", ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        std::cout<<p->data<<", ";
    }
}

int height(Node *p){
    int x{0},y{0};

    if(p){
        x=height(p->lchild);
        y=height(p->rchild);
    }
    if(x>y){
        return x+1;
    }else{
        return y+1;
    }
}

int count(Node *p){
    int x{0},y{0};

    if(p){
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int sumOfData(Node *p){
    int x{0},y{0};
    if(p){
        x=sumOfData(p->lchild);
        y=sumOfData(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

int main(){

    createTree();

    // std::cout<<"Preorder Traversal: ";
    // Preorder(root); //* at a given moment, number of activation records will be height + 2
    // std::cout <<"\n";
    
    // std::cout<<"Inorder Traversal: ";
    // Inorder(root); //* at a given moment, number of activation records will be height + 2
    // std::cout <<"\n";
    
    // std::cout<<"Postorder Traversal: ";
    // Postorder(root); //* at a given moment, number of activation records will be height + 2
    // std::cout <<"\n";

    std::cout<<"Count :";
    std::cout<<count(root);
    std::cout<<"\n";

    std::cout<<"Height :";
    std::cout<<height(root);
    std::cout<<"\n";

    std::cout<<"Sum of elements :";
    std::cout<<sumOfData(root);
    std::cout<<"\n";

    return 0;
}