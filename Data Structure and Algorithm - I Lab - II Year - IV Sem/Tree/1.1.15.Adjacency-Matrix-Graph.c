#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n][n];
	if(n<=10 && n>=1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		if(n==1){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d\n",arr[i][j]);
				}
				printf("\n");
			}
		}
		else if(n>1){
			for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						printf("%d ",arr[i][j]);
					}
					printf("\n");
				}
		}
	}
	else{
		printf("-1");
	}
}
