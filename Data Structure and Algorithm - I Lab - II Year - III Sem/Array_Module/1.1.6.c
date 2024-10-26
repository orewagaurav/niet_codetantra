// Implement a program that takes the number of rows 
// r
//  and columns 
// c
//  from the user to create a 2D array, and then traverses and prints the array in both row-major and column-major order.



// Input Format:

// The first line of input contains two integers 
// r
//  and 
// c
//  separated by a space, representing the number of rows and columns, respectively.
// The second line of input contains 
// r×c
//  space-separated elements to populate the 2D array.

// Output Format:

// The first 
// r
//  lines of the output should each contain 
// c
//  space-separated elements, representing the row-major order traversal of the array.
// The next 
// c
//  lines of the output should each contain 
// r
//  space-separated elements, representing the column-major order traversal of the array.

// Test case 1
// 2 3	
// 1 2 3 4 5 6	
// 1·2·3·⏎	
// 4·5·6·⏎	
// 1·4·⏎	
// 2·5·⏎	
// 3·6·	
// Test case 2
// 2 2	
// 1 3 2 4	
// 1·3·⏎	
// 2·4·⏎	
// 1·2·⏎	
// 3·4·

#include <stdio.h>
int main(){
	int r,c;
	scanf("%d%d",&r,&c);
	int arr[r][c];
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	for(int j = 0;j<c;j++){
		for(int i = 0;i<r;i++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}