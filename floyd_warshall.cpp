#include <iostream>
#include <vector>
#include <limits.h>

#define INF INT_MAX
using namespace std;
//Use 0-indexed vertices
//Dummy value is 1000000000
void insertEdge(vector<int>* graph,int i,int j,int weight){
	graph[i][j]=weight;
}

//Initialize graph with n^2 elements at Infinity (practically large value)
void initGraph(vector<int>* graph,int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			if(i!=j)
				graph[i].push_back(INF);
			else
				graph[i].push_back(0);
	}
}

//Print the matrix
void printMatrix(vector<int>* graph,int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(graph[i][j]==INF)
				cout<<"INF\t";
			else
				cout<<graph[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

vector<int>* floydWarshall(vector<int>* graph,int n){
	vector<int>* solution;
	solution = new vector<int>[n];
	initGraph(solution,n);

	//Set solution initially to adjacency matrix itself (made a copy to preserve the original graph)
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			solution[i][j]=graph[i][j];

	//Three steps, choosing intermediate vertex, choosing source and choosing destination
	for(int k=0;k<n;++k){                                                           //intermediate
		for(int i=0;i<n;++i){														//source
			for(int j=0;j<n;++j){													//destination
				if(solution[i][k]!=INF && solution[k][j]!=INF && solution[i][k]+solution[k][j]<solution[i][j])
					solution[i][j] = solution[i][k]+solution[k][j];
			}
		}
	}
	return solution;
}

/*******Given Graph*******/
/*
0	3	8	INF	-4	
INF	0	INF	1	7	
INF	4	0	INF	INF	
2	INF	-5	0	INF	
INF	INF	INF	6	0
*/
/*******Given Graph*******/

int main(){
	int n=5;
	vector<int> graph[n];
	initGraph(graph,n);

	//set values for the graph (graphic above)
	graph[0][1] = 3;
	graph[0][2] = 8;
	graph[0][4] = -4;
	graph[1][3] = 1;
	graph[1][4] = 7;
	graph[2][1] = 4;
	graph[3][0] = 2;
	graph[3][2] = -5;
	graph[4][3] = 6;
	printMatrix(graph,n);

	vector<int>* solution=NULL;
	solution = floydWarshall(graph,n);						//the solution states the minimum distance between vertex i & j
	printMatrix(solution,n);
	return 0;
}

/*******Resulting Distance*******/
/*
0	1	-3	2	-4	
3	0	-4	1	-1	
7	4	0	5	3	
2	-1	-5	0	-2
8	5	1	6	0
*/
/*******Resulting Distance*******/
