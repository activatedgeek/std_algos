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

int gcd(int a,int b){
  while(b){
    int r = b;
    b = a%b;
    a = r;
  }
  return a;
}

int calc(int a,int b,int c){
	if(a<b)
		swap(a,b);
	int g = gcd(a,b);
	if(c%g!=0)
		return -1;
	a/=g,b/=g,c/=g;
	if(c>a && c>b)
		return -1;
	int x=0,y=0,n=0;
	do{
		if(x==a)
			x=0;
		else if(y==0)
			y=b;
		else{
			int t=min(a-x,y);
			y-=t;
			x+=t;
		}
		++n;
	}while(x!=0 || y!=0);

	x=0,y=0;
	int res=n;
	repi(i,0,n-1){
		if(x==c || y==c)
			res = min(res,min(i,n-i));
		if(x==a)
			x=0;
		else if(y==0)
			y=b;
		else{
			int t=min(a-x,y);
			y-=t;
			x+=t;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	int t,A,B,C;
	cin>>t;
	while(t--){
		cin>>A>>B>>C;
		int res = calc(A,B,C);
		cout<<res<<"\n";
	}
	return 0;
}