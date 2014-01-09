#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class nump{
public:
	int cur;
	int src;
	nump(int c,int s){
		cur=c;
		src=s;
	}
};

bool dfs_checkcycle(vector<int>* adj,int cur,int src,vector<bool>& used){
	stack<nump> s;
	s.push(nump(cur,src));
	while(!s.empty()){
		nump pr = s.top();
		s.pop();
		used[pr.cur]=true;
		for(int i=0;i<adj[pr.cur].size();++i){
			if(!used[adj[pr.cur][i]])
				s.push(nump(adj[pr.cur][i],pr.cur));
			else if(adj[pr.cur][i]!=pr.src)
				return true;
		}
	}
	return false;
}

bool dutil(vector<int>* adj,int n){
	vector<bool> used(n,false);
	bool res = false;
	for(int i=0;i<n;++i){
		if(!used[i])
			res |= dfs_checkcycle(adj,i,i,used);
	}
	return res;
}


int main(){
	vector<int> adj[3];
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[0].push_back(2);
	adj[2].push_back(0);
	cout<<dutil(adj,3);
	return 0;
}