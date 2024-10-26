// Imagine you are working on a project for a data analytics company. They have a dataset that consists of a large matrix where each cell represents a measurement taken at different times and locations. This matrix is quite large, and most of its elements are zeros, which means it is a sparse matrix



// Your task is to develop a tool that will help the company analyze this matrix efficiently.



// Matrix Input:

// Create a tool that allows the user to input the dimensions of the matrix (number of rows and columns) and then enter the elements of the matrix. Each element is an integer.


// Matrix Analysis:

// Implement functionality to determine if the matrix is sparse. A matrix is considered sparse if more than half of its elements are zeros.


// Sparse Matrix Representation:

// If the matrix is identified as sparse, convert it to its triplet form representation. The triplet form should consist of a list of tuples where each tuple represents a non-zero element in the format (row_index, column_index, value).


// Output Requirements:

// If the matrix is sparse, print its triplet representation.


// Input Format

// First Line: Two integers r and c representing the number of rows and columns of the matrix separated by a space
// Following Lines: r rows represents c elements with a new line for every 
// i
// t
// h
//  row where the elements are separated by a space


// Output Format

// Triplet Representation (if sparse): Print the triplet representation of the matrix. Each triplet should be printed on a new line in the format (row_index, column_index, value).
// if not sparse : Return -1


// Constraints

// 1 <= rows, cols <= 1000
// -10^6 <= matrix[i][j] <= 10^6 (matrix elements range between -1,000,000 and 1,000,000)
// The input matrix will be a rectangular grid (i.e., all rows have the same number of columns).

// Test case 1
// 2 2	
// 0 0	
// 0 0	
// -1	
// Test case 2
// 3 3	
// 0 1 0	
// 2 0 3	
// 0 4 0	
// 0·1·1⏎	
// 1·0·2⏎	
// 1·2·3⏎	
// 2·1·4

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
	int nm =r*c;
	int nz=0,z=0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(arr[i][j]==0){
				z++;
			}
			else{
				nz++;
			}
		}
	}
	int spp[nz][3];
	int k=0;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(arr[i][j]!=0){
					spp[k][0]=i;
					spp[k][1]=j;
					spp[k][2]=arr[i][j];
					k++;
				}
			}
		}
	if(nz==0){
		printf("-1");
	}
	else if(z>nz){
		for(int i=0;i<nz;i++){
			printf("%d %d %d\n",spp[i][0],spp[i][1],spp[i][2]);
		}
	}
	else{
		printf("-1");
	}
}