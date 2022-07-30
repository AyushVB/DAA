#include <iostream>
using namespace std;
int maxSum(int a[],int n){
	int max_so_far=0,max_ending_here=0;
	for(int i=0;i<n;i++){
		max_ending_here+=a[i];
		if(max_ending_here<0){
			max_ending_here=0;
		}
		if(max_so_far<max_ending_here){
			max_so_far=max_ending_here;
		}
	}
	return max_so_far;
}
int main(){
	int n;
	cout<<"Enter the no of elements in array";
	cin>>n;
	int a[n];
	cout<<"enter the values in array";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"maximum sum of any contigous subarray of the array"<<maxSum(a,n);
	return 0;
	
}
