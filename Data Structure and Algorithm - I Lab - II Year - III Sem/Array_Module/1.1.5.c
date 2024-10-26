// Implement a program to count the occurrence of a specific element 
// k
//  in an array of size 
// n



// Input Format:

// The first line of the input represents an integer 
// n
// The second line of the input represents 
// n
//  space separated elements of the array (Integers)
// The third line of the input represents an integer 
// k
//  to search the occurrence in the array.
// Output Format:

// The output contains an integer representing the count of the occurrence of integer 
// k
//  in the array.

// Test case 1
// 5	
// 1 2 3 2 4	
// 2	
// 2	
// Test case 2
// 4	
// 7 8 9 10	
// 6	
// 0

#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int k;
	int count=0;
	scanf("%d",&k);
	for(int i = 0;i<n;i++){
		if(arr[i]==k){
			count++;
		}
	}
	printf("%d",count);
	return 0;
}
