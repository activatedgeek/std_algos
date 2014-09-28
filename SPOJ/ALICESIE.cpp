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
 *	Logic: Half (check even and odd off by one) the numbers always remain unmarked.
 */

int main(){
	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<((n%2==0)?n/2:n/2+1)<<"\n";
	}
	return 0;
}
