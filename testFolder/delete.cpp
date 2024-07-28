#include "Queue.h"
#include "Stack.h"

Node *root=new Node;

Node *Root= nullptr;

void createTree(){
    Node *p{nullptr},*t{nullptr};
    Queue q(10);
    int x{-1};

    std::cout<<"Enter root value : ";
    std::cin>>x;
    root->data=x;
    root->lchild=root->rchild=nullptr;

    q.enqueue(root);

    while(!q.isEmpty()){
        p=q.dequeue();

        std::cout<<"Enter value of left child of "<<p->data<<" : "<<std::flush;
        std::cin>>x;

        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.enqueue(t);
        }

        std::cout<<"Enter value of right child of "<<p->data<<" : "<<std::flush;
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
        std::cout<<p->data<<",";
        Inorder(p->rchild);
    }
    return;
}

void Preorder(Node *p){
    
    if(p){
        std::cout<<p->data<<",";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
    return;
}

void Postorder(Node *p){
    
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        std::cout<<p->data<<",";
    }
}

int count(Node *p){
    int x{0},y{0};
    if(p){
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
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
    return 0;
}

int sum(Node *p){
    int x{0},y{0};
    if(p){
        x=sum(p->lchild);
        y=sum(p->rchild);
        return x+y+p->data; 
    }
    return 0;
}

void LevelOrder(Node *p){
    Queue q(10);
    std::cout<<p->data<<", ";
    q.enqueue(p);
    Node *x{nullptr};
    while(!q.isEmpty()){
        x=q.dequeue();
        if(x->lchild){
            std::cout<<x->lchild->data<<", ";
            q.enqueue(x->lchild);
        }
        if(x->rchild){
            std::cout<<x->rchild->data<<", ";
            q.enqueue(x->rchild);
        }
    }
}

void IterativePreorder(Node *p){
    Stack st(50);
    while(p || !st.isEmpty()){
        if(p){
            std::cout<<p->data<<", ";
            st.Push(p);
            p=p->lchild;
        }else{
            p=st.Pop();
            p=p->rchild;
        }
    }
}

void IterativeInorder(Node *p){
    Stack st(20);

    while(p || !st.isEmpty()){
        if(p){
            st.Push(p);
            p=p->lchild;
        }else{
            p=st.Pop();
            std::cout<<p->data<<", ";
            p=p->rchild;
        }
    }
}

void Insert(int key){
    Node* t = Root;
    Node* p;
    Node* r;
 
    // root is empty
     if (Root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        Root = p;
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

void inorder(Node *p){
    if(p){
        inorder(p->lchild);
        std::cout<<p->data<<", ";
        inorder(p->rchild);
    }
}

Node * Search(int key){
    Node *t=Root;

    while(t){
        if(key<t->data){
            t=t->lchild;    
        }else if(key>t->data){
            t=t->rchild;
        }else{
            return t;
        }
    }
    return nullptr;
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
    

}

int main(){

    // createTree();

    // std::cout<<"Preoder traversal is : ";
    // Preorder(root);
    // std::cout<<"\n";

    // std::cout<<"Inorder traversal is : ";
    // Inorder(root);
    // std::cout<<"\n";

    // std::cout<<"Postorder traversal is : ";
    // Postorder(root);
    // std::cout<<"\n";

    // std::cout<<"Level traversal is : ";
    // LevelOrder(root);
    // std::cout<<"\n";

    // std::cout<<"Sum is :"<<sum(root)<<"\n";
    // std::cout<<"Count is :"<<count(root)<<"\n";
    // std::cout<<"Height is :"<<height(root)<<"\n";

    // std::cout<<"Iterative Preoder traversal is : ";
    // IterativePreorder(root);
    // std::cout<<"\n";

    // std::cout<<"Iterative Inorder traversal is : ";
    // IterativeInorder(root);
    // std::cout<<"\n";

    Node *temp{nullptr};
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);
    Insert(50);
    Insert(60);
    Insert(70);

    inorder(Root);
    // temp=Search(10);
    // if(temp){
    //     std::cout<<"Element "<< temp->data <<" is found\n";
    // }else{
    //     std::cout<<"Element not found";
    // }
    


    return 0;
}