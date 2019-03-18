#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* front,*rear=NULL;
void enqueue();
void display();
void dequeue();
void peek();
int main()
{
	int ch;
	while(1)
	{
		printf("===========================");
		printf("\n Queue using linked lists: \n");
		printf("1.enqueue \n");
		printf("2.dequeue \n");
		printf("3.peek \n");
		printf("4.quit \n");
		printf("===========================");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: enqueue();
			break;
			case 2: dequeue();
			break;
			case 3: peek();
			break;
			case 4: exit(1);
			break;
			default: printf("Invalid Input..\n");
		}
	}
	return 0;
}

void enqueue()
{
		struct node* temp,*p;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter queue data: ");
		scanf("%d",&temp->data);
		temp->link=NULL;
		if(front==NULL)
		{
			front=rear=temp;
		}
		else
		{
			p=rear;
			p->link=temp;
			rear=temp;
		}
		display();
}

void display()
{
	struct node* temp;
	temp=front;
	while(temp!=NULL)
	{
		printf(" %d \t",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

void dequeue()
{
	if(front==NULL)
	{
		printf("Queue is Empty. \n");
	}
	else
	{
		struct node* temp;
		temp=front;
		front=temp->link;
		temp->link=NULL;
		free(temp);
		display();
	}
}

void peek()
{
	if(front==NULL)
	{
		printf("Queue is Empty. \n");
	}
	else
	{
		printf("element at front is: %d \n",front->data);
	}
}
