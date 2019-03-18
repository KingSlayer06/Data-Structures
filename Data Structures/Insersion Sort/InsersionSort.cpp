#include<iostream>
using namespace std;

void insersion_sort(int *arr,int n) {
	int i,j;
	for(i=1;i<n;i++) {
		int key=arr[i];
		int hole=i;
		while(hole>0 && arr[hole-1]>key) {
			arr[hole]=arr[hole-1];
			hole--;
		}
		arr[hole]=key;
	}
}

int main() {
	int arr[]={2,7,5,3,1,0,4};
	insersion_sort(arr,7);
	int i;
	for(i=0;i<7;i++) {
		cout<<arr[i]<<" ";
	}
}
