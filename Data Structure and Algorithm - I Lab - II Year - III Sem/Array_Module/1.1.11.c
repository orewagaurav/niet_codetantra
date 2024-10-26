// Given a list of N numbers a1, a2, a3........an. Find The Position of number x in the given list using binary search.



// Note:

// The default position of first element is 0, and find the element's position in the sorted order of occurrence. Print -1 if not found.



// For repeated elements find the position of the last occurrence.



// Constraints:

// 0<N<1000
// 0<element of array <100
// 0<x<100

// Input Format:

// The first line takes the input value of N.

// The second line takes input N space-separated integer values.

// The third line takes the input value of x which needs to be searched.



// Output Format:

// Output is an integer that represents the position of x in the given list. Otherwise print -1


// Test case 1
// 5	
// 1 5 8 7 4	
// 8	
// 2	
// Test case 2
// 5	
// 12 85 97 45 2	
// 145	
// -1


#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n],i,j,x,ni,pos;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&x);
	i=0,j=n-1;
	int flag=0;
	while(i<=j){
		int mid =(i+j)/2;
		if(arr[mid]==x){
			ni=mid;
			flag=1;
			// pos = mid+1;
			break;
		}
		else if(arr[mid]>x){
			j = mid-1;
		}
		else if(arr[mid]<x){
			i=mid+1;
		}
		
	}
	if(flag ==1){
		printf("%d",ni);
	}
	else{
		printf("-1");
	}
}