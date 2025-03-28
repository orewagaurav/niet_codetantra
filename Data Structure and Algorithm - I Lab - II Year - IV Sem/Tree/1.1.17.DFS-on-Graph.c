#include <stdio.h>
#define max 100
void dfs(int graph[max][max],int vertices,int node,int visited[]){
	visited[node]=1;
	printf("%d ",node);
	for(int i=0;i<vertices;i++){
		if(graph[node][i]==1 && visited[i]==0){
			dfs(graph,vertices,i,visited);
		}
	}
}
int main(){
	int v,e;
	scanf("%d",&v);
	scanf("%d",&e);
	int graph[max][max]={0};
	int visited[max]={0};
	for(int i=0;i<e;i++){
		int src,dst;
		scanf("%d %d",&src,&dst);
		graph[src][dst]=1;
		graph[dst][src]=1;
	}
	int start;
	scanf("%d",&start);
	dfs(graph,v,start,visited);
}
