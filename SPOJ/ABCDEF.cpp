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

int arr[100];
vector<int> seta,setb;

void print(){
	repi(i,0,seta.size()-1)
		cout<<seta[i]<<" ";
		cout<<endl;

	repi(i,0,setb.size()-1)
		cout<<setb[i]<<" ";
		cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	repi(i,0,n-1)
		cin>>arr[i];
	repi(i,0,n-1)
		repi(j,0,n-1)
			repi(k,0,n-1)
				seta.push_back(arr[i]*arr[j]+arr[k]);

	repi(i,0,n-1)
		repi(j,0,n-1)
			repi(k,0,n-1)
				if(arr[k]!=0)
					setb.push_back(arr[k]*(arr[i]+arr[j]));
	
	sort(seta.begin(),seta.end());
	sort(setb.begin(),setb.end());

	//print();
	int i=0,j=0;
	int count=0;
	while(i<seta.size() && j<setb.size()){
		if(seta[i]==setb[j]){
			int temp = seta[i];
			int top=0,down=0;
			while(seta[i]==temp){
				++top;
				++i;
			}
			while(setb[j]==temp){
				++down;
				++j;
			}
			count += top*down;
		}
		else if(seta[i]<setb[j])
			++i;
		else if(setb[j]<seta[i])
			++j;
	}
	cout<<count<<"\n";
	return 0;
}