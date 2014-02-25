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
	int t;
	string res,input;
	cin>>t;
	while(t--){
		cin>>input;
		res = input;
		int window = input.length();
		string temp=input;
		reverse(temp.begin(),temp.end());
		input+=temp;
		int mincut = 0;
		repi(i,1,window-1){
			string cut = input.substr(i,window);
			if(cut<res){
				res =cut;
				mincut=i;
			}
		}
		cout<<mincut+1<<endl;
	}
	return 0;
}