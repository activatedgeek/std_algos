#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

#define repi(i,a,b) for(int i=a;i<=b;++i)

class store{
public:
	int a,b,c,d;
	store(int A,int B,int C,int D){
		a=A,b=B,c=C,d=D;
	}
};

vector<store> arr;

bool comp(store a,store b){
	if(a.a==b.a)
		return a.b<b.b;
	return a.a<b.a;
}

int main(){
	repi(b,2,100){
		int b3=b*b*b;
		repi(c,b,100){
			int c3=c*c*c;
			repi(d,c,100){
				int d3=d*d*d;
				repi(a,2,100){
					int a3=a*a*a;
					if(a3==b3+c3+d3){
						arr.push_back(store(a,b,c,d));
					}
				}
			}
		}
	}
	sort(arr.begin(),arr.end(),comp);
	repi(i,0,arr.size()-1){
		printf("Cube = %d, Triple = (%d,%d,%d)\n",arr[i].a,arr[i].b,arr[i].c,arr[i].d);
	}
	return 0;
}