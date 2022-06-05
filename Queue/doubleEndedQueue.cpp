// *dosent strictly follow FIFO
// *in DEqueue we can use both front and rear for both insertion and deletion

//? 1)input restricted DEqueue(insert)
// *only rear can insert
// ! fornt cannot insert

// ?2output restricted DEqueue(deletion)
// *only front can be used to delete
// !rear cannot be used to delete

#include <stdio.h>

#include <stdlib.h>

struct Queue

{

    int front;

    int rear;

    int size;

    int *Q;
};

void create(struct Queue *q)

{

    printf("Enter size of Queue: ");

    scanf("%d", &q->size);

    q->Q = (int *)malloc(sizeof(int) * q->size);

    q->rear = q->front = -1;
}

// we assume that the insertion is initially start by rear

void insertUsingRear(struct Queue *q, int x)

{

    if (q->rear == q->size - 1)

        printf("DE queue is full\n");

    else

    {

        q->Q[++q->rear] = x;
    }
}

void insertUsingFront(struct Queue *q, int x)

{

    if (q->front == -1 && q->front < q->rear)

    {

        printf("Front can't insert\n");
    }

    else
    {

        q->Q[q->front--] = x;
    }
}

int deleteUsingRear(struct Queue *q)

{

    int x = -1;

    if (q->rear == q->front)

        printf("Rear can't delete\n");

    else

    {

        x = q->Q[q->rear--];
    }

    return x;
}

int deleteUsingFront(struct Queue *q)

{

    int x;

    if (q->front == q->rear)
        printf("Queue is empty\n");

    else

    {

        x = q->Q[++q->front];
    }

    return x;
}

void display(struct Queue q)

{

    int i;

    for (i = q.front + 1; i <= q.rear; i++)

    {

        printf("%d ", q.Q[i]);
    }

    printf("\n");
}

int main()

{

    struct Queue q;

    create(&q);

    insertUsingRear(&q, 10);

    insertUsingRear(&q, 20);

    insertUsingRear(&q, 30);

    insertUsingRear(&q, 40);

    insertUsingRear(&q, 50);

    insertUsingRear(&q, 60);

    deleteUsingFront(&q);

    deleteUsingFront(&q);

    insertUsingFront(&q, 100);

    insertUsingFront(&q, 200);

    insertUsingFront(&q, 100);

    display(q);

    return 0;
}