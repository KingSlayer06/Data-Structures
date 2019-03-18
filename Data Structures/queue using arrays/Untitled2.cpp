#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10

int queue[CAPACITY],front=-1,rear=-1;
int enqueue();
void display();
int dequeue();
int main()
{
	int ch;
	while(1)
	{
		printf("===========================");
		printf("\n Queue Operation: \n");
		printf("1.enqueue \n");
		printf("2.dequeue \n");
		printf("3.display \n");
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
			case 3: display();
			break;
			case 4: exit(1);
			break;
			default: printf("Invalid Input..\n");
		}
	}
return 0;
}

int enqueue()
{
	if(front==-1)
	{
		front++;
	}
	if(rear==CAPACITY-1)
	{
		printf("Queue is full \n");
	}
	else
	{
		rear++;
		printf("Enter queue data: ");
		scanf("%d",&queue[rear]);
		return rear;
	}
}

int dequeue()
{
	int i=0;
	if(front==-1 || front>rear)
	{
		printf("Queue is empty. \n");
	}
	else
	{
		printf("%d element deleted. \n",queue[front]);
		front++;
		
	}
}

void display()
{
	if(front==-1 || front>rear)
	{
		printf("Queue is empty. \n");
	}
	else
	{
		int i;
		printf(" Queue is: \n");
		for(i=front;i<=rear;i++)
		{
			printf("%d \t",queue[i]);
		}
		printf("\n");
	}
}

