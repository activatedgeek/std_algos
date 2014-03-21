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
#define MAX 200

int sp[MAX][MAX];

bool comp(pair<int,int> a,pair<int,int> b){
	if(a.first==b.first)
		return a.second<b.second;
	return a.first<b.first;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		repi(i,0,n-1)
			repi(j,0,n-1)
				cin>>sp[i][j];
		vector<pair<int,int> > res;
		if(n>1){
			repi(i,0,n-1){
				bool shortest;
				repi(j,i+1,n-1){
					shortest=true;
					repi(k,0,n-1){
						if(k!=i && k!=j){
							if(sp[i][k]+sp[k][j]==sp[i][j]){
								shortest=false;
								break;
							}
						}
						if(!shortest)
							break;
					}
					if(shortest){
						res.push_back(make_pair(i,j));
					}
				}
			}
		}
		sort(res.begin(),res.end(),comp);
		
		if(res.size()>0){
			repi(i,0,res.size()-1){
				cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
			}
		}
	}
	return 0;
}