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
#define MAX 1001

//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

string suffix[MAX];

int main(){
	ios::sync_with_stdio(false);
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		int n=s.length();
		suffix[0]=s;
		repi(i,1,n-1){
			string temp= suffix[i-1];
			temp.erase(0,1);
			suffix[i]=temp;
		}
		sort(suffix,suffix+n);
		int res = suffix[0].length();
		repi(i,1,n-1){
			int j=0,lim = min(suffix[i].length(),suffix[i-1].length());
			while(j<lim && suffix[i-1][j]==suffix[i][j])
				++j;
			res += suffix[i].length()-j;
		}
		cout<<res<<"\n";
	}
	return 0;
}