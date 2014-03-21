#include <iostream>
using namespace std;

#define MAX 1048580
#define MOD 1000000009  //only prime

long long fact[MAX];

void preprocess(long long n){
	fact[0]=1;
	fact[1]=1;
	repi(i,2,MAX-1){
		fact[i]=i*fact[i-1];
		fact[i]%=MOD;
	}
}

long long modpow(long long a, long long x){
	long long res = 1;
	while(x>0){
		if(x%2==1)
			res = (res*a)%MOD;
		a = (a*a)%MOD;
		x = x/2;
	}
	return res;
}

long long ncr(long long n,long long r){
	if(n<r)
		return 0;
	long long ans=fact[n];
	long long denom=(fact[n-r]*fact[r])%MOD;
	ans = (ans*modpow(denom,MOD-2))%MOD;
	return ans;
}

int main(){
	preprocess();
	cout<<ncr(32,4);
	return 0;
}

