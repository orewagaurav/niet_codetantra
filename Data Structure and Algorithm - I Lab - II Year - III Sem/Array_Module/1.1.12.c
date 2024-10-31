// You are given a task to sort an array of integers using the Selection Sort algorithm. Your program should follow these specifications:



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

#include <stdio.h>
void selection_sort(int arr[],int n){
	for(int i=0;i<n;i++){
		int small = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[small]){
				int tmp = arr[j];
				arr[j]=arr[small];
				arr[small]=tmp;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int elements=0;
	int arr[n];
	for(int i=0;;i++){
		scanf("%d",&arr[i]);
		elements++;
		char c;
		scanf("%c",&c);
		if(c =='\n'){
			break;
		}
	}
	selection_sort(arr,n);
	if(n==elements){
		for(int i=0;i<n;i++){
			if(i<n-1)
			printf("%d ",arr[i]);
			else
			printf("%d",arr[i]);
		}
		printf("\n");
	}
	else{
		printf("-1\n");
	}
}