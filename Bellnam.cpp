#include <iostream>
#include<climits>
using namespace std;

struct Edge{
    int u,v,w;
};
struct Graph{
    int V,E;
    Edge* e;
};

struct Graph* createGraph(int v,int e){
    Graph* g=new Graph;
    g->V=v;
    g->E=e;
    
    g->e=new Edge[e];
    for(int i=0;i<e;i++){
        cout<<"Enter the u v w for edge #"<<i+1<<" :- ";
        cin>>g->e[i].u>>g->e[i].v>>g->e[i].w;
    }
    return g;
}
void BellmanFord(Graph* g,int source){
    int V=g->V;
    int E=g->E;
    int dist[V];
    
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[source]=0;
    
    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u=g->e[j].u;
            int v=g->e[j].v;
            int w=g->e[j].w;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
        }
    }
    
    for(int j=0;j<E;j++){
        int u=g->e[j].u;
        int v=g->e[j].v;
        int w=g->e[j].w;
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
        cout<<"There will be negative edge cycle....";
        return;}
    }
    cout<<"\n"
    for(int i=0;i<V;i++){
        cout<<dist[i]<<"\t";
    }
    
}
int main(){
    int V,E,S;
    cout<<"Enter the no of vertex :- ";
    cin>>V;
    cout<<"Enter the no of edges :- ";
    cin>>E;
    cout<<"Enter the source vertex consider vertex name start from 0 :- ";
    cin>>S;
    Graph* g=createGraph(V,E);
    
    BellmanFord(g, S);
    
}
