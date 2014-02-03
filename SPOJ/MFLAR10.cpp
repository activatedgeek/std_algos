#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <vector>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define LIM_UI UINT_MAX
#define LIM_UL ULLONG_MAX

//iterations
#define repi(i,a,b) for(int i=a;i<=b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)

int main(){
	ios::sync_with_stdio(false);
	string s;
	getline(cin,s);
	while(s!="*"){
		while(s.length()<1){
			getline(cin,s);
		}
		if(s=="*")
			break;
		stringstream ss;
		ss<<s;
		char c;
		string temp;
		bool taut = true;
		ss>>temp;
		c = temp[0];
		if(c<'a')
			c+=32;
		while(ss>>temp){
			char cur = temp[0];
			if(cur<'a')
				cur+=32;
			if(cur!=c){
				taut=false;
				break;
			}
		}
		string res = (taut==true)?"Y\n":"N\n";
		cout<<res;
		getline(cin,s);
	}
	return 0;
}