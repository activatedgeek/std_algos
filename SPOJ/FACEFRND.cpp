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

set<int> friends;
set<int> fof;

int main(){
	ios::sync_with_stdio(false);
	int t,f;
	cin>>t;
	while(t--){
		cin>>f;
		friends.insert(f);
		int m,temp;
		cin>>m;
		while(m--){
			cin>>temp;
			fof.insert(temp);
		}
	}
	set<int>::iterator fr= fof.begin();
	int count=0;
	while(fr!=fof.end()){
		set<int>::iterator temp = friends.find(*fr);
		if(temp==friends.end())
			++count;
		++fr;
	}
	cout<<count<<"\n";
	return 0;
}