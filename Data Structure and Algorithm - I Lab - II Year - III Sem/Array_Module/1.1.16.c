// You are given a task to sort an array of integers using the Counting Sort algorithm. Your program should follow these specifications:



// Input Format:

// The first line contains a single integer n, which represents the number of elements in the array.
// The second line contains n space-separated integers, which are the elements of the array.


// Output Format:

// Print the sorted array on a single line, with elements separated by spaces.
// If the number of elements does not match n, print -1 and do not perform any sorting.


// Constraints:

// The number of elements n is between 1 and 1000.
// Each integer in the array is between -1,000,000 and 1,000,000.

// Test case 1
// 6	
// 10 5 3 8 6 7	
// 3·5·6·7·8·10	
// Test case 2
// 3	
// 2 4 6 8	
// -1

#include<stdio.h>
int getMax(int arr[],int n){
	int max=arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
int getMin(int arr[],int n){
	int min=arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]<min){
			min=arr[i];
		}
	}
	return min;
}
void countingSort(int arr[],int n,int output[]){
	int max=getMax(arr,n);
	int min=getMin(arr,n);
	int count[max];
	for(int i=min;i<max+1;i++){
		count[i]=0;
	}
	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	int index=0;
	for(int i=min;i<max+1;i++){
		if(count[i]!=0){
			for(int j=0;j<count[i];j++){
				output[index++]=i;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int output[n];
	int elements=0;
	int arr[n];
	for(int i=0;;i++){
		scanf("%d",&arr[i]);
		elements++;
		char c=getchar();
		if(c=='\n'){
			break;
		}
	}
	if(n==elements){
		countingSort(arr,n,output);
		for(int i=0;i<n-1;i++){
			printf("%d ",output[i]);
		}
		printf("%d\n",output[n-1]);
	}
	else{
		printf("-1");
	}
}