#include<iostream>
using namespace std;
#define inf 999
void bellmanFord(int **a,int n){
	int V[n]={0};
	for(int i=1;i<n;i++){
		V[i]=inf;
	}
	for(int i=0;i<n;i++){
		int t=0;
		cout<<i+1<<"=>\t"
		for(int j=0;j<n;j++){
			if(V[i]==inf ||arr[i][j]=0){
				cout<<"\t-"
				continue;
				
			}
			else if(V[i]+arr[i][j]<V[j]){
				V[j]=V[i]+arr[i][j];
				cout<<"\t"<<V[j];
				t=1;
			}
		}
		cout<<endl;
		if(t==0) break;
	}
}
int main(){
	int n;
	cout<<"Enter the no. of vertex : ";
	cin>>n;
	int ** a=new int*[n];
	for(int i=0;i<n;i++){
		a[i]=new int [n];
		for(int j=0;j<n;j++){
			a[i][j]=0;
			
		}
	}
	while(1){
		int i,j,t=0;
		cout<<"Enter the i and j";
		cin>>i;
		cin>>j;
		cout<<"Enter the cost of edge";
		cin>>a[i][j];
		cout<<"you want to terminate press 1 otherwise 0 : ";
		cin>>t;
		if(t==1)break;
	}
	bellmanFord(a,n);
	
}
