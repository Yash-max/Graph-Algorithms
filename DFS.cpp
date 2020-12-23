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
  stack<int> s;
  vector<bool> vis(v,false);
  cout<<"Enter the starting node of dfs : ";
  int x; cin>>x;
  s.push(x);
  vis[x] = true;
  cout<<"DFS : ";
  while(!s.empty()){
    int t = s.top();
    cout<<t<<" ";
    s.pop();
    for(auto itr : adj[t]) {
      if(!vis[itr]) {
        s.push(itr);
        vis[itr] = true;
      }
    }
  }
  return 0;
}
