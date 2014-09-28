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
#define MAX 1000000

/*
 *	Logic: Find the deepest fall at any given point in time. So, answer is deficit+1. 
 *	For positive fall just 1.
 */

int main(){
	ios::sync_with_stdio(false);
	int t,n,temp;
	cin>>t;
	long long sum,curmin;
	int c=1;
	while(c<=t){
		sum = 0;
		curmin=MAX;
		cin>>n;
		repi(i,1,n){
			cin>>temp;
			sum+=temp;
			if(sum<0 && sum<curmin)
				curmin = sum;
		}
		curmin = (curmin<0)?(curmin*-1+1):1;
		cout<<"Scenario #"<<c<<": "<<curmin<<"\n";
		++c;
	}
	return 0;
}
