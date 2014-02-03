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

int dp[100][13];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		//i inversions with length 0 permutations = 0
		repi(i,0,k)
			dp[i][0] = 0;
		//0 inversions with i length = 1, the sorted permutation
		repi(i,0,n)
			dp[0][i] = 1;
		repi(i,1,k)
			repi(j,1,n){
				int l=0,m=i;
				dp[i][j] = 0;
				while(m>=0 && l<j){
					dp[i][j]+=dp[m][j-1];
					++l;
					--m;
				}
			}
		cout<<dp[k][n]<<"\n";
	}
	return 0;
}