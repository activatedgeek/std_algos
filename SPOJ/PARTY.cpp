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
#define MAX 501
//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int dp[MAX][MAX]; //i parties j budget

int fee[MAX],hap[MAX];

void calc(int b,int n){
	repi(i,0,n)
		dp[i][0] = 0;
	repi(i,0,b)
		dp[0][i] = 0;

	repi(i,1,n){
		repi(j,1,b){
			if(fee[i-1]<=j)
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-fee[i-1]]+hap[i-1]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	int finalb = b;
	while(finalb>0 && dp[n][finalb]==dp[n][finalb-1])
		--finalb;

	cout<<finalb<<" "<<dp[n][finalb]<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	int b,n;
	cin>>b>>n;
	while(b!=0 && n!=0){
		repi(i,0,n-1)
			cin>>fee[i]>>hap[i];
		calc(b,n);
		cin>>b>>n;
	}
	return 0;
}