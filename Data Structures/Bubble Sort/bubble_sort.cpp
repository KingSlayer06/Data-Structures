#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;


class bubble_sort {
	public:
	void sort(int arr[],int n) {
		int temp;
		for(int i=0;i<n-1;i++) {
			for(int j=0;j<n-i-1;j++) {
				if(arr[j]>arr[j+1]) {
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
	}
	
	void disp(int arr[],int n) {
		for(int k=0;k<n;k++) {
			cout<<arr[k]<<" ";
		}
	}
};

int main() {
	bubble_sort bs;
	int arr[]={5,4,3,2,1,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	clock_t tStart = clock();
	bs.sort(arr,n);
	cout<<"Time: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC)<<endl;
	return 0;
	}
