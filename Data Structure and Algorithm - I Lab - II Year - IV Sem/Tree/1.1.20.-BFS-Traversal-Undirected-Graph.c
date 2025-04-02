#include<stdio.h>
#include<stdlib.h>

void BFS(int *visited,int v,int adjMatrix[][v],int src){
	visited[src]=1;
	int queue[100];
	int front=0,rear=0;
	queue[rear++]=src;
	while(front<rear){
		int temp=queue[front++];
		for(int i=0;i<v;i++){
			if(!visited[i] && adjMatrix[temp][i]){
				visited[i]=1;
				printf("%d ",i);
				queue[rear++]=i;
			}
		}
	}
}
int main(){
	int v;
	scanf("%d",&v);
	int adjMatrix[v][v];
	for(int i=0;i<v;i++){
		for(int j=i+1;j<v;j++){
			if(i==j){
				adjMatrix[i][j]=0;
			}
		}
	}
	for(int i=0;i<v;i++){
		for(int j=i+1;j<v;j++){
			int value;
			scanf("%d",&value);
			adjMatrix[i][j]=value;
			adjMatrix[j][i]=value;
		}
	}
	int *visited=calloc(v,sizeof(int));
	int src;
	scanf("%d",&src);
	if(src>=0 && src<v){
		BFS(visited,v,adjMatrix,src);
	}else{
		printf("-1");
	}
	return 0;
}