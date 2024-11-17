#include <stdio.h>
void swap(int *a,int *b){
	int tmp = *a;
	*a =*b;
	*b =tmp;
}
void sort(int start[],int end[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(end[i]>end[j]){
				swap(&end[i],&end[j]);
				swap(&start[i],&start[j]);
			}
		}
	}
}
int max(int start[],int end[],int n){
	sort(start,end,n);
	int count =1;
	int lastEnd =end[0];
	for(int i=1;i<n;i++){
		if(start[i]>lastEnd){
			count++;
			lastEnd =end[i];
		}
	}
	return count;
}
int main(){
	int n;
	scanf("%d",&n);
	int start[n],end[n];
	for(int i=0;i<n;i++){
		scanf("%d",&start[i]);
	}
	for(int i =0;i<n;i++){
		scanf("%d",&end[i]);
	}
	int MAX = max(start,end,n);
	printf("%d\n",MAX);
	return 0;
}