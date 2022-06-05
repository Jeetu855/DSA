#include <iostream>
#include <stdlib.h>

using namespace std;

// *insertion from rear end
// * deletion from front end

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(Queue *q,int s){
    q->size=s;
    q->Q=new int[q->size]; //(int *)malloc(q->size*sizeof(int))
    q->front=q->rear=-1;
}

void enqueue(Queue *q,int x){
    // *check if queue is full
    if(q->rear==q->size-1){
        cout<<"Queue is full\n";
    }else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(Queue *q){
    int x=-1;
    // *check if Queue is empty
    if(q->rear==q->front){
        cout<<"Queue is empty\n";
    }else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void Display(Queue q){
     for(size_t i=q.front+1;i<=q.rear;i++){
         cout<<q.Q[i]<<" ";
     }
     cout<<"\n";
}

int main()
{
    Queue q;
    Create(&q,5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    Display(q);
    dequeue(&q);
    dequeue(&q);
    Display(q);
    return 0;
}

// ************************DRAWBACKS*************************

//*cannot reuse space of deleted elements
// *every index can only be used once
// *when we insert all elements then delete all of them,rear==front
// *and queue is empty and full

// *SOLUTION1*******************RESETTING POINTERS****************
// *SOLUTION2*******************CIRCULAR QUEUE****************

