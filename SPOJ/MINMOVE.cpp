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

int main(){
	ios::sync_with_stdio(false);
	int t,i,j,k;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		int n=s.length();
		int lim=n*2;
		i=0,j=1,k=0;
		while(i+k<lim && j+k<lim){
			char a = s[(i+k)%n];
			char b = s[(j+k)%n];
			if(a==b)
				++k;
			else if(a>b){
				i += k+1;
				if(i<=j)
					i=j+1;
				k=0;
			}
			else if(a<b){
				j += k+1;
				if(j<=i)
					j=i+1;
				k=0;
			}
		}
		int res = min(i,j);
		cout<<res<<endl;
	}
	return 0;
}