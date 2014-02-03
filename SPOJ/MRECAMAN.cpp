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
#define MAX 500001

//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int a[MAX];
set<int> used;

void preprocess(){
	a[0]=0;
	repi(i,1,MAX-1){
		a[i] = a[i-1]-i;
		if(a[i]>0){
			pair<set<int>::iterator, bool> res = used.insert(a[i]);
			if(!res.second){
				a[i] = a[i-1]+i;
			}
		}else{
			a[i] = a[i-1] + i ;
		}
		used.insert(a[i]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	preprocess();
	int n;
	cin>>n;
	while(n!=-1){
		cout<<a[n]<<"\n";
		cin>>n;
	}
	return 0;
}