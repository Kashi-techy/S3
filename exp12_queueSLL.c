#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the queue
struct Node {
    int data;
    struct Node *next;
};

// Global pointers for the front and rear of the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to add an element to the rear of the queue (Enqueue)
void enqueue(int value) {
    // Create a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, the new node is both front and rear
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        // Add the new node at the end of the queue and change rear
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to remove an element from the front of the queue (Dequeue)
int dequeue() {
    // If the queue is empty, return an error value
    if (front == NULL) {
        return -1; // Indicates queue underflow
    }

    // Store the front node and its data
    struct Node *temp = front;
    int dequeuedValue = front->data;

    // Move front one node ahead
    front = front->next;

    // If front becomes NULL, then change rear to also be NULL
    if (front == NULL) {
        rear = NULL;
    }

    free(temp); // Free the old front node
    return dequeuedValue;
}

// Function to display all elements in the queue
void displayQ() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue: FRONT -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    int ch, data, dequeuedValue;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue (Add)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                displayQ();
                break;
            case 2:
                dequeuedValue = dequeue();
                if (dequeuedValue == -1) {
                    printf("Queue underflow: Cannot dequeue from an empty queue.\n");
                } else {
                    printf("Dequeued value is: %d\n", dequeuedValue);
                }
                displayQ();
                break;
            case 3:
                displayQ();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
/*o/p
    --- Queue Menu ---
    1. Enqueue (Add)
    2. Dequeue (Remove)
    3. Display
    4. Exit
    Enter your choice: 1
    Enter the data to enqueue: 45
    Queue: FRONT -> 45 -> NULL
    
    --- Queue Menu ---
    1. Enqueue (Add)
    2. Dequeue (Remove)
    3. Display
    4. Exit
    Enter your choice: 1 
    Enter the data to enqueue: 89
    Queue: FRONT -> 45 -> 89 -> NULL
    
    --- Queue Menu ---
    1. Enqueue (Add)
    2. Dequeue (Remove)
    3. Display
    4. Exit
    Enter your choice: 1
    Enter the data to enqueue: 78
    Queue: FRONT -> 45 -> 89 -> 78 -> NULL
    
    --- Queue Menu ---
    1. Enqueue (Add)
    2. Dequeue (Remove)
    3. Display
    4. Exit
    Enter your choice: 2
    Dequeued value is: 45
    Queue: FRONT -> 89 -> 78 -> NULL
    
    --- Queue Menu ---
    1. Enqueue (Add)
    2. Dequeue (Remove)
    3. Display
    4. Exit
    Enter your choice: 3
    Queue: FRONT -> 89 -> 78 -> NULL
*/
