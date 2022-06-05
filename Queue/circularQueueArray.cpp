#include<iostream>
#include<stdlib.h>

using namespace std;

// *index where front is,that index is left empty so,front +1 is where queue starts from


struct Queue{
    int size;
    int rear;
    int front;
    int *Q;
};

// void Create(Queue *q){
//     q->rear=q->front=0;
//     cout<<"Enter size: \n";
//     cin>>q->size;
//     q->Q=new int[q->size];
// }

// void enqueue(Queue *q,int x){//*constant time
//     if((q->rear+1)%q->size==q->front){
//         cout<<"Queue is full\n";
//     }else{
//         q->rear=(q->rear+1)%q->size;
//         q->Q[q->rear]=x;
//     }
// }

// int dequeue(Queue *q){//*constant time
//     int x=-1;
//     if(q->front==q->rear){
//         cout<<"Queue is empty\n";
//     }else{
//         q->front=(q->front+1)%q->size;
//         x=q->Q[q->front];
//     }
//     return x;
// }

// void Display(Queue q){
//     int i=q.front+1;

//     do{
//         cout<<q.Q[i]<<" ";
//         i=(i+1)%q.size;
//     }while(i!=(q.rear+1)%q.size);
// }

void Create(Queue *q,int s){
    q->front=q->rear=0;
    q->size=s;
    q->Q=(int *)malloc(s*sizeof(int));
}

void enqueue(Queue *q,int x){
    // * check if Queue is full
    if((q->rear+1)%q->size==q->front){
        cout<<"Queue is full\n";
    }else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(Queue *q){
    int x=-1;
    if(q->rear==q->front){
        cout<<"Queue is empty\n";
    }else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void Display(Queue q){
    int i=(q.front+1)%q.size;//*coz where front is pointing is empty
    do{
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    cout<<"\n";
}

int main(){
    Queue q;
    Create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    Display(q);
    enqueue(&q,50);
    Display(q);
    cout<<dequeue(&q)<<"\n";
    cout<<dequeue(&q)<<"\n";
    Display(q);
    enqueue(&q,10);
    enqueue(&q,20);
    Display(q);
    cout<<dequeue(&q)<<"\n";
    Display(q);

    return 0;
}