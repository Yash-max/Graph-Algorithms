#include "bits/stdc++.h"
using namespace std;
int main(){
  cout<<"Enter the number of vertices : ";
  int v;  cin>>v;
  vector < vector<int> > adj(v);
  cout<<"Enter the edges :\n";
  while(1){
    int a,b;  cin>>a>>b;
    if(a == -1 || b == -1) break;
    adj[a].push_back(b);
  }
  queue<int> q;
  vector<bool> vis(v,false);
  cout<<"Enter the starting node of bfs : ";
  int x; cin>>x;
  q.push(x);
  vis[x] = true;
  cout<<"BFS : ";
  while(!q.empty()){
    int t = q.front();
    cout<<t<<" ";
    q.pop();
    for(auto itr : adj[t]) {
      if(!vis[itr]) {
        q.push(itr);
        vis[itr] = true;
      }
    }
  }
  return 0;
}
