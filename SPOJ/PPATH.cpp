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
#define MAX 10050
//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)
bool prime[MAX];

vector<int> getadjList(int k){
	vector<int> list;
	int digs[4];
	int divi=1000;
	repi(i,0,3){
		digs[i]=k/divi;
		k%=divi;
		divi/=10;
	}
	repd(i,3,0){
		int copy = digs[i];
		repi(j,((i>0)?0:1),9){
			if(j!=copy){
				digs[i]=j;
				int change = digs[0]*1000+digs[1]*100+digs[2]*10+digs[3];
				if(prime[change]){
					list.push_back(change);
				}
			}
		}
		digs[i]=copy;
	}
	return list;
}

int bfs(int start,int end){
	queue<pair<int,int> > q;
	bool used[MAX];
	memset(used,false,sizeof(bool)*MAX);
	q.push(make_pair(start,0));
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		if(top.first==end)
			return top.second;
		used[top.first]=true;
		vector<int> adj = getadjList(top.first);
		if(adj.size()>0){
			repi(i,0,adj.size()-1){
				if(!used[adj[i]]){
					q.push(make_pair(adj[i],top.second+1));
				}
			}
		}
	}
	return -1;
}

void preprocess(){
	memset(prime,true,sizeof(bool)*MAX);
	prime[0]=false;
	prime[1]=false;
	repi(i,2,MAX-1){
		if(prime[i]){
			int j=2;
			while(i*j<MAX){
				prime[i*j]=false;
				++j;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	preprocess();
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int res = bfs(a,b);
		cout<<res<<endl;
	}
	return 0;
}