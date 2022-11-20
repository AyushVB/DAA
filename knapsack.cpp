#include <iostream>
#include<cmath>
using namespace std;

struct object{
    int index;
    int profit;
    int weight;
    float pw;
    float sel;
};
void Fractional_Knapsack(int *p,int *w,int n,int cap){
    object obj[n];
    for(int i=0;i<n;i++){
        obj[i].index=i+1;
	    obj[i].profit=p[i];
		obj[i].weight=w[i];
		obj[i].pw=float(obj[i].profit)/obj[i].weight;
		obj[i].sel=0;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(obj[j].pw<obj[j+1].pw){
                object temp=obj[j];
                obj[j]=obj[j+1];
                obj[j+1]=temp;
            }
        }
    }
    int rem=cap;
    for(int i=0;i<n;i++){
        if(obj[i].weight>rem){
            obj[i].sel=float(rem)/obj[i].weight;
            rem=0;
            break;
        }
        else{
            obj[i].sel=1;
            rem-=obj[i].weight;
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(obj[j].index>obj[j+1].index){
                object temp=obj[j];
                obj[j]=obj[j+1];
                obj[j+1]=temp;
            }
        }
    }
    float totalProfit=0;
    cout<<"\nSelected item :- ";
    for(int i=0;i<n;i++){
        cout<<obj[i].sel<<" ";
        totalProfit+=obj[i].sel*obj[i].profit;
    }
    cout<<"\nTotal Profit :-"<<totalProfit;
    
}
int max(int i,int j){
    if(i>j)return i;
    return j;
}
void Knapsack_01(int *p,int *w,int n,int cap){
    int table[n+1][cap+1];
    for(int i=0;i<=cap;i++){
        table[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        table[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            if(j>=w[i-1]) {  
               table[i][j]=max(p[i-1]+table[i-1][j-w[i-1]],table[i-1][j]);
            }
            else{
                table[i][j]=table[i-1][j];
            }
        }
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++){
            cout<<table[i][j]<<"\t"; 
        }
        cout<<endl;
    } 
    int temp=cap;
    int sel[n];
    int total_wei=0;
    for(int i=n;i>0;i--){
        if(table[i][temp]!=table[i-1][temp]){
            temp-=w[i-1];
            sel[i-1]=1;
            total_wei+=w[i-1];
        }
        else{
            sel[i-1]=0;
        }
    }
    cout<<"\n\nselected items :- ";
    for(int i=0;i<n;i++){
        cout<<sel[i]<<"\t";
    }
    cout<<"\n\ntotal profit :- "<<table[n][cap];
    cout<<"\n\nweight of selected items :- "<<total_wei;
}
int main(){
    int n,cap;
    cout<<"Enter the no of objects :- ";
    cin>>n;
    cout<<"Enter the max weight that sack can store :- ";
    cin>>cap;
    
    int p[n],w[n];
    
    cout<<"Enter the profit of objects :- ";
    for(int i=0;i<n ;i++){
        cin>>p[i];
    }
    cout<<"Enter the weight of objects :- ";
     for(int i=0;i<n ;i++){
        cin>>w[i];
    }
    
    int ch;
    cout<<"\n1]Fractional Knapsack\n2]0/1 Knapsack\nEnter the choice :- ";
    cin>>ch;
    switch(ch){
        case 1:
            Fractional_Knapsack(p,w,n,cap);
            break;
        case 2:
            Knapsack_01(p,w,n,cap);
            break;
        default:
            cout<<"you selected wrong choice..";
    }
    
    return 0;
}
