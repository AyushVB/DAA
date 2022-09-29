#include<iostream>
using namespace std;
void print(int n){
	if(n==0) return;
	cout<<"* ";	
	print(n-1);
}
void pattern(int n){
	if(n==0) return;
	pattern(n-1);
	print(n);

	
	cout<<endl;
}
int main(){
	int n;
	cout<<"Enter the no. : ";
	cin>>n;
	pattern(n);
} 

