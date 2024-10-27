#include <stdio.h>
int main(){
	int n,k;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	int i=0,j=n-1,index,flag=0;
	while(i<=j){
		int mid = (i+j)/2;
		if(arr[mid]==k){
			flag =1;
			index =mid;
			break;
		}
		else if(arr[mid]>k){
			j=mid-1;
		}
		else if(arr[mid]<k){
			i = mid+1;
		}
	}
	if(flag==1)
		printf("%d\n",index);
	else
		printf("Not found\n");
}