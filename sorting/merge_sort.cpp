/**MERGE SORT**/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>   //to directly convert int to string
using namespace std;

void mergesorted(int *arr,int count,int start,int mid,int end){   //Sub-routine to merge two sorted arrays
	int a[mid-start],b[end-mid],i=0;
	while(i<mid-start)
		a[i++]=arr[start+i];
	i=0;
	while(i<end-mid)
		b[i++] = arr[mid+i];
		
	int left=0,right=0;
	i=start;
	while(left<mid-start && right<end-mid){
		if(a[left]<b[right]){
			arr[i++]=a[left++];
		}
		else{
			arr[i++]=b[right++];
		}
	}
	if(left<mid-start){
		while(left<mid-start)
			arr[i++]=a[left++];
	}
	else if(right<end-mid){
		while(right<end-mid)
			arr[i++]=b[right++];
	}
}

void mergesort(int *arr,int count,int low,int high){  //Main routine to divide the problem into two halves in every recursive step
	if(low<high-1){
		int mid = (low+high)/2;
		mergesort(arr,count,low,mid);
		mergesort(arr,count,mid,high);
		mergesorted(arr,count,low,mid,high);
	}
}

int main(){
	fstream input;
	int count,i;
	
	//Filestream to take input from the file
	input.open("input.txt",ios::in);
	if(!input.good()){
		cout<<"Could not open\n";
		return 1;
	}
	input>>count;
	int *arr = new int[count]; //Dyamically allocated memory for the array
	int s;
	i=0;
	while(!input.eof()){
		input>>s;
		arr[i] = s;
		i++;
	}
	input.close();
	
	mergesort(arr,count,0,count); //Call to the mergesort sort routine
	
	delete arr;  //deleting the allocated memory for array to prevent memory leaks
	return 0;
}

