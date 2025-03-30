#include <stdio.h>
#define max 10
int queue[max];
int front=-1;
int rear=-1;
void enqueue(int value){
	if(rear==max-1)
		return;
	if(front ==-1)front++;
	rear++;
	queue[rear]=value;
}
int dequeue(){
	if(front>rear ||front ==-1){
		return -1;
	}
	int key = queue[front];
	front++;
	return key;
}
void bfs(int graph[max][max],int node,int visited[]){
	visited[node]=1;
	enqueue(node);
	while(rear>=front){
		int current = dequeue();
		printf("%d ",current);
		for(int i=0;i<max;i++){
			if(graph[current][i]==1 && visited[i]==0){
				visited[i]=1;
				enqueue(i);
			}
		}
	}
}
int main(){
	int v,e;
	scanf("%d",&v);
	scanf("%d",&e);
	int graph[max][max];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			graph[i][j]=0;
		}
	}
	int src ,dst;
	for(int  i=0;i<e;i++){
		scanf("%d %d",&src,&dst);
		graph[src][dst]=1;
		graph[dst][src]=1;
	}
	int visited[max]={0};
	int start;
	scanf("%d",&start);
	bfs(graph,start,visited);
}
