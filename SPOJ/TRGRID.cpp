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
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		bool ne = (n%2==0)?true:false;
		bool me = (m%2==0)?true:false;
		if(n>m){
			if(me)
				cout<<"U\n";
			else
				cout<<"D\n";
		}
		else{
			if(ne)
				cout<<"L\n";
			else
				cout<<"R\n";

		}
	}
	return 0;
}