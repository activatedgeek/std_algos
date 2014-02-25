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

inline string numtomcxi(int n){
	char res[8];
	memset(res,'0',sizeof(char)*8);
	res[1]='m',res[3]='c',res[5]='x',res[7]='i';
	int loc=6;
	while(n){
		int temp=n%10;
		res[loc] = char('0'+temp);
		n/=10;
		loc-=2;
	}
	string mcxi = "";
	for(int i=0;i<8;i+=2){
		if(res[i]>'0'){
			if(res[i]=='1')
				mcxi += res[i+1];
			else{
				mcxi += res[i];
				mcxi += res[i+1];
			}
		}
	}
	return mcxi;
}

int mcxitonum(string& m){
	int num=0;
	char req[4]={'m','c','x','i'};
	int mult[4]={1000,100,10,1};
	int state=0;
	while(state<4){
		int i=0;
		while(i<m.length() && m[i]!=req[state])
			++i;
		if(i<m.length()){
			if(i>0 && m[i-1]>='2' && m[i-1]<='9')
				num += (m[i-1]-'0')*mult[state];
			else
				num += mult[state];
		}
		++state;
	}
	return num;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		int res = mcxitonum(a) + mcxitonum(b);
		cout<<numtomcxi(res)<<endl;
	}
	return 0;
}