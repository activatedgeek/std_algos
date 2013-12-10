#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <limits.h>
using namespace std;

#define INF INT_MAX

int findValidMin(vector<int>& distance,vector<bool>& spt){
	int min = INT_MAX,index;
	for(int i=0;i<distance.size();++i){
		if(!spt[i] && distance[i]<=min)
			min = distance[i],index = i;
	}
	return index;
}

void dijkstra(vector<int> *graph,int src){
	int V = graph[0].size();
	vector<int> distance(V,INT_MAX);					//holds distances from source to vertex i
	vector<bool> spt(V,false);							//if vertex i comes in shortest path tree or final min distance has been calculated from src to i
	distance[src]=0;	
	
	for(int count=0;count<V-1;++count){
		int u = findValidMin(distance,spt);
		//cout<<"chosen "<<u<<endl;
		spt[u]=true;
		//graph[u][j] checks for connectivity, spt checks if not finalized
		for(int j=0;j<V;++j){
			if(!spt[j] && graph[u][j]!=INF && distance[u]+graph[u][j]<distance[j])
				distance[j] = distance[u]+graph[u][j];
		}
	}

	cout<<"\nThe distances are: ";
	for(int i=0;i<V;++i)
		cout<<distance[i]<<" ";
	cout<<endl;
}

int main(){
	int V = 9;
    int g[][9] = {{0, 4, INF, INF, INF, INF, INF, 8, INF},
                  {4, 0, 8, INF, INF, INF, INF, 11, INF},
                  {INF, 8, 0, 7, INF, 4, INF, INF, 2},
                  {INF, INF, 7, 0, 9, 14, INF, INF, INF},
                  {INF, INF, INF, 9, 0, 10, INF, INF, INF},
                  {INF, INF, 4, 14, 10, 0, 2, INF, INF},
                  {INF, INF, INF, INF, INF, 2, 0, 1, 6},
                  {8, 11, INF, INF, INF, INF, 1, 0, 7},
                  {INF, INF, 2, INF, INF, INF, 6, 7, 0}
                 };

	vector<int> graph[V];
	for(int i=0;i<V;++i)
		for(int j=0;j<V;++j){
			graph[i].push_back(g[i][j]);
		}
	dijkstra(graph,0);
	return 0;
}
