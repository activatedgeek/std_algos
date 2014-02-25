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
#define MAX 1000001

//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

map<int,int> freq;

int main(){
	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		repi(i,0,n-1){
			int temp;
			cin>>temp;
			pair<map<int,int>::iterator,bool> res = freq.insert(make_pair(temp,1));
			if(!res.second){
				res.first->second++;
			}
		}
		bool valid=true;
		map<int,int>::iterator it = freq.begin();
		int num = it->first,count = it->second;
		++it;
		while(it!=freq.end()){
			if(it->second>count){
				count=it->second;
				num=it->first;
			}
			else if(it->second==count){
				valid=false;
				break;
			}
			++it;
		}
		if(valid && count>n/2){
			cout<<"YES "<<num<<"\n";
		}
		else
			cout<<"NO\n";
		freq.clear();
	}
	return 0;
}