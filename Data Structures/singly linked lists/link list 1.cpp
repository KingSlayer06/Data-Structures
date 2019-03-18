#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* head=NULL;

int len;
void create(void);
void addatbegain(void);
void display(void);
void addinbetween(void);
int length(void);
void search(void);
void del(void);
void reverse(void);

int main()
{
	int ch;
	while(1)
	{
		printf("\n singly linked list: \n");
		printf("1.create \n");
		printf("2.add at begain \n");
		printf("3.reverse \n");
		printf("4.add in between \n");
		printf("5.length \n");
		printf("6.search \n");
		printf("7.delete \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:create();
			break;
			case 2:addatbegain();
			break;
			case 3:reverse();
			break;
			case 4:addinbetween();
			break;
			case 5:len=length();
				   printf("length: %d \n",len);
			break;	  
			case 6: search();
			break; 	
			case 7:del();
			break;
			default: printf("Invalid input..\n");
		}
		printf("\n\n");
	}
return 0;	
}

void create()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node* p;
		p=head;
		
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
	display();
}

void addatbegain(void)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	temp->link=head;
	head=temp;
	display();
}

void addinbetween(void)
{
	struct node* temp,*p;
	int loc,len,i=1;
	printf("Enter location to add: ");
	scanf("%d",&loc);
	if(loc>len)
	printf("invalid location.. \n");
	
	else
	{
		p=head;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data: ");
		scanf("%d",&temp->data);
		temp->link=NULL;
		
		temp->link=p->link;
		p->link=temp;	
	}
	display();
}


void display(void)
{
	struct node* temp;
	temp=head;
	
	while(temp!=NULL)
	{
		printf(" %d -->",temp->data);
		temp=temp->link;
	}
}

int length(void)
{
	struct node* temp;
	temp=head;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->link;
		count++;
	}
return count;	
}

void search(void)
{
	struct node* temp;
	int num,flag=0,count=1;
	temp=head;
	printf("Enter no. to be searched: ");
	scanf("%d",&num);
	
	while(temp!=NULL)
	{
		if(num==temp->data)
		{
			printf("element found at %d location \n",count);
			flag=1;
			break;
		}
		else
		{
			temp=temp->link;
			count++;
		}
	}
	if(flag==0)
	{
		printf("Element not found \n");
	}
}

void del(void)
{
	int loc,len;
	printf("Enter location to be delelted: ",&loc);
	scanf("%d",&loc);
	
	if(loc>len)
	printf("invalid location.. \n");
	
	else if(loc==1)
	{
		struct node* temp;
		temp=head;
		head=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		struct node* p,*q;
		int i=1;
		p=head;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);	
	}
	display();
}

void reverse(void)
{
	int len,i,j,k,temp;
	struct node* p,*q;
	len=length();
	i=0;j=len-1;
	
	p=q=head;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;j--;
		p=p->link;
		q=head;
		display();
	}
}
