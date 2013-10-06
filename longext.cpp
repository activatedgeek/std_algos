//to use numbers larger than 10^18 uptil 10^36, by dividing the number into two long long..


inline void solve(long long n,long long m){
	long long left=0,right=n*m-1,base=1000000000000LL;
	right*=n;
	left=right/base,right%=base;
	left*=m,right*=m;
	left+=right/base,right%=base;
	if(n>2){
		right -= 4*(n-2)*(m-1);
		if(right<0){
			right+=base;
			left--;
		}
	}
	if(m>2){
		right -= 4*(m-2)*(n-1);
		if(right<0){
			right+=base;
			left--;
		}
	}
	if(left>0){
		cout<<left;
		for(long long r=base/10;r>right;r/=10)
			cout<<0;
	}
	cout<<right<<"\n";
}
