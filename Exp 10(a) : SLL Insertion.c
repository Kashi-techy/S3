#include<stdio.h>
#include<stdlib.h>
struct node {
 	int data;
 	struct node *next;
 	};
 struct node *head =NULL;

void insertatFrnt( int value){
 	struct node *newnode=(struct node*)malloc(sizeof(struct node));
 	newnode -> data=value;
 	newnode->next=head;
 	head=newnode;
 	printf("value added");
}

void insertatend( int value){
 	struct node *newnode=(struct node*)malloc(sizeof(struct node));
 	newnode -> data=value;
 	newnode->next=NULL;
       if(head==null){
                head=newnode;
       	return;
       }
 	printf("value added");
 	struct node *temp=head;
 	while(temp->next != NULL)
 		temp=temp->next;
 	temp->next=newnode;
}

void display(){
	struct node *temp=head;
	while (temp!=NULL){
		printf("%d inserted at frnt",temp->data);
		temp=temp->next;
	}
printf("NULL \n");
}

int main(){
	int choice,value;
	printf("1.INSERT AT FRONT\n,2.INSERT AT END\n,3. INSERT AT SPEC POS\n,4.DELETION AT FRONT\n, 5. DELETION AT END \n,6.DELETION AT SPEC POS\n,7.DISPLAY\n,8.EXIT");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			printf("enter the value");
			scanf("%d",&value);
			insertatFrnt(value);}
		case 7:{
			display();}
		case 2:{
			printf("enter the value");
			scanf("%d",&value);
			insertatend(value);}
		case 3:{
			printf("enter the value");
			scanf("%d",&value);
			insertatpos(value);}
		case 4:{
			dltatfrnt();}
		case 5:{
			dltatend();}
		case 6:{
			dltatpos();}
		case 8:{
			exit(0);}
		default:
               	{ printf("Invalid choice!\n");}
}
