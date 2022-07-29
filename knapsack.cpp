#include<iostream>
using namespace std;
float buuble_sort(float **a ,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(a[0][j]<a[0][j+1]){
				float temp =a[0][j];
				a[0][j]=a[0][j+1];
				a[0][j+1]=temp;
				temp=a[1][j];
				a[1][j]=a[1][j+1];
				a[1][j+1]=temp;
			}
		}
	}
}
int main(){
	int n,m,i;
	cout<<"Enter the no. of objects :- ";
	cin>>n;
	cout<<"Enter the max weight that sack can store :- ";
	cin>>m;
	float obj[4][n];
	for(i=0;i<n;i++){
		cout<<"Enter the profit of obj "<<(i+1)<<"th";
		cin>>obj[0][i];
		cout<<"Enter the weight of obj "<<(i+1)<<"th";
		cin>>obj[1][i];
		obj[2][i]=obj[0][i]/obj[1][i];
		obj[3][i]=0;
			}
	float temp[2][n];
	float *pt[n];
	for( i=0;i<n;i++){
		temp[0][i]=obj[2][i];
		temp[1][i]=i;
		pt[i]=temp[i];
	}
    buuble_sort(pt,n);
	for(int i=0;i<n;i++){
		cout<<	temp[0][i]<<"\t"<<temp[1][i]<<"\n";
	}
	int wt=m;
	i=0;
	while(wt!=0){
		if(obj[1][int(temp[1][i])]<wt){
			wt-=obj[1][int(temp[1][i])];
			obj[3][int(temp[1][i])]=1;
		}
		else{
		obj[3][int(temp[1][i])]=wt/(obj[1][int(temp[1][i])]);
			wt=0;
		}
		i++;
	}
	float max_profit=0;
	for( i=0;i<n;i++){
		cout<<	obj[3][i]<<"\t";
		max_profit+=obj[0][i]*obj[3][i];
	}
	cout<<"\n max profit :- "<<max_profit;
	
	return 0;
}
