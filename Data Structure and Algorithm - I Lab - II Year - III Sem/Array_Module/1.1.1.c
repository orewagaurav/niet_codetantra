// Implement a program to find the maximum element in an array of size 
// n

// Input Format:

// The first line of the input represents an integer 
// n
// The second line of the input represents 
// n
//  space separated elements of the array (Integers)
// Output Format:

// The first line of the output represents the input array.
// The second line contains an integer representing the maximum element of the array.

//output cases
// Test case 1
// 4	
// 7 2 9 5	
// [7,·2,·9,·5]⏎	
// 9	
// Test case 2
// 3	
// -1 -4 0	
// [-1,·-4,·0]⏎	
// 0

#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i =0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int max = arr[0];
	printf("[");
	for(int i=0;i<n;i++){
		if(i<n-1){
			printf("%d, ",arr[i]);
		}
		else
			printf("%d",arr[i]);
	}
	printf("]");
	for(int i = 1;i<n;i++){
		if(arr[i]>max){
			max = arr[i];}
		}
	printf("\n");
	printf("%d",max);
	return 0;
}
