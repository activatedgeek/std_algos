#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class times{
public:
	int arr,dep;
	times(int a,int d){
		arr=a;
		dep=d;
	}
};

bool comp(times a,times b){
	if(a.dep==b.dep)
		return a.arr>b.arr;
	return a.dep<b.dep;
}

int maxtogether(vector<times>& arr){
	int i,j;
	//first always selected
	int res =1;
	i=0;
	for(int j=1;j<arr.size();++j){
		if(arr[j].arr>=arr[i].dep){
			++res;
			i=j;
		}
	}
	return res;
}

int main(){
	vector<times> arr;
	arr.push_back(times(1,2));
	arr.push_back(times(3,4));
	arr.push_back(times(0,6));
	arr.push_back(times(5,7));
	arr.push_back(times(8,9));
	arr.push_back(times(5,9));
	sort(arr.begin(),arr.end(),comp);
	cout<<maxtogether(arr)<<endl;
	return 0;
}