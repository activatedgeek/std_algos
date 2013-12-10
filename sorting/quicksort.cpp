#include<iostream>
using namespace std;

void moveTill(int *a,int start,int end){
if(start>=end){
  int i=start;
	while(i>end){
		int temp = a[i];
		a[i]=a[i-1];
		a[i-1]=temp;
		i--;
	}
}
else{
	int i=start;
	while(i<end){
		int temp = a[i];
		a[i]=a[i+1];
		a[i+1]=temp;
		i++;
	}

}
}

int partition(int *A,int p,int q){
	int i=p;
	int j=i+1;
	//Partitioning Subroutine
	for(j;j<q;j++){
	  if(A[j]<A[p]){
		  moveTill(A,j,i+1);
		  i++;
	  }
	}
	moveTill(A,p,i);
	//Partitioning Subroutine
	
	return i;
}

void quickSort(int *A,int p,int q){
	if(p<q){
      int r = partition(A,p,q); //make sure two separate variables are declared
	  int s = partition(A,p,q); //otherwise the new one is passed to the next quicksort recursive call
	  quickSort(A,p,r-1);
	  quickSort(A,s+1,q);
	}
}

int main(){
	int list[20] = {23,78,4,12,90,6,76,34,87,92,38,56,45,68,112,397,900,123,1,17};
 int n=20;
	quickSort(list,0,n);
	return 0;
}
