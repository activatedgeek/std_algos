#include<iostream>
using namespace std;

void swaputil(int *list, int apos,int bpos){
int temp = list[apos];
list[apos]= list[bpos];
list[bpos] = temp;
}

void selectionsort(int *list,int start,int total){
  int minpos = start;
	for(int i=start+1;i<total;i++){
		if(list[i]<list[minpos])
			minpos = i;
	}
	swaputil(list,start,minpos);
	if(start<total)
		selectionsort(list,start+1,total);
}
int main(){
	int list[20] = {23,78,4,12,90,6,76,34,87,92,38,56,45,68,112,397,900,123,57,17};
int nums=20;
for(int i=0;i<nums;i++)
	selectionsort(list,i,nums);
  
return 0;
}
