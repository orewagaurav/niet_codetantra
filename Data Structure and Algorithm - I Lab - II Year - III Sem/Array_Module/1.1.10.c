// Write a program to check whether the given element is present or not in the array of elements using linear search.



// Input format:

// The first line of input contains an integer representing the no. of elements of the array.
// The second line of input contains the array of integers separated by space.
// The last line of input contains the key element to be searched.


// Output format:

// If the element is found, print the index.
// If the element is not found, print Not found.


// Sample Test Case:

// Input:

// 7

// 1 2 3 4 3 5 6

// 3

// Output:

// 2

#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n],i,k,l,count=0;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(arr[i]==k){
			l=i;
			count =1;
			break;
		}
	}
	if(count==1){
		printf("%d",l);
	}
	else{
		printf("Not found");
	}
}