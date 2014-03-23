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
#define MOD 10000007

long long power(long long b,long long p){
	if(b==1)
		return 1;
	if(p==1)
		return b;
	else{
		long long res = power(b,p/2);
		res%=MOD;
		res*=res;
		res%=MOD;
		if((p&1)==0)
			return res;
		else
			return (res*b)%MOD;
	}
}

int main(){
	ios::sync_with_stdio(false);
	long long n,k;	
	cin>>n>>k;	
	while(n!=0){
		long long res = 2*power(n-1,k)+power(n,k)+power(n,n)+2*power(n-1,n-1);
		res%=MOD;
		cout<<res<<"\n";
		cin>>n>>k;
	}
	return 0;
}