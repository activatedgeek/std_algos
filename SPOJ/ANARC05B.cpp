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
#define MAX 10000
//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int a[MAX],b[MAX];

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n;
	while(n!=0){
		repi(i,0,n-1)
			cin>>a[i];
		cin>>m;
		repi(j,0,m-1)
			cin>>b[j];

		int i=0,j=0;
		int si=0,sj=0;
		int total = 0;
		while(i<n && j<m){
			if(a[i]==b[j]){
				total += max(si,sj)+a[i];
				si=0;sj=0;
				++i;++j;
			}
			else if(a[i]<b[j]){
				si += a[i++];
			}
			else if(b[j]<a[i]){
				sj += b[j++];
			}
		}
		while(i<n)
			si += a[i++];
		while(j<m)
			sj += b[j++];
		total += max(si,sj);
		cout<<total<<"\n";
		cin>>n;
	}
	return 0;
}