#include <iostream>
using namespace std;

int power(int b, int p){
	int res=1;
	while(p){
		if((p&1)==0){
			b*=b;
			p/=2;
		}
		else{
			--p;
			res*=b;
		}
	}
	return res;
}

int main(){
	cout<<power(2,10);
	return 0;
}