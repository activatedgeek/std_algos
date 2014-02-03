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

int arr[]= {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n!=0){
		int j=0;
		while(arr[j]<n && j<15)
			++j;
		int res = (j>0)?j-1:0;
		cout<<res<<endl;
		cin>>n;
	}
	return 0;
}
