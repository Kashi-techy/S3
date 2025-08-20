/* ALGORITHM
Initialize front = -1, rear = -1.

InsertFront(x):

If full → Overflow.

If empty → front = rear = 0.

Else if front == 0 → front = MAX-1.

Else front--.

Insert x at deque[front].

InsertRear(x): (similar to circular enqueue at rear).

DeleteFront(): (similar to circular dequeue at front).

DeleteRear():

If empty → Underflow.

If front == rear → reset.

Else if rear == 0 → rear = MAX-1.

Else rear--.

Display: Traverse circularly.*/

//PROGRAM
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int dq[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX-1) || (front == rear+1);
}
int isEmpty() {
    return front == -1;
}

void insertFront(int x) {
    if(isFull()) { printf("Overflow!\n"); return; }
    if(front == -1) front = rear = 0;
    else if(front == 0) front = MAX-1;
    else front--;
    dq[front] = x;
    printf("%d inserted at front\n", x);
}

void insertRear(int x) {
    if(isFull()) { printf("Overflow!\n"); return; }
    if(front == -1) front = rear = 0;
    else if(rear == MAX-1) rear = 0;
    else rear++;
    dq[rear] = x;
    printf("%d inserted at rear\n", x);
}

int deleteFront() {
    if(isEmpty()) { printf("Underflow!\n"); return -1; }
    int item = dq[front];
    if(front == rear) front = rear = -1;
    else if(front == MAX-1) front = 0;
    else front++;
    return item;
}

int deleteRear() {
    if(isEmpty()) { printf("Underflow!\n"); return -1; }
    int item = dq[rear];
    if(front == rear) front = rear = -1;
    else if(rear == 0) rear = MAX-1;
    else rear--;
    return item;
}

void display() {
    if(isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deque elements: ");
    int i = front;
    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i+1)%MAX;
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("\n1.InsertFront 2.InsertRear 3.DeleteFront 4.DeleteRear 5.Display 6.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter item: "); scanf("%d",&item); insertFront(item); break;
            case 2: printf("Enter item: "); scanf("%d",&item); insertRear(item); break;
            case 3: item=deleteFront(); if(item!=-1) printf("Deleted front: %d\n",item); break;
            case 4: item=deleteRear(); if(item!=-1) printf("Deleted rear: %d\n",item); break;
            case 5: display(); break;
            case 6: exit(0);
        }
    } while(1);
}

