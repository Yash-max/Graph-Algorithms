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
void print(int &x,vector < int > &dist){
  for(int i=0;i<dist.size();i++){
    if(i == x) continue;
    cout<<x<<" - "<<i<<" : "<<dist[i]<<endl;
  }
}
void Dijkstra(vector < vector<int> > &adj,int &x){
  int v = adj.size();
  vector<bool> vis;
  vector<int> dist;
  for(int i=0;i<v;i++){
    vis.push_back(false);
    dist.push_back(INT_MAX);
  }
  dist[x] = 0;
  for(int i=0;i<v-1;i++){
    int u = minKey(vis,dist);
    vis[u] = true;
    for(int j=0;j<v;j++){
      if(adj[u][j] != 0 && !vis[j] && dist[u] + adj[u][j] < dist[j]){
        dist[j] = adj[u][j] + dist[u];
      }
    }
  }
  print(x,dist);
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
  cout<<"Enter the starting vertex : ";
  int x; cin>>x;
  Dijkstra(adj,x);
  return 0;
}
