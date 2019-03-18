#include<iostream>
using namespace std;

void selection_sort(int *arr,int end) {
	int i,j;
	for(i=0;i<end;i++) {
		for(j=i+1;j<end;j++) {
			if(arr[i]>arr[j]) {
				swap(arr[i],arr[j]);
			}
		}
	}
}

int main() {
	int arr[]={8,5,9,10,2,1};
	selection_sort(arr,6);
	int i;
	for(i=0;i<6;i++) {
		cout<<arr[i]<<" ";
	}
}
