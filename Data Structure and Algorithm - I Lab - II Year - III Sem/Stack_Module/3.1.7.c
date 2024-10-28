#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxArrSize 100000


int fibonacciNumbers(int N, int *resultsArr) {
	if(N<0) 
		return 0;
	int count =0;
	resultsArr[count++]=0;
	if(N>=1){
		resultsArr[count++]=1;
	}
	while(1){
		int next =resultsArr[count-1]+resultsArr[count-2];
		if(next>N) break;
		resultsArr[count++]=next;
	}
	return count;
}

void printArrayElements(int *resultsArr, int resultsArrLength) {
	int index;
	for(index = 0; index < resultsArrLength - 1; index++) {
		printf("%d,", resultsArr[index]);
 	}
	printf("%d\n", resultsArr[index]);
}

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	int resultsArr[MaxArrSize];
	int resultsArrLength = fibonacciNumbers(N, resultsArr);
	printArrayElements(resultsArr, resultsArrLength);
	return 0;
}