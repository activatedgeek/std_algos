#include <iostream>
using namespace std;

bool subsetsum(int *arr,int n,int sum){
	bool subset[sum+1][n+1];  //subset[i][j] = sum i possible with j elements
	
	for(int i=0;i<n+1;++i)
		subset[0][i] = true;

	for(int i=1;i<sum+1;++i)
		subset[i][0] = false;

	for(int cursum=1;cursum<=sum;++cursum){
		for(int count=1;count<=n;++count){
			subset[cursum][count] = subset[cursum][count-1]; //if sum is possible with lesser elements then with more elements also
			
			//check if different counts of subsets can give us a smaller sum
			if(cursum >= arr[count-1])
				subset[cursum][count] = subset[cursum][count] || subset[cursum-arr[count-1]][count-1];
		}
	}
	//string s = (subset[sum][n]==true) ? "Yes\n" : "No\n";
	//cout<<s;
	return subset[sum][n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int note[n];
		for(int i=0;i<n;++i)
			cin>>note[i];
		subsetsum(note,n,m);
	}
	return 0;
}
