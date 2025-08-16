//PROGRAM
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top=-1;

//Push
void push(int value){
 if(top==MAX_SIZE-1){
   printf("Stack Overflow\n");
 }
 else{
 top++;
 stack[top]=value;
 printf("%d pushed to stack", value);
 }
}

//Pop
int pop(){
 if(top==-1){
   printf("Stack Underflow\n");
   return -1;
 }
 else{
 int popped=stack[top];
 top--;
 printf("%d popped from stack", popped);
 return popped;
 }
}

//Peek

int peek(){
 if(top==-1){
   printf("Stack is Empty\n");
   return -1;
 }
 else
   return stack[top];
}

//Display
void display(){
 if(top==-1){
   printf("Stack is Empty\n");
 }
 else{
 printf("Stack elements are : " );
 for(int i=top; i>=0; i--){
     printf("%d ", stack[i]);
 }
 }
}

int main(){
 int item, choice;
 printf("Implementation of Stack Operations\n");
 do{
  printf("\n\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
  printf("Enter your Choice :- ");
  scanf("%d",&choice);
  switch(choice){
  case 1:
   printf("\nEnter the item to be pushed : ");
   scanf("%d",&item);
   push(item);
   break;
  case 2:
   if(top==-1)
    printf("\nEmpty Stack! UNDERflow!\n");
   else{
    item=pop();
    printf("\nThe popped element is %d", item);
   }
   break;
  case 3:
   if(top==-1)
    printf("\nEmpty Stack! UNDERflow!\n");
   else{
    item=peek();
    printf("\nThe TOP element is %d", item);
   }
   break;
  case 4:
   display();
   break;
  case 5:
   exit(0);
 }}while(1);
  return 0;
}

/*OUTPUT
Implementation of Stack Operations


1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 1

Enter the item to be pushed : 3    
3 pushed to stack

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 4
Stack elements are : 3

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 2
3 popped from stack
The popped element is 3

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 4
Stack is Empty


1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 3

Empty Stack! UNDERflow!


1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 1

Enter the item to be pushed : 2
2 pushed to stack

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 1

Enter the item to be pushed : 8
8 pushed to stack

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 1

Enter the item to be pushed : 40
40 pushed to stack

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 4
Stack elements are : 40 8 2

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 2
40 popped from stack
The popped element is 40

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 4
Stack elements are : 8 2

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter your Choice :- 5
*/
