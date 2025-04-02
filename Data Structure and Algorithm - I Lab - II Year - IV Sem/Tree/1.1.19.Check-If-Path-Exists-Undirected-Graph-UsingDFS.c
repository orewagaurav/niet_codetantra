#include<stdio.h>
#include<stdlib.h>
void DFS(int *visited,int v,int adjMatrix[][v],int src){
	visited[src]=1;
	for(int i=0;i<v;i++){
		if(!visited[i] && adjMatrix[src][i]){
			DFS(visited,v,adjMatrix,i);
		}
	}
}
int main(){
	int v;
	scanf("%d",&v);
	int adjMatrix[v][v];
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			if(i==j)
				adjMatrix[i][j]=0;
	
	for(int i=0;i<v;i++){
		for(int j=i+1;j<v;j++){
			int value;
			scanf("%d",&value);
			adjMatrix[i][j]=value;
			adjMatrix[j][i]=value;
		}
	}
	int src,des;
	scanf("%d %d",&src,&des);
	int *visited=calloc(v,sizeof(int));
	DFS(visited,v,adjMatrix,src);
	
	if(visited[des]){
		printf("1");
	}else{
		printf("0");
	}
	
	return 0;
}
