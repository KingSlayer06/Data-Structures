#include<stdio.h>
int rec(int);
int main()
{
	int num,f;
	printf("Enter any no. \n");
	scanf("%d",&num);
	f=rec(num);
	printf("Factorial value is %d",f);
	return 0;
}
int rec(int x)
{
int f;

if(x==1)
	return(1);
else
    f=x*rec(x-1);
return(f);    
}

