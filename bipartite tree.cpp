#include <iostream>
#include <queue>
using namespace std;
bool Func(int V, int **G, int src, int colorArr[])
{

    colorArr[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (G[u][u] == 1)
            return false;
        for (int v = 0; v < V; ++v) {
            if (G[u][v] && colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (G[u][v] && colorArr[v] == colorArr[u]){
                return false;
        	}
        }
        
    }
    return true;
}
bool Bipartite(int V,int **G){
    int colorArr[V];
    for (int i = 0; i < V; ++i){
        colorArr[i] = -1;
    }
        
    for (int i = 0; i < V; i++){ 
        if (colorArr[i] == -1)
            if (!Func(V,G, i, colorArr) )
                return false;
    }
       
    return true;
}
int main(){
	int T;
	cin>>T;
	int V;
	bool Ans[T];
	for(int i=0;i<T;i++){
		cin>>V;
		int G[V][V];
		int *pt[V];
		for(int j=0;j<V;j++){
			for(int z=0;z<V;z++){
				cin>>G[j][z];
			}
			pt[j]=G[j]	;	
		}
		Ans[i]=Bipartite(V,pt);
	
	}
	for(int i=0;i<T;i++){
		cout<<Ans[i]<<"\n";
	}

   
    
    return 0;
}
