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
#define MAX 1001

int lista[MAX],listb[MAX];

//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		repi(i,0,n-1)
			cin>>lista[i];
		cin>>m;
		repi(i,0,m-1)
			cin>>listb[i];
		int res = INT_MAX;
		repi(i,0,n-1)
			repi(j,0,m-1){
				int diff = abs(lista[i]-listb[j]);
				res = min(res,diff);
			}
		cout<<res<<"\n";
	}
	return 0;
}