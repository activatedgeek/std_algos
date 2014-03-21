#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <vector>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define LIM_UI UINT_MAX
#define LIM_UL ULLONG_MAX

//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

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
	bool res = true;
	for(int i=0;i<n;++i){
		if(!used[i])
			res &= dfs_checkbipartite(adj,i,used,color);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	repi(i,1,t){
		int n,k;
		cin>>n>>k;
		vector<int> adj[n];
		while(k--){
			int a,b;
			cin>>a>>b;
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		bool valid = dutil(adj,n);
		string res = (valid)?"No suspicious bugs found!":"Suspicious bugs found!";

		cout<<"Scenario #"<<i<<":\n";
		cout<<res<<"\n";
	}
	return 0;
}