#include <iostream>
using namespace std;

bool isSafe(int **a, int n,int x,int y){
    int row,col;
    //column check
    for(row=0;row<x;row++){
        if(a[row][y]==1)return false;
    }
    
    //diagonal check upper left
    row=x;
    col=y;
    while(row>=0 && col>=0){
        if(a[row][col]==1)return false;
        row--;
        col--;
    }
    
    //diagonal check upper right
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(a[row][col]==1)return false;
        row--;
        col++;
    }
    
    return true;
}

bool nQueen(int **a, int n,int x){
    if(x>=n)return true;
    for(int col=0;col<n;col++){
        if(isSafe(a,n,x,col)){
            a[x][col]=1;
            if(nQueen(a,n,x+1))return true;
            a[x][col]=0;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the no of queens :- ";
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++){
        a[i]=new int [n];
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    if(nQueen(a,n,0)){
        cout<<"\nqueens placed :-\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"we cant place queen...";
    }

    return 0;
}
