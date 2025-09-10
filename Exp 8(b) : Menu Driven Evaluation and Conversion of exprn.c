#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Custom strrev function
void custom_strrev(char *str) {
    int len = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Infix to Postfix Conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char temp;
    for (i = 0; infix[i] != '\0'; i++) {
        temp = infix[i];
        if (isalnum(temp)) {
            postfix[j++] = temp;
        } else if (temp == '(') {
            push(temp);
        } else if (temp == ')') {
            while ((temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(temp)) {
                postfix[j++] = pop();
            }
            push(temp);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// Postfix Evaluation
int evaluatePostfix(char postfix[]) {
    int i, operand1, operand2, result;
    top = -1; // Reset stack for evaluation
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();
            switch (postfix[i]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
                case '^': push(pow(operand1, operand2)); break;
            }
        }
    }
    return pop();
}

// Infix to Prefix Conversion
void infixToPrefix(char infix[], char prefix[]) {
    int i;
    // Reverse the infix expression and swap parentheses
    custom_strrev(infix);
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    // Now convert the modified infix to postfix
    char tempPostfix[MAX];
    infixToPostfix(infix, tempPostfix);
    // Reverse the postfix to get prefix
    custom_strrev(tempPostfix);
    strcpy(prefix, tempPostfix);
    // Re-reverse the original infix and swap parentheses back
    custom_strrev(infix);
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
}

// Prefix Evaluation
int evaluatePrefix(char prefix[]) {
    int i, operand1, operand2, result;
    top = -1; // Reset stack for evaluation
    // Scan the prefix expression from right to left
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(prefix[i] - '0');
        } else {
            operand1 = pop();
            operand2 = pop();
            switch (prefix[i]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
                case '^': push(pow(operand1, operand2)); break;
            }
        }
    }
    return pop();
}

int main() {
    int choice;
    char exp[MAX], temp[MAX];

    do {
        printf("\n\n*** MENU ***\n");
        printf("1. Infix to Postfix Conversion\n");
        printf("2. Postfix Evaluation\n");
        printf("3. Infix to Prefix Conversion\n");
        printf("4. Prefix Evaluation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", exp);
                infixToPostfix(exp, temp);
                printf("Postfix expression: %s\n", temp);
                break;
            case 2:
                printf("Enter postfix expression: ");
                scanf("%s", exp);
                printf("Result: %d\n", evaluatePostfix(exp));
                break;
            case 3:
                printf("Enter infix expression: ");
                scanf("%s", exp);
                infixToPrefix(exp, temp);
                printf("Prefix expression: %s\n", temp);
                break;
            case 4:
                printf("Enter prefix expression: ");
                scanf("%s", exp);
                printf("Result: %d\n", evaluatePrefix(exp));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}
/* OUTPUT 


*** MENU ***
1. Infix to Postfix Conversion
2. Postfix Evaluation
3. Infix to Prefix Conversion
4. Prefix Evaluation
5. Exit
Enter your choice: 1
Enter infix expression: (A+B)*(C+D)
Postfix expression: AB+CD+*


*** MENU ***
1. Infix to Postfix Conversion
2. Postfix Evaluation
3. Infix to Prefix Conversion
4. Prefix Evaluation
5. Exit
Enter your choice: 2
Enter postfix expression: 562+*142/-+
Result: 39


*** MENU ***
1. Infix to Postfix Conversion
2. Postfix Evaluation
3. Infix to Prefix Conversion
4. Prefix Evaluation
5. Exit
Enter your choice: 
=== Session Ended. Please Run the code again ===*/