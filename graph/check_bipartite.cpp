#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool dfs_checkbipartite(vector<int>* adj,int cur,vector<bool>& used,vector<bool>& color){
	stack<int> s;
	s.push(cur);
	while(!s.empty()){
		int n = s.top();
		s.pop();
		used[n]=true;
		for(int i=0;i<adj[n].size();++i){
			if(!used[adj[n][i]]){
				s.push(adj[n][i]);
				color[adj[n][i]] = !color[n];
			}
			else if(color[adj[n][i]]==color[n])
				return false;
		}
	}
	return true;
}

bool dutil(vector<int>* adj,int n){
	vector<bool> used(n,false);
	vector<bool> color(n,true);
	bool res = false;
	for(int i=0;i<n;++i){
		if(!used[i])
			res |= dfs_checkbipartite(adj,i,used,color);
	}
	return res;
}


int main(){
	vector<int> adj[2];
	adj[0].push_back(1);
	adj[1].push_back(0);
	//adj[1].push_back(2);
	//adj[2].push_back(1);
	//adj[0].push_back(2);
	//adj[2].push_back(0);
	cout<<dutil(adj,2);
	return 0;
}