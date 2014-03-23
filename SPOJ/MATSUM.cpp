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
#define MAX 1025
int arr[MAX][MAX],tree[MAX][MAX];

void reset(int n){
	repi(i,0,n){
		memset(arr[i],0,sizeof(int)*(n+1));
		memset(tree[i],0,sizeof(int)*(n+1));
	}
}

void update(int x,int y,int change,int n){
	while(x<=n){
		int j=y;
		while(j<=n){
			tree[x][j]+=change;
			j += (j & -j);
		}
		x += (x & -x);
	}
}

int read(int x,int y){
	int sum=0,j;
	while(x){
		j=y;
		while(j){
			sum += tree[x][j];
			j -= (j & -j);
		}
		x -= (x & -x);
	}
	return sum;
}

int read2D(int sx,int sy,int ex,int ey){
	int sum=0;
	sum += read(sx,sy);
	if(ex>1)
		sum -= read(ex-1,sy);
	if(ey>1)
		sum -= read(sx,ey-1);
	if(ex>1 && ey>1){
		sum += read(ex-1,ey-1);
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	int t,n;
	char query[10];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		reset(n);
		scanf("%s",query);
		while(query[0]!='E'){
			if(query[1]=='E'){
				int x,y,val;
				scanf("%d %d %d",&x,&y,&val);
				update(x+1,y+1,val-arr[x+1][y+1],n);
				arr[x+1][y+1]=val;
				//printf("%s %d %d %d\n", query,x,y,val);
			}else if(query[1]=='U'){
				int x1,y1,x2,y2;
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				int sum = read2D(x2+1,y2+1,x1+1,y1+1);
				//printf("%s %d %d %d %d\n", query,x1,y1,x2,y2);
				printf("%d\n",sum);
			}
			scanf("%s",query);
		}
	}
	return 0;
}