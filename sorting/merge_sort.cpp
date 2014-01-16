#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream> 
using namespace std;

long long mergesorted(long long *arr,long long n,long long low,long long mid,long long high){
	long long i=low,j=mid,k=low;
	long long temp[n],count=0;
	while(i<mid && j<=high){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			temp[k++]=arr[j++];
			count+= (mid-i);
		}
	}

	while(i<mid)
		temp[k++]=arr[i++];
	while(j<=high)
		temp[k++]=arr[j++];
	for(i=low;i<=high;++i)
		arr[i]=temp[i];
	return count;
}

long long mergesort(long long *arr,long long n,long long low,long long high){
	long long count=0;
	if(low<high){
		long long mid = (low+high)/2;
		count+=mergesort(arr,n,low,mid);
		count+=mergesort(arr,n,mid+1,high);
		count+=mergesorted(arr,n,low,mid+1,high);
	}
}

int main(){
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long arr[n];
		for(long long i=0;i<n;++i)
			cin>>arr[i];

		long long res = mergesort(arr,n,0,n-1);
		cout<<res+1<<"\n";
	}
	return 0;
}