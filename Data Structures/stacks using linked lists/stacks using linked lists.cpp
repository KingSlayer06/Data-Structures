#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* head=NULL;

void push();
void pop();
void peek();
void display();

int main()
{
	int ch;
	while(1)
	{
		printf("===============================\n");
		printf("Stack Operation: \n");
		printf("1.push \n");
		printf("2.pop \n");
		printf("3.peek \n");
		printf("4.traverse \n");
		printf("===============================\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	push();
			break;
			case 2:pop();
			break;
			case 3:peek();
			break;
			case 4:display();
			break;
			default: printf("invalid input .. \n");
		}
	printf("\n\n");
	}
return 0;	
}

void push()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	temp->link=head;
	head=temp;
	printf("%d element pushed. \n",temp->data);
}

void pop()
{
	struct node* temp;
		temp=head;
		printf("%d element popped. \n",temp->data);
		head=temp->link;
		temp->link=NULL;
		free(temp);
}

void peek()
{
	struct node* temp;
	temp=head;
	printf("%d element is at top. \n",temp->data);
}

void display()
{
	struct node* temp;
	temp=head;
	
	while(temp!=NULL)
	{
		printf("\t %d \n",temp->data);
		temp=temp->link;
	}
}
