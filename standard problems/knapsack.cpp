#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

int knapSack(int W, int wt[], int val[], int n){
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++){
       for (w = 0; w <= W; w++){
			if (i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
       }
   } 
   return K[n][W];
}

int main(){
	int wt[] = {2, 2, 3};
    int val[] = {1, 2, 5};
    int  W = 4;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
	return 0;
}