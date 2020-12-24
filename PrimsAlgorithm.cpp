#include "bits/stdc++.h"
using namespace std;
int minKey(vector<bool> &vis, vector<int> &dist){
  int minElement = INT_MAX,minIndex = 0;
  for(int i=0;i<vis.size();i++){
    if(!vis[i] && minElement > dist[i]){
      minElement = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}
void print(vector < vector<int> > &adj,vector < int > &parent){
  for(int i=1;i<adj.size();i++){
    cout<<"Edge : "<<parent[i]<<" - "<<i<<" Cost: "<< adj[i][parent[i]]<<endl;
  }
}
void PrimsMST(vector < vector<int> > &adj){
  int v = adj.size();
  vector<bool> vis;
  vector<int> parent,dist;
  for(int i=0;i<v;i++){
    vis.push_back(false);
    parent.push_back(-1);
    dist.push_back(INT_MAX);
  }
  parent[0] = -1;
  dist[0] = 0;
  for(int i=0;i<v-1;i++){
    int u = minKey(vis,dist);
    vis[u] = true;
    for(int j=0;j<v;j++){
      if(adj[u][j] != 0 && !vis[j] && adj[u][j] < dist[j]){
        dist[j] = adj[u][j];
        parent[j] = u;
      }
    }
  }
  print(adj,parent);
}
int main(){
  cout<<"Enter the number of vertices : ";
  int v;  cin>>v;
  vector < vector<int> > adj(v,vector<int> (v,0));
  cout<<"Enter the cost of edges :\n";
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      int cost = 0; cin>>cost;
      adj[i][j] = cost;
    }
  }
  PrimsMST(adj);
  return 0;
}
