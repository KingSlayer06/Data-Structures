#include<stdio.h>
#define CAPACITY 5

int top=-1,stack[CAPACITY];
void push(void);
int pop(void);
int peek(void);
int traverse(void);
int isfull(void);
int isempty(void);

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
			case 4:traverse();
			break;
			default: printf("invalid input .. \n");
		}
	printf("\n\n");
	}
return 0;	
}

void push()
{
	if(isfull())
	{
		printf("\n Stack is full. \n");
	}
	else
	{
		int ele;
		printf("Enter element to be pushed: ");
		scanf("%d",&ele);
		top++;
		stack[top]=ele;
		printf("%d element pushed.",ele);	
	}
}
int pop()
{
	if(isempty())
	{
		printf("\n Stack is empty. \n");
	}
	else
	{
		printf("%d element popped. \n",stack[top]);
		return stack[top--];
	}
}

int peek()
{
	if(isempty())
	{
		printf("stack is empty \n");
	}
	else
	{
		printf("Element at top is: %d",stack[top]);
	}
}

int traverse()
{
	if(isempty())
	{
		printf("\n Stack is empty. \n");
	}
	else
	{
		int i;
		printf("\n Stack elements are: \n\n");
		for(i=top;i>=0;i--)
		{
			printf("\t %d \n",stack[i]);
		}
	}
}

int isfull()
{
	if(top==CAPACITY-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
