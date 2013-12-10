#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> &list, int num){
  int i = 0;
	while(num>list[i]){
		i++;
		if(i==list.size())
			break;
	}
	list.insert(list.begin()+i,num);
}

int main(){
int list[20] = {23,78,4,12,90,6,76,34,87,92,38,56,45,68,112,397,900,123,1,17};
int nums = 20;

vector<int> finalList;
finalList.push_back(list[0]);
for(int i=1;i<nums;i++)
	insert(finalList,list[i]);

return 0;
}
