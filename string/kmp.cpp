#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//build array, where lps[i] gives length of longest prefix 
//which is also suffix of sub-string [0..i]
void getlps(string& s,int *lps){
	lps[0]=0;
	int len=0;
	int i=1;
	while(i<s.length()){
		if(s[i]==s[len]){
			++len;
			lps[i] = len;
			++i;
		}
		else{
			if(len!=0)
				len = lps[len-1];
			else{
				lps[i] = 0;
				++i;
			}
		}
	}
}

vector<int> kmp(string& text,string& pattern){
	vector<int> pos;
	int m = pattern.length();
	int n = text.length();
	if(n<m)
		return pos;
	int lps[m];
	getlps(pattern,lps);			//longest prefix substring
	int j=0;
	for(int i=0;i<n;){
		if(pattern[j]==text[i]){
			++i;
			++j;
		}
		if(j==m){
			pos.push_back(i-j);
			j = lps[j-1];
		}
		else if(pattern[j]!=text[i]){
			if(j!=0)
				j = lps[j-1];
			else
				++i;
		}
	}
	return pos;
}

int main(){
	string text;
	string pattern;
	getline(cin,text);
	getline(cin,pattern);
	vector<int> pos = kmp(text,pattern);
	for(int i=0;i<pos.size();++i)
		cout<<pos[i]<<" ";
	cout<<endl;
	return 0;
}
