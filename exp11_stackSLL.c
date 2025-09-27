#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the stack
struct Node {
    int data;
    struct Node *next;
};

// Global 'top' pointer, initialized to NULL for an empty stack
struct Node *top = NULL;

// Function to add an element to the top of the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Function to remove and return the top element of the stack
int pop() {
    if (top == NULL) {
        // No need to print here, can be handled in main
        return -1; // Indicate stack underflow
    }
    struct Node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

// Function to display all elements in the stack
void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Stack: TOP -> ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function to drive the menu
int main() {
    int ch, data, poppedValue;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(data);
                displayStack();
                break;
            case 2:
                poppedValue = pop();
                if (poppedValue == -1) {
                    printf("Stack underflow: Cannot pop from an empty stack.\n");
                } else {
                    printf("Popped value is: %d\n", poppedValue);
                }
                displayStack();
                break;
            case 3:
                displayStack();
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
/* o/p
    --- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the data to push: 37
Stack: TOP -> 37 -> NULL

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1 
Enter the data to push: 39
Stack: TOP -> 39 -> 37 -> NULL

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the data to push: 35
Stack: TOP -> 35 -> 39 -> 37 -> NULL

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped value is: 35
Stack: TOP -> 39 -> 37 -> NULL

*/
    
