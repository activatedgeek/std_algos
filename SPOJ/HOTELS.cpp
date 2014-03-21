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
#define MAX 300000
//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)
int arr[MAX];

int findlongest(int n,int m){
	int maxs=0,curmax=0;
	int index=0,i=0;
	while(i<n){
		if(curmax+arr[i]<=m){
			curmax+=arr[i++];
			maxs = max(maxs,curmax);
		}
		else{
			if(index<n)
				curmax-=arr[index++];
		}
	}
	return maxs;
}

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	repi(i,0,n-1){
		cin>>arr[i];
	}
	cout<<findlongest(n,m);
	return 0;
}