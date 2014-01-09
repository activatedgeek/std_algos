#include <iostream>
using namespace std;

long long lmult(long long x,long long y,long long mod){
	if(y==0)
		return 0;
	long long d = lmult(x,y/2,mod);
	if(y%2==0)
		return (d+d)%mod;
	else
		return (x+(d+d)%mod)%mod;
}

int main(){
	long long a = 23536456;
	long long b = 23947242;
	long long c = 243242;
	cout<<lmult(a,b,c);
	return 0;
}