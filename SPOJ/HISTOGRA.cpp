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
	long long n;
	cin>>n;
	while(n!=0){
		stack<long long> s;
		long long arr[n];
		repi(i,0,n-1){
			cin>>arr[i];
		}
		long long maxa=0;
		long long i=0;
		while(i<n){
			if(s.empty() || arr[i]>=arr[s.top()]){
				s.push(i++);
			}
			else{
				long long t = s.top();
				s.pop();
				long long area = arr[t]*((s.empty())?i:i-s.top()-1);
				maxa = max(area,maxa);
			}
		}

		while(!s.empty()){
			long long t=s.top();
			s.pop();
			long long area = arr[t]*((s.empty())?i:i-s.top()-1);
			maxa = max(area,maxa);
		}
		cout<<maxa<<endl;
		cin>>n;
	}
	return 0;
}