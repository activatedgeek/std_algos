#include<iostream>
using namespace std;

void swaputil(int *list, int apos,int bpos){
int temp = list[apos];
list[apos]= list[bpos];
list[bpos] = temp;
}

int main(){
  int list[20] = {23,78,4,12,90,6,76,34,87,92,38,56,45,68,112,397,900,123,57,17};
  int nums=20;
  for(int i=0;i<nums;i++){
  	bool swapped=false;
  	for(int j=0;j<nums-1-i;j++){
  		if(list[j]>list[j+1]){
  			swaputil(list,j,j+1);
  			swapped=true;
  		}
  	}
  	if(!swapped)
  		break;
  }
  
return 0;
}
