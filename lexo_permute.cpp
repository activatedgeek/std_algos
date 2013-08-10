#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long num=1;

void swap(string& s,int a, int b){
  char temp = s[a];
	s[a] = s[b];
	s[b] = temp; 
}

int firstchar(string s){
int pos = s.length()-2;
	for(int i=pos;i>=0;i--){
		if(s[i]<s[i+1]){
			pos = i;
			break;
		}
	}
return pos;
}

int ceilchar(string s, int fc){
int ceil = fc+1;
int diff=27;
for(int i=ceil;i<s.length();i++){
	if(s[i]>s[fc] && s[i]-s[fc]<diff){
	ceil = i;
	diff = s[i]-s[fc];
	}
}
return ceil;
}

int nextpermute(string& s){
int fc = firstchar(s);
int cc = ceilchar(s,fc);
swap(s,fc,cc);
sort(&s[fc]+1,&s[fc]+s.length()-fc);
num+=1;
if(s!="9876543210"){
	cout<<s<<"\n";
	return 1;
}
else{
	return 0;
}
}

int main(){
string test="0123456789";
while(nextpermute(test));
return 0;
}
