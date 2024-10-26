#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n],i,j,elements=0;
	for(i=0;;i++){
		scanf("%d",&arr[i]);
		elements++;
		char c = getchar();
		if(c=='\n'){
			break;
		}
	}
	if(n==elements){
		for(int gap=n/2;gap>0;gap/=2){
			for(i=gap;i<n;i++){
				int temp = arr[i];
				for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap){
					arr[j]=arr[j-gap];
				}
				arr[j]=temp;
			}
		}
		for(i=0;i<n;i++){
			if(i<n-1){
				printf("%d ",arr[i]);
			}
			else{
				printf("%d",arr[i]);
			}
		}
	}
	else{
		printf("-1");
	}
}