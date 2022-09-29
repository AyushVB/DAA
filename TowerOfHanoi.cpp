#include<iostream>
#include<cmath>
using namespace std;
int i=1;
void TOH(int n ,int l,int m,int r ){
	if(n==0)return ;

	TOH(n-1,l,r,m);
	cout<<i<<"] "<<l<<"->"<<r<<endl;
	i++;
	TOH(n-1,m,l,r);
}

int main(){
	int n;
	cout<<"Enter the no plates";
	cin>>n;
	TOH(n,1,2,3);
	cout<<"\nTotal call : "<<pow(2,n+1)-1;
	cout<<"\nFirst move after which call : "<<n+1;
	cout<<"\nLast move after which call : "<<pow(2,n+1)-2;
	cout<<"\nTotal Moves : "<<pow(2,n)-1;	
}
