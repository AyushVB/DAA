#include <iostream>
using namespace std;

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
	
		for(int i=n-1;i>=0;i--){
			cout<<a[i]<<" ";
		}
		t--;	
	}
	
	return 0;
}
