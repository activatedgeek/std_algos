#include <iostream>
using namespace std;
#define MAX 6101
int dp[MAX][MAX];

int LCS(string& s,string& t){
	int result=0;
	int m=s.length(),n=t.length();
	for(int i=0;i<=m;++i){
		for(int j=0;j<=n;++j){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(s[i-1]==t[j-1]){
				dp[i][j] = dp[i-1][j-1] +1;
				result = max(result,dp[i][j]);
			}
			else
				dp[i][j]=0;
		}
	}
	return result;
}

int main(){
	string s = "fft";
	string r = "tff";
	cout<<LCS(s,r);
	return 0;
}