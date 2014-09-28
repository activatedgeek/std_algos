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

/*
 *	Logic: Stirling's Formula, precise PI and E values
 */

int main(){
	ios::sync_with_stdio(false);
	int t;
	long long n;
	long double pi = 3.14159265358979323;
  	long double e = 2.71828182845904523536;
	cin>>t;
	long long count;
	while(t--){
		cin>>n;
		count = 1;
		if(n>1){
			count = (long long)ceil((log10((long double)2.0*pi*n)/2.0 + (long double)n * log10((long double)n/e)));
		}
		cout<<count<<"\n";
	}
	return 0;
}
