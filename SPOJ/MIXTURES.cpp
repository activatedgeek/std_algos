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
#define MAX 100
long long arr[MAX];
long long dp[MAX][MAX];
long long color[MAX][MAX];
//iterations
#define repi(i,a,b) for(long long i=a;i<=b;++i)
#define repd(i,a,b) for(long long i=a;i>=b;--i)

void calc(int n){
	repi(i,0,n-1)
		dp[i][i]=0;

	repi(i,0,n-1){
		int c=0;
		repi(j,i,n-1){
			c+=arr[j];
			c%=100;
			color[i][j]=c;
		}
	}

	repd(i,n-2,0)
		repi(j,i+1,n-1){
			dp[i][j] = dp[i+1][j]+arr[i]*color[i+1][j];
			repi(k,i+1,j-1){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+color[i][k]*color[k+1][j]);
			}
		}

	cout<<dp[0][n-1]<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		repi(i,0,n-1){
			cin>>arr[i];
		}
		calc(n);
	}
	return 0;
}