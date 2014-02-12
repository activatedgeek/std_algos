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

vector<int> seta,setb,setc,setd,leftset,rightset;

int main(){
	ios::sync_with_stdio(false);
	int n,a,b,c,d;
	cin>>n;
	while(n--){
		cin>>a>>b>>c>>d;
		seta.push_back(a);
		setb.push_back(b);
		setc.push_back(c);
		setd.push_back(d);
	}

	repi(i,0,seta.size()-1)
		repi(j,0,setb.size()-1)
			leftset.push_back(seta[i]+setb[j]);

	repi(i,0,setc.size()-1)
		repi(j,0,setd.size()-1)
			rightset.push_back(setc[i]+setd[j]);

	int i=0,j=rightset.size()-1,count=0;
	sort(leftset.begin(),leftset.end());
	sort(rightset.begin(),rightset.end());

	while(i<leftset.size() && j>=0){
		if(leftset[i]+rightset[j]==0){
			int ltemp=leftset[i],rtemp=rightset[j];
			int l=0,r=0;
			while(i<leftset.size() && leftset[i]==ltemp){
				++i;++l;
			}
			while(j>=0 && rightset[j]==rtemp){
				--j;++r;
			}
			count += l*r;
		}
		else if(leftset[i]+rightset[j]<0)
			++i;
		else if(leftset[i]+rightset[j]>0)
			--j;
	}
	cout<<count<<endl;
	return 0;
}
