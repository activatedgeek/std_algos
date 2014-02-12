#include <iostream>
using namespace std;
#define MOD 1000000007

//for fibonacci numbers

long long f(int n){
	long long res[2][2] = {{1,0},{0,1}};
	long long mult[2][2] = {{1,1},{1,0}};
	long long temp[2][2];
	while(n){
		if((n&1)==0){
			temp[0][0] = (mult[0][0]*mult[0][0])%MOD + (mult[0][1]*mult[1][0])%MOD;
			temp[0][1] = (mult[0][0]*mult[0][1])%MOD + (mult[0][1]*mult[1][1])%MOD;
			temp[1][0] = (mult[1][0]*mult[0][0])%MOD + (mult[1][1]*mult[1][0])%MOD;
			temp[1][1] = (mult[1][0]*mult[0][1])%MOD + (mult[1][1]*mult[1][1])%MOD;
			repi(i,0,1)
				repi(j,0,1)
					mult[i][j] = temp[i][j]%MOD;
			n/=2;
		}
		else{
			--n;
			temp[0][0] = (res[0][0]*mult[0][0])%MOD + (res[0][1]*mult[1][0])%MOD;
			temp[0][1] = (res[0][0]*mult[0][1])%MOD + (res[0][1]*mult[1][1])%MOD;
			temp[1][0] = (res[1][0]*mult[0][0])%MOD + (res[1][1]*mult[1][0])%MOD;
			temp[1][1] = (res[1][0]*mult[0][1])%MOD + (res[1][1]*mult[1][1])%MOD;
			repi(i,0,1)
				repi(j,0,1)
					res[i][j] = temp[i][j]%MOD;
		}
	}
	return res[0][1];
}

int main(){
	long long res = f(23);
	return 0;
}