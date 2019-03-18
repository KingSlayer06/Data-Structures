#include<stdio.h>
#include<stdlib.h>

void mergesort(int,int,int);
void merge(int,int,int,int);
int main()
{
	int length,i,a[30];
	printf("Enter length of array: ");
	scanf("%d",&length);
	printf("Enter elements of array: ");
	for(i=0;i<length;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,length-1);
	printf("The sorted array is: ");
	for(i=0;i<length;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}

void mergesort(int a[],int low,int high)
{
	int mid=0;
	if(low>high)
	{
		return;
	}
	else
	{
		mid=low+high/2;
		
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
	int i=0,j=0,k=0,nl,nr;
	nl=mid-low+1;
	nr=high-mid;
	int l[nl],r[nr];
	for(i=0;i<=nl;i++)
	{
		l[i]=a[i+1];
	}
	for(i=0;i<nr;i++)
	{
		r[i]=a[mid+1+i]
	}
	while(i<nl && j<nr)
	{
		if(l[i]<r[j])
		{
			a[k]=l[i];
			i++;
		}
		else
		{
			a[k]=r[j];
			j++
		}
		k++;
	}
	while(i<nl)
	{
		a[k]=l[i];
		i++;
	}
	while(j<nr)
	{
		a[k]=r[j];
		j++;
	}
}
