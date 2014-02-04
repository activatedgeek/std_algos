#include <iostream>
using namespace std;

int longestPalin(string& s, int& count){
	int maxlen = 1;
	int start=0,n = s.length();
	int low,high;
	//every char as center
	for(int i=1;i<n;++i){
		low = i-1;high = i; //even length
		while(low>=0 && high<n && s[low]==s[high]){
			if(high-low+1>maxlen){
				start=low;
				maxlen = high-low+1;
			}
			--low;++high;++count;
		}
		low = i-1;high=i+1; //odd length
		while(low>=0 && high<n && s[low]==s[high]){
			if(high-low+1>maxlen){
				maxlen = high-low+1;
				start=low;
			}
			--low;++high;++count;
		}
	}
	//cout<<s.substr(start,maxlen)<<endl;
	//count stores total pallindrome substr length>1
	return maxlen;
}

int main(){
	string test= "daata";
	int count=0;
	longestPalin(test,count);
	cout<<count<<endl;
	return 0;
}