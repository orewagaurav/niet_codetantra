#include<stdio.h>
int main(){
	int vertices;
	scanf("%d",&vertices);
	int edges;
	scanf("%d",&edges);
	int adjMatrix[vertices][vertices];
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			adjMatrix[i][j]=0;
		}
	}
	for(int i=0;i<edges;i++){
		int src,des;
		scanf("%d %d",&src,&des);
		adjMatrix[src][des]=1;
		adjMatrix[des][src]=1;
	}
	for(int i=0;i<vertices;i++){
		printf("%d ",i);
		int count=0;
		for(int j=0;j<vertices;j++){
			if(adjMatrix[i][j]==1){
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
