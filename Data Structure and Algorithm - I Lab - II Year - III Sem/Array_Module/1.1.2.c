// Implement a program to find the sum of all elements in an array of size 
// n
// .



// Input Format:

// The first line of the input represents an integer 
// n
// The second line of the input represents 
// n
//  space separated elements of the array (Integers)
// Output Format:

// The first line of the output represents the input array.
// The second line of the output contains an integer representing the sum of all element of the array.

// Test case 1
// 3	
// 1 2 3	
// [1,·2,·3]⏎	
// 6	
// Test case 2
// 5	
// 4 -2 7 1 0	
// [4,·-2,·7,·1,·0]⏎	
// 10

#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i =0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("[");
	for(int i=0;i<n;i++){
		if(i<n-1){
			printf("%d, ",arr[i]);
		}
		else
			printf("%d]\n",arr[i]);
	}
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	printf("%d",sum);
	return 0;
}