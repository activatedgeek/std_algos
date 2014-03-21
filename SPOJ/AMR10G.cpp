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

#define LIM_I INT_MAX
#define LIM_UL ULLONG_MAX
//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int main(){
	ios::sync_with_stdio(false);
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int arr[n];
		repi(i,0,n-1){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int minimum = arr[k-1]-arr[0];
		for(int i=1;i+k<=n;++i){
			int diff = arr[i+k-1]-arr[i];
			minimum = min(minimum,diff);
		}
		cout<<minimum<<"\n";
	}
	return 0;
}