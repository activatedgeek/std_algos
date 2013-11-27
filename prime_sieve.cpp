#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

//sieve for calculations upto 1e6 using one arrays
void sieve_n(bool *prime_set1,long long n){
	memset(prime_set1,true,sizeof(bool)*n);
	prime_set1[0]=false;
	prime_set1[1]=false;
	long long lim = (long long)(sqrt(n));
	for(long long i=2;i<=lim;++i){
		if(prime_set1[i]){
			for(long long k=i*i;k<n;k+=i){
				prime_set1[k]=false;
			}
		}
	}
}

//sieve for calculations upto 1e12 using two arrays
void sieve_n_n(bool *prime_set1,bool *prime_set2,long long n){
	memset(prime_set1,true,sizeof(bool)*n);
	memset(prime_set2,true,sizeof(bool)*n);
	prime_set1[0]=false;
	prime_set1[1]=false;
	long long lim = (long long)(sqrt(n+n));
	for(long long i=2;i<=lim;++i){
		if(i<n){
			if(prime_set1[i]){
				for(long long k=i*i;k<n+n;k+=i){
					if(k<n)
						prime_set1[k]=false;
					else
						prime_set2[k-n]=false;
				}
			}
		}
		else{
			if(prime_set2[i-n]){
				long long temp = i-n;
				for(long long k=temp*temp;k<n;k+=temp){
					prime_set2[k-n]=false;
				}
			}
		}
	}
}

//sieve for calculations upto 1e18 using three arrays
void sieve_n_n_n(bool *prime_set1,bool *prime_set2,bool *prime_set3,long long n){
	memset(prime_set1,true,sizeof(bool)*n);
	memset(prime_set2,true,sizeof(bool)*n);
	memset(prime_set3,true,sizeof(bool)*n);
	prime_set1[0]=false;
	prime_set1[1]=false;
	long long lim = (long long)(sqrt(n+n+n));
	for(long long i=2;i<=lim;++i){
		if(i<n){
			if(prime_set1[i]){
				for(long long k=i*i;k<n+n+n;k+=i){
					if(k<n)
						prime_set1[k]=false;
					else if(k<n+n)
						prime_set2[k-n]=false;
					else
						prime_set3[k-n-n]=false;
				}
			}
		}
		else if(i<n+n){
			long long fi = i-n;
			if(prime_set2[fi]){
				for(long long k=fi*fi;k<n+n;k+=fi){
					if(k<n)
						prime_set2[k]=false;
					else
						prime_set3[k-n]=false;
				}
			}
		}
		else{
			long long fi = i-n-n;
			if(prime_set3[fi]){
				for(long long k=fi*fi;k<n;k+=fi){
					prime_set3[k]=false;
				}
			}
		}
	}
}

//checking n array primes
bool check_n(bool *prime_set1,long long k,long long n){
	if(k<n)
		return prime_set1[k];
	else
		return false;
}

//checking n_n array primes
bool check_n_n(bool *prime_set1,bool *prime_set2,long long k,long long n){
	if(k<n)
		return prime_set1[k];
	else if(k<n+n)
		return prime_set2[k-n];
	else
		return false;
}

//checking n_n_n array primes
bool check_n_n_n(bool *prime_set1,bool *prime_set2,bool *prime_set3,long long k,long long n){
	if(k<n)
		return prime_set1[k];
	else if(k<n+n)
		return prime_set2[k-n];
	else if(k<n+n+n)
		return prime_set3[k-n-n];
	else
		return false;
}

int main(){
	long long n=(long long)1500;
	bool primes_set1[n],primes_set2[n],primes_set3[n];

	//for max upto 1e6
	//sieve_n(primes_set1,n);

	//for max upto 2*1e6
	//sieve_n_n(primes_set1,primes_set2,n);

	//for max upto 3*1e6
	//sieve_n_n_n(primes_set1,primes_set2,primes_set3,n);
	return 0;
}
