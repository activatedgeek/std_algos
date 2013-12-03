//Longest non-decreasing subsequence using Dynamic Programming
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int LIS(int* seq,int n){
	vector<int> solution(n,1);
	//solution[i] stores the LIS uptil that point
	for(int i=0;i<n;++i){
		for(int j=0;j<i;++j){
			if(seq[j]<=seq[i] && solution[i]<solution[j]+1)
				solution[i]=solution[j]+1;
		}
	}
	int m  =max_element(solution.begin(),solution.end())-solution.begin();
	return solution[m];
}

int main(){
	int n = 9;
	int seq[]={10, 22, 9, 33, 21, 50, 41, 60, 80};
	cout<<LIS(seq,n);
	return 0;
}
