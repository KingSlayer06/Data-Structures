#include<iostream>
using namespace std;

int partition(int *arr,int start,int end) {
	int pivot=arr[end];
	int pindex=start;
	int i;
	for(i=start;i<end;i++) {
		if(arr[i]<=pivot) {
			swap(arr[i],arr[pindex]);
			pindex++;
		}
	}
	swap(arr[pindex],arr[end]);
	return pindex;
}

void quicksort(int *arr,int start,int end) {
	if(start<end) {
		int pivot=partition(arr,start,end);
		quicksort(arr,start,pivot-1);
		quicksort(arr,pivot+1,end);
	}
}

int main() {
	int arr[]={7,6,5,4,3,2,1,0};
	quicksort(arr,0,7);
	int i;
	for(i=0;i<8;i++) {
		cout<<arr[i]<<" ";
	}
}
