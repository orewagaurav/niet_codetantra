// Implement a program that determines whether a given matrix is sparse and, if so, prints its non-zero elements. A matrix is considered sparse if the number of zero elements is greater than the number of non-zero elements.



// Input Format:

// The first line of input contains two integers r and c
// separated by a space, representing the number of rows and columns, respectively.
// The next r lines each contain c
// space-separated integers, representing the elements of the matrix.


// Output Format:

// The first line of the output should be a boolean value (True or False), indicating whether the matrix is sparse.
// If the matrix is sparse, print the non-zero elements in the format row column value, each on a new line. If the matrix is not sparse, print nothing.

// Test case 1
// 3 3	
// 0 0 3	
// 0 0 6	
// 0 0 0	
// True⏎	
// 0·2·3⏎	
// 1·2·6	
// Test case 2
// 3 3	
// 1 2 3	
// 4 0 6	
// 7 8 9	
// False

#include <stdio.h>
int main(){
	int r,c,i,j;
	scanf("%d%d",&r,&c);
	int arr[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int z=0,nz=0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(arr[i][j]!=0){
				nz++;
			}
			else{
				z++;
			}
		}
	}
	if(nz>z){
		printf("False\n");
	}
	else{
		printf("True\n");
		int spars[nz][3],k=0;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(arr[i][j]!=0){
					spars[k][0]=i;
					spars[k][1]=j;
					spars[k][2]=arr[i][j];
					k++;
				}
			}
		}
		for(i=0;i<nz;i++){
			for(j=0;j<3;j++){
				if(j<2){
					printf("%d ",spars[i][j]);
				}
				else{
					printf("%d\n",spars[i][j]);
				}
			}
		}
	}
	return 0;
}