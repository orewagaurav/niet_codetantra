// Implement a program to check if an array of size 
// n
//  is sorted in ascending order or not.



// Input Format:

// The first line of the input represents an integer 
// n
// The second line of the input represents 
// n
//  space separated elements of the array (Integers)
// Output Format:

// The output represents True if the array is sorted in ascending order, otherwise, it is False

// Test case 1
// 5	
// 1 2 3 4 5	
// True	
// Test case 2
// 4	
// 10 5 15 20	
// False

#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int count = 0;
	for(int i = 0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j]= arr[j+1];
				arr[j+1]=temp;
				count = 1;
			}
		}
	}
	if(count == 0 ){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
	return 0;
}
