/*ALGORITHM
1. Initialize front = -1, rear = -1.

Enqueue(x):

If (front == 0 && rear == MAX-1) || (front == rear+1) → Overflow.

If front == -1 → front = rear = 0.

Else if rear == MAX-1 → rear = 0.

Else rear++.

Insert x at queue[rear].

Dequeue():

If front == -1 → Underflow.

Store queue[front] as deleted element.

If front == rear → front = rear = -1.

Else if front == MAX-1 → front = 0.

Else front++.

Peek: Return queue[front].

Display: Traverse circularly from front to rear.*/

//PROGRAM
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX-1) || (front == rear+1);
}
int isEmpty() {
    return front == -1;
}

// Enqueue
void enqueue(int x) {
    if(isFull()) {
        printf("Overflow! CQ is full.\n");
        return;
    }
    if(front == -1) front = 0;
    rear = (rear+1) % MAX;
    cq[rear] = x;
    printf("%d enqueued\n", x);
}

// Dequeue
int dequeue() {
    if(isEmpty()) {
        printf("Underflow! CQ is empty.\n");
        return -1;
    }
    int item = cq[front];
    if(front == rear) front = rear = -1;
    else front = (front+1) % MAX;
    return item;
}

// Peek
int peek() {
    if(isEmpty()) return -1;
    return cq[front];
}

// Display
void display() {
    if(isEmpty()) {
        printf("CQ is empty\n");
        return;
    }
    printf("CQ elements: ");
    int i = front;
    while(1) {
        printf("%d ", cq[i]);
        if(i == rear) break;
        i = (i+1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter item: "); scanf("%d", &item); enqueue(item); break;
            case 2: item = dequeue(); if(item!=-1) printf("Dequeued: %d\n", item); break;
            case 3: item = peek(); if(item!=-1) printf("Front: %d\n", item); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    } while(1);
}
//OUTPUT
