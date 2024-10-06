#include <stdio.h>
#include <stdlib.h>

typedef struct sll {
    int data;
    struct sll* link;
} node;

node* head = NULL;

void insert_front();
void insert_end();
void display();
void delete_front();
void delete_end();
void search();
void count();
void reverse();
int mid();
void sort();

int main() {
    int ch;
    while (1) {
        printf("Options:\n");
        printf("1. Insert at the front\n2. Insert at the end\n3. Display\n4. Delete from the front\n5. Delete from the end\n6. Search\n7. Count\n8. Reverse\n9. Mid\n10. Sort\n11. Exit\n");
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
            case 5:
            	delete_end();
            	break;
            case 6:
            	search();
            	break;
            case 7:
            	count();
            	break;
            case 8:
            	reverse();
            	break;
            case 9:
            	mid();
            	break;
            case 10:
            	sort();
            	break;
            case 11:
                exit(0);
                break;
        }
    }
}

// Function to insert a node at the front of the list
void insert_front()
{
	int ele;
    printf("Enter data to insert at the front: ");
    scanf("%d", &ele);
    node* p =malloc(sizeof(node));
    p->data = ele;
    p->link = head;
    head = p;
}

//Function to insert a node at the end of the list
void insert_end()
{
    node* p = malloc(sizeof(node));
    int ele;
    printf("Enter data to insert at the end: ");
    scanf("%d", &ele);
    p->data = ele;
    p->link = NULL;
    if (head == NULL) 
	{
        head = p;
    } 
	else 
	{
        node*t= head;
        while (t->link != NULL) 
		{
            t = t->link;
        }
        t->link = p;
    }
}

// Function to display the linked list
void display() 
{
    node* t = head;
    if (t == NULL) 
	{
        printf("The list is empty.\n");
        return;
    }
    else
    {
    while (t!= NULL) 
	{
        printf("%d\n", t->data);
        t=t->link;
    }  
    }
}

//Function to delete the front node
void delete_front()
{
	node*t=head;
	if(head==NULL)
	printf("list is empty");
	else
	{
		head=head->link;
		printf("deleted element is %d",t->data);
		free(t);
	}
}

//Function to delete the last node
void delete_end()
{
	node*t=head;
	if(head==NULL)
	printf("list is empty");
	else
	{
		if(head->link==NULL)
		{
			head=NULL;
			free(t);
		}
		else
		{
			while(head->link->link!=NULL)
			{
				t=t->link;
			}
		node*t1=t->link;
		t->link=NULL;
		free(t);
		}
	}
}

//Function to search the element
void search()
{
	int ele;
	printf("enter the element to search: ");
	scanf("%d",&ele);
	node*t=head;
	while(t!=NULL && t->data!=ele)
	{
		t=t->link;
	}
    if(t==NULL)
    {
    	printf("Not Found\n");
	}
	else
	{
		printf("Found\n");
	}
}

//Function to count the no of elements
void count()
{
	node*t=head;
	int count=0;
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		while(t!=NULL)
		{
			t=t->link;
			count=count+1;
		}
	printf("Number of elements in the list: %d\n", count);
	}
}

//Function for reversing a linked list
void reverse()
{
	node*p=head;
	node*q=NULL;
	node*r;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->link;
		q->link=r;
	}
head=q;
printf("\n");
}

//Function for finding the mid of linked list
int mid()
{
	node*f=head,*s=head;
	while(f!=NULL && f->link!=NULL)
	{
		s=s->link;
		f=f->link->link;
	}
printf("the mid element is %d\n",s->data);
}

//Function for sorting the data of a linked list
void sort()
{
	int temp;
	node*p=head;
	node*q=head;
	while(p->link!=NULL)
	{
		q = p->link;
		while(q!=NULL)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->link;
		}
		p=p->link;
	}
printf("\n");
}
