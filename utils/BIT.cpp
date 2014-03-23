#include <iostream>
#include <string.h>
using namespace std;

int read(int* tree,int index){
	int sum=0;
	while(index){
		sum += tree[index];
		index -= (index & -index);
	}
	return sum;
}

void update(int* tree,int change,int index,int n){
	while(index<=n){
		tree[index]+=change;
		index+= (index & -index);
	}
}

void initTree(int *tree,int* cumu,int n){
	memset(tree,0,sizeof(int)*(n+1));
	for(int i=1;i<=n;++i){
		update(tree,cumu[i],i,n);
	}
}

/***********for 2D**********/
/*
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
}*/


int main(){
	int n;
	cin>>n;
	int arr[n+1],tree[n+1];
	arr[0]=0;
	for(int i=1;i<=n;++i)
		cin>>arr[i];
	initTree(tree,arr,n);

	for(int i=1;i<=n;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<read(tree,8)-read(tree,7)<<endl;

	return 0;
}