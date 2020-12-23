#include "bits/stdc++.h"
using namespace std;
void topologicalSort(vector < vector<int> > &adj,vector<bool> &vis,stack<int> &s,int v){
  if(!vis[v]){
  	vis[v] = true;
  	for(auto itr : adj[v]){
    	if(!vis[itr]){
    	  topologicalSort(adj,vis,s,itr);
	    }
  	}
  	s.push(v);
  }
}
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
  vector<bool> vis(v,false);
  stack<int> s;
  for(int i=0;i<v;i++){
    topologicalSort(adj,vis,s,i);
  }
  cout<<"Topological Sorting :\n";
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}
