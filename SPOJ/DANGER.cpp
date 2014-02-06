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
	cin>>s;
	while(s!="00e0"){
		int base = (s[0]-'0')*10 + (s[1]-'0');
		int zero = s[3] - '0';
		while(zero--)
			base*=10;
		int res = 2*(base - (int)pow(2,(int)log2(base)))+1;
		cout<<res<<endl;
		cin>>s;
	}
	return 0;
}