#include<bits/stdc++.h>
using namespace std;

const int INF=INT_MAX;
struct Edge{
int u,v,w;
};
vector<Edge> edges;
vector<int> d;

void solve(){
int n=edges.size();
d[0]=0;
for(int i=0;i<n-1;++i){
    for(Edge e:edges)
        if(d[e.u]<INF)
        d[e.v]=min(d[e.v],d[e.u]+e.w);
}

}

void print(){
    for(int i=0;i<d.size();++i){
if(d[i]==INF){
    cout<<"INF"<<endl;
}else{
cout<<"0 to "<<i<<":"<<d[i]<<endl;
}
}}
int main(){
int n,m;
cout<<"Vertex and Edge:";
cin>>n>>m;
edges.resize(m);
d.resize(n,INF);
for(int i=0;i<m;++i){
        int u,v,w;
    cout<<"Enter edges(u,v,w):";
cin>>u>>v>>w;
edges[i]={u,v,w};

}
solve();
print();
}
