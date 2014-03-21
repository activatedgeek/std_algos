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

long long coef[1000];

inline void eval(long long point,long long deg){
	long long curr = coef[deg--];
	while(deg>=0){
		curr = point*curr + coef[deg--];
	}
	cout<<curr<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	long long deg;
	int p;
	cin>>deg;
	int t=1;
	while(deg!=-1){
		repd(i,deg,0)
			cin>>coef[i];
		cin>>p;
		cout<<"Case "<<t<<":\n";
		repi(i,1,p){
			long long point;
			cin>>point;
			eval(point,deg);
		}
		++t;
		cin>>deg;
	}
	return 0;
}