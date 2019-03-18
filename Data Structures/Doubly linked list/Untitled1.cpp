/*doubly linked lists*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* head=NULL;

int len;
void append(void);
void display(void);
void reverse(void);
void addatbegain(void);
int length(void);
void addatafter(void);
void del(void);

int main()
{	
	int ch;
	while(1)
    {
		printf("\ndoubly linked lists: \n");
		printf("1.append \n");
		printf("2.display \n");
		printf("3.reverse display \n");
		printf("4.add at begain \n");
		printf("5.add in between \n");
		printf("6.length \n");
		printf("7.delete a node \n");
		printf("8.quit \n");
		
		printf("enter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: append();
			break;
			case 2: display();
			break;
			case 3: reverse();
			break;
			case 4: addatbegain();
			break;
			case 5: addatafter();
			break;
			case 6: len=length();
			printf("length: %d \n\n",len);
			break;
			case 7: del();
			break;
			case 8: exit(1);
			default: printf("invalid input \n");
		}
	}
	return 0;
}

void append(void)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node* p;
		p=head;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}

void display(void)
{
	struct node* temp;
	temp=head;
	if(temp==NULL)
	{
		printf("list is empty..\n\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d -->",temp->data);
			temp=temp->right;
		}
		printf("\n\n");
	}
}

void reverse(void)
{
	struct node* temp;
	temp=head;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	while(temp!=NULL)
	{
		printf("%d -->",temp->data);
		temp=temp->left;
	}
	printf("\n");
}

void addatbegain(void)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data:");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		head->left=temp;
		temp->right=head;
		head=temp;
	}
}
void addatafter(void)
{
	struct node* temp,*p;
	int i=1,loc,len;
	len=length();
	printf("Enter location:");
	scanf("%d",&loc);
	
	if(loc>len)
	{
		printf("invalid location \n\n");
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter node data:");
		scanf("%d",&temp->data);
		temp->left=NULL;
		temp->right=NULL;
		p=head;
		
		while(i<loc)
		{
			p=p->right;
			i++;
		}
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
	}
}

int length(void)
{
	struct node* temp;
	int count=0;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->right;
	}
	return count;
}

void del(void)
{
	struct node* temp;
	int loc,len;
	printf("enter location to be deleted: ");
	scanf("%d",&loc);
	len=length();
	
	if(loc>len)
	{
		printf("invalid location \n");
		printf("the list currently has %d nodes\n",len);
	}
	else if(loc==1)
	{
		temp=head;
		head=temp->right;
		temp->right=NULL;
		free(temp);
	}
	else
	{
		struct node* p,*q;
		int i=1;
		p=head;
		while(i<loc-1)
		{
			p=p->right;
			i++;
		}
		q=p->right;
		p->right=q->right;
		q->right=NULL;
		q->left=NULL;
		free(q);
	}
}
