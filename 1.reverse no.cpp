#include <iostream>
using namespace std;
void reverse(int *a,int n){
	int start=0;
	int end=n-1;
	while(start<end){
		int temp=a[start];
		a[start]=a[end];
		a[end]=temp;
		start++;
		end--;
	}
}
int main() {
	int t;
	cin>>t;
	int n;
	while(t!=0){
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		reverse(a,n);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		t--;	
	}
	
	return 0;
}
