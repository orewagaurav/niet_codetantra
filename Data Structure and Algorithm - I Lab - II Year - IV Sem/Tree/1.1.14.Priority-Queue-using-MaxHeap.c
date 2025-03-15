#include <stdio.h>
void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j= 0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n-1];
	for(int i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		arr[i]=data;
	}
	sort(arr,n);
	printf("%d",arr[n-1]);
	printf("\n");
	printf("%d",arr[n-2]);
}