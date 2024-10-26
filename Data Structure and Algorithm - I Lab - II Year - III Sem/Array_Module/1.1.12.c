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
int main(){
	int n,i,j,elements =0;
	scanf("%d",&n);
	int arr[n];
	for(i=0;;i++){
		scanf("%d",&arr[i]);
		elements++;
		char c;
		scanf("%c",&c);
		if(c =='\n'){
			break;
		}
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
			else{
				continue;
			}
		}
	}
	if(n==elements){
		for(i=0;i<n;i++){
			if(i<n-1){
				printf("%d ",arr[i]);
			}
			else{
				printf("%d\n",arr[i]);
			}
		}
	}
	else{
		printf("-1");
	}
}