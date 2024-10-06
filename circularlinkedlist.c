#include <stdio.h>
#include <stdlib.h>

typedef struct cll {
    int data;
    struct cll* link;
} node;

node* head = NULL;

void insert_front();
void insert_end();
void display();
void delete_front();
void delete_end();

int main() {
    int ch;
    while (1) {
        printf("Options:\n");
        printf("1. Insert at the front\n2. Insert at the end\n3. Display\n4. Delete from the front\n5. Delete from the end\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert_front();
                break;
            case 2:
            	insert_end();
            	break;
            case 3:
            	display();
            	break;
            case 4:
            	delete_front();
            	break;
            case 6:
                exit(0);
                break;
        }
    }
}

// Function to insert a node at the front of the circular linked list
void insert_front()
{
	int ele;
    printf("Enter data to insert at the front: ");
    scanf("%d", &ele);
    node* p =malloc(sizeof(node));
    p->data = ele;
    if(head==NULL)
    {
    	head=p;
    	p->link=head;
	}
	else
	{
		node*t=head;
		while(t->link!=head)
		{
			t=t->link;
		}
	p->link=head;
	head=p;
	t->link=head;
	}
}

//Function to insert the node at the end of a circular linked list
void insert_end()
{
    node* p = malloc(sizeof(node));
    int ele;
    printf("Enter data to insert at the end: ");
    scanf("%d", &ele);
    p->data = ele;
    if (head == NULL) 
	{
        head = p;
        p->link=head;
    } 
	else 
	{
        node*t= head;
        while (t->link != head) 
		{
            t = t->link;
        }
        t->link = p;
        p->link=head;
    }
}

//Function to display the elements in the circular linked list
void display() 
{
    node* t = head;
    if (t == NULL) 
	{
        printf("The list is empty.\n");
        return;
    }
    while (1) 
	{
        printf("%d , ", t->data);
        t = t->link;
        if (t == head) 
		{
            break;
        }
    }
    printf("\n");
}

//Function to delete the node from the front
void delete_front()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    node *t1 = head;
    while (t1->link != head)
    {
        t1 = t1->link;
    }
    t1->link = head->link; 
    printf("the deleted element is %d", head->data);
    node *temp = head;
    head = head->link;
    free(temp); 
}

//Function to delete the node from the end
void delete_end()
{
	
}
