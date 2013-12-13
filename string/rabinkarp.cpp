#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

#define d 256             //range of characters
#define PRIME 104729      //choose a good/large prime for least collisions

vector<int> rabinkarp(string& text,string& pattern,int prime){
	vector<int> pos;
	int m=pattern.length(),n = text.length();
	if(m>n)
		return pos;
	int phash=0;          	
	int thash=0;
	int h=1;
  
  //h = d^(len-1) len = length of pattern
	for(int i=0;i<m-1;++i){
		h *= d;
		h %= prime;
	}

	//hash of pattern and first window hash of text
	for(int i=0;i<m;++i){
		phash = (d*phash + pattern[i])%prime;
		thash = (d*thash + text[i])%prime;
	}

	for(int i=0;i<=n-m;++i){
		if(phash==thash){
			int j=0;
			for(j;j<m;++j)
				if(pattern[j]!=text[i+j])
					break;
			if(j==m)
				pos.push_back(i);
		}

    //slide hash window in text
		if(i<n-m){
			thash = (d*(thash-text[i]*h) + text[i+m])%prime;
			if(thash<0)
				thash += prime;
		}
	}
	return pos;
}

int main(){
	string text;
	string pattern;
	getline(cin,text);
	getline(cin,pattern);
	vector<int> pos = rabinkarp(text,pattern,PRIME);
	for(int i=0;i<pos.size();++i)
		cout<<pos[i]<<" ";
	cout<<endl;
	return 0;
}
