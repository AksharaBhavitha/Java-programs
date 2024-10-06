#include<stdio.h>
#include<stdlib.h>
 typedef struct stack 
 {
 	int data;
 	struct stack*link;

 }node;

node*top=NULL;

void push();
void pop();
void display();

int main()
{
	int ch;
	while(1)
	{
		printf("1. Push\n2. Pop\n3. Display\n4. Exit");
		printf("Enter the choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 4:
				exit(0);
		}
	}
}

//Function for inserting the elements into the stack
void push()
{
	int ele;
	printf("enter the value of element");
	scanf("%d",&ele);
	node*p=malloc(sizeof(node));
	p->data=ele;
	p->link=top;
	top=p;
}

//Function to delete the elements from the stack
void pop()
{
	node*t=top;
	if(top==NULL)
	{
		printf("stack underflow");
	}
	else
	{
		printf("deleted element is %d",t->data);
		top=top->link;
		free(t);
	}
}

//Function to display the elements of the stack
void display()
{
	node*t=top;
	if(top==NULL)
	{
		printf("stack empty");
	}
	else
	{
		while(t!=NULL)
		{
			printf("%5d",t->data);
			t=t->link;
		}
	}
}
