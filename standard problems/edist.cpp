//Edit distance algorithm

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

//insert,delete,replace costs
#define IC 1
#define DC 1
#define RC 1

//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int res[2005][2005];

inline void reset(int m,int n){
	repi(i,0,m)
		res[i][0]=i;
	repi(i,0,n)
		res[0][i]=i;
}

inline int minimum(int a,int b,int c){
	int num = min(a,b);
	num= min(num,c);
	return num;
}

int editDistance(string& a,string& b){
	int m=a.length(),n=b.length();
	reset(m,n);
	repi(i,1,m)
		repi(j,1,n){
			int d=(a[i-1]==b[j-1])?0:RC;
			res[i][j] = minimum(res[i-1][j-1]+d,res[i-1][j]+IC,res[i][j-1]+DC);
		}
	return res[m][n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		int dist = editDistance(a,b);
		cout<<dist<<"\n";
	}
	return 0;
}

