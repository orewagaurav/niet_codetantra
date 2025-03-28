#include <stdio.h>
int main(){
	int v,e;
	scanf("%d",&v);
	int max =v*(v-1)/2;
	if(v<1 || v>10){
		printf("Invalid number");
	}
	else{
		scanf("%d",&e);
		if(e<0 || e>max){
			printf("Invalid number");
		}
		else{
			int graph[v][v];
			for(int i =0;i<v;i++){
				for(int j=0;j<v;j++){
					graph[i][j]=0;
				}
			}
			int src,dst;
			for(int i=0;i<e;i++){
				scanf("%d %d",&src,&dst);
				graph[src][dst]=1;
				graph[dst][src]=1;
			}
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					printf("%d ",graph[i][j]);
				}
				printf("\n");
			}
		}
	}
}