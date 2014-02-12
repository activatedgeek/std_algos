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

#define LIM_L LLONG_MAX
#define MAX 10000000
#define MOD 1000000007
//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int power(int b, int p){
	int res=1;
	while(p){
		if((p&1)==0){
			b*=b;
			p/=2;
		}
		else{
			--p;
			res*=b;
		}
	}
	return res;
}

long long f(long long n){
	long long res[2][2] = {{1,0},{0,1}};
	long long mult[2][2] = {{1,1},{1,0}};
	long long temp[2][2];
	while(n){
		if((n&1)==0){
			temp[0][0] = (mult[0][0]*mult[0][0])%MOD + (mult[0][1]*mult[1][0])%MOD;
			temp[0][1] = (mult[0][0]*mult[0][1])%MOD + (mult[0][1]*mult[1][1])%MOD;
			temp[1][0] = (mult[1][0]*mult[0][0])%MOD + (mult[1][1]*mult[1][0])%MOD;
			temp[1][1] = (mult[1][0]*mult[0][1])%MOD + (mult[1][1]*mult[1][1])%MOD;
			repi(i,0,1)
				repi(j,0,1)
					mult[i][j] = temp[i][j]%MOD;
			n/=2;
		}
		else{
			--n;
			temp[0][0] = (res[0][0]*mult[0][0])%MOD + (res[0][1]*mult[1][0])%MOD;
			temp[0][1] = (res[0][0]*mult[0][1])%MOD + (res[0][1]*mult[1][1])%MOD;
			temp[1][0] = (res[1][0]*mult[0][0])%MOD + (res[1][1]*mult[1][0])%MOD;
			temp[1][1] = (res[1][0]*mult[0][1])%MOD + (res[1][1]*mult[1][1])%MOD;
			repi(i,0,1)
				repi(j,0,1)
					res[i][j] = temp[i][j]%MOD;
		}
	}
	return res[0][1];
}

int main(){
	ios::sync_with_stdio(false);
	long long t,l,r;
	cin>>t;
	while(t--){
		cin>>l>>r;
		long long res = f(r+2) - f(l+1);
		if(res<0)
			res += MOD;
		cout<<res<<endl;
	}
	return 0;
}