//Largest sum contiguous sub-array
#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(vector<int>& arr,int start,int end){
	if(arr.size()<1 || start>end)
		return 0;
	int netmax = arr[start-1];
	int curmax = arr[start-1];
	for(int i=start;i<end;++i){
		curmax = max(arr[i], curmax+arr[i]);
		netmax = max(curmax,netmax);
	}
	return netmax;
}

int main(){
	int n = 8;
	int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
	vector<int> arr(a,a+n);
	cout<<maxSubArraySum(arr,1,8);
}