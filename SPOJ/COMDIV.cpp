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
#define MAX 1000001

/*
 *	Logic: Number of factors of GCD.
 */

bool prime[MAX];

int gcd(int a, int b){
	while(b){
		int r = b;
		b = a%b;
		a = r;
	}
	return a;
}

int factors(int n){
	if(n==1)
		return 1;
	if(n==2 || n==3)
		return 2;
	int res = 1;
	int lim = (int)sqrt(n)+1;
	repi(i,2,lim){
		if(prime[i] && n%i==0){
			int count = 0;
			while(n%i==0){
				++count;
				n/=i;
			}
			res*= count+1;
		}
	}
	return res;
}

void preprocess(){
	memset(prime, true, sizeof(bool)*MAX);
	prime[0] = false;
	prime[1] = false;

	repi(i,2,MAX-1){
		if(prime[i]){
			int j = i+i;
			while(j<MAX){
				prime[j]=false;
				j+=i;
			}
		}
	}
}

int main(){
	preprocess();
	ios::sync_with_stdio(false);
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d", &a, &b);
		printf("%d\n",factors(gcd(a,b)));
	}
	return 0;
}
