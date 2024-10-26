// Implement a program to reverse the elements of an array of size 
// n
// .



// Input Format:

// The first line of the input contains an integer 
// n
//  representing the number of elements.
// The second line of the input represents 
// n
//  space separated elements of the array (Integers).
// Output Format:

// The output represents the elements of the input array in reversed order.

// Test case 1
// 3	
// 1 2 3	
// [3,·2,·1]	
// Test case 2
// 6	
// 0 -1 2 -3 4 -5	
// [-5,·4,·-3,·2,·-1,·0]

#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("[");
	for(int i =n-1;i>=0;i--){
		if(i > 0){
			printf("%d, ",arr[i]);
		}
		else
			printf("%d]",arr[i]);
	}
	return 0;
}