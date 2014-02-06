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

int main(){
	ios::sync_with_stdio(false);
	int t,n,m,D,arr[500];
	cin>>t;
	while(t--){
		cin>>n>>m>>D;
		repi(i,0,n-1)
			cin>>arr[i];
		int count=0;
		repi(i,0,n-1){
			while(arr[i]-D>0){
				arr[i]-=D;
				++count;
			}
		}
		string res = (count>=m)?"YES\n":"NO\n";
		cout<<res;
	}
	return 0;
}