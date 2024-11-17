#include <stdio.h>

void swap(int *a,int *b){
	int temp =*a;
	*a = *b;
	*b =temp;
}
void sort(int values[],int weight[],int n){
	double ratio[n];
	for(int i=0;i<n;i++){
		ratio[i]=(double)values[i]/weight[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ratio[i]<ratio[j]){
				double tmp = ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=tmp;

				swap(&values[i],&values[j]);
				swap(&weight[i],&weight[j]);
			}
		}
	}
}
double max(int values[],int weight[],int n,int capacity){
	sort(values,weight,n);
	double totalVal = 0.0;
	for(int i=0;i<n && capacity>0;i++){
		if(weight[i] <= capacity){
			capacity -= weight[i];
			totalVal += values[i];
		}
		else{
			totalVal += (double)values[i]*capacity/weight[i];
			break;
		}
	}
	return totalVal;
}
int main(){
	int n,capacity;
	scanf("%d %d",&n,&capacity);
	int values[n],weight[n];
	for(int i=0;i<n;i++){
		scanf("%d %d",&values[i],&weight[i]);
	}
	double MAX = max(values,weight,n,capacity);
	printf("%.6f\n",MAX);
	return 0;
}