#include <iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		int t=0;
		int m=sqrt(i);
		for (int j = 2; j <=m; j++){
        	if (i % j == 0){
				t=1;
				break;
			}
	   }
	   if(t==0){
	   	cout<<i<<" ";
	   }
	}
}
