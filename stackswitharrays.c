#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct stack
{
    int a[SIZE];
    int top;
} s;

void push();
void pop();
void display();

int main()
{
    int ch;
    s.top = -1;
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
        	pop();
        	break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}

// Inserting elements into the stack
void push()
{
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    if (s.top < SIZE - 1)
    {
        s.top++;
        s.a[s.top] = val;
    }
    else
    {
        printf("Stack overflow.\n");
    }
}

//deleting the elements in stack
void pop()
{
	if(s.top==-1)
	{
		printf("stack underflow\n");
	}
	else
	{
		printf("The element to be deleted is %d\n",s.a[s.top]);
		s.top--;
	}
}

// Display the stack
void display()
{
    if (s.top == -1)
    {
        printf("Stack is empty.\n");
    }
    printf("Stack elements: ");
    int i;
    for (i = 0; i <= s.top; i++)
    {
        printf("%d ", s.a[i]);
    }
    printf("\n");
}
