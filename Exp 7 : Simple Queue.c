PROGRAM
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int rear=-1;
int front=-1;

bool isfull(){
 return rear == MAX_SIZE-1;
}
bool isempty(){
 return front == -1 || front>rear;
}
//Enqueue
int enqueue(){
 int item;
 if(rear==MAX_SIZE-1){
   printf("OVERflow\n");
   return -1;
}else{
   if(front==-1){
      front=0;}
   printf("Insert the Element : ");
   scanf("%d",&item);
   rear++;
   queue[rear]=item;
   printf("\nThe enqueued element is %d", item);
   return item ;
 }
}

//Dequeue
int dequeue(){
 if(isempty()){
   printf("UNDERflow");
   return -1;
}else{
   int item=queue[front];
   front++;
   return item;
 }
}

//Peek
int peek(){
 if(isempty()){
   printf("Queue is Empty\n");
   return -1;
}else
   return queue[front];
}

//Display
void display(){
 if(front==-1 || front>rear){
   printf("Queue is Empty\n");
 }
 else{
 printf("Queue elements are : " );
 for(int i=front; i<=rear; i++){
     printf("%d ", queue[i]);
 }
 printf("\n");
 }
}

//Main Function
int main(){
 int item, choice;
 printf("Implementation of Queue Operations\n");
 do{
  printf("\n\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
  printf("Enter your Choice :- ");
  scanf("%d",&choice);
  switch(choice){
  case 1:
   item=enqueue();
   if(item==-1)
    printf("\nEnqueue failed due to overflow.\n");
   break;
  case 2:
   if(isempty())
    printf("\nEmpty Queue! UNDERflow!\n");
   else{
    item=dequeue();
    printf("\nThe dequeued element is %d", item);
   }
   break;
  case 3:
   if(isempty())
    printf("\nEmpty Queue! UNDERflow!\n");
   else{
    item=peek();
    printf("\nThe FRONT element is %d", item);
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
Implementation of Queue Operations


1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 1
Insert the Element : 93

The enqueued element is 93

1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 1
Insert the Element : 85

The enqueued element is 85

1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 1
Insert the Element : 98

The enqueued element is 98

1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 1
Insert the Element : 89

The enqueued element is 89

1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 4
Queue elements are : 93 85 98 89


1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 2

The dequeued element is 93

1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 4
Queue elements are : 85 98 89


1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 3

The FRONT element is 85

1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 4
Queue elements are : 85 98 89


1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
Enter your Choice :- 5
*/
