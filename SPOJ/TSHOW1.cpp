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
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		--n;
		long long w=1,c=2;
		while(n-c>=0){
			++w;
			n-=c;
			c<<=1;
		}
		string res;
		while(w--){
			res = char('5'+n%2)+res;
			n>>=1;
		}
		cout<<res<<"\n";
	}
	return 0;
}