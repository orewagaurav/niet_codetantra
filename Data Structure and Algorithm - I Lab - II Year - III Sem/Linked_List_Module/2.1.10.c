#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxArrSize 100000


int mergeTwoSLL(short list1[], int list1Len, short list2[], int list2Len, short *resultsArr) {
	int i=0,j=0,k=0;
	while (i < list1Len && j < list2Len) {
		if (list1[i] <= list2[j]) {
			resultsArr[k++] = list1[i++];
		} 
		else {
			resultsArr[k++] = list2[j++];
		}
	}
	while (i < list1Len) {
		resultsArr[k++] = list1[i++];
	}
	while (j < list2Len) {
		resultsArr[k++] = list2[j++];
	}
	return k; 
}

int readShortArray(char *argsArray, short arr[]) {
	int col = 0;
	char *token = strtok(argsArray, ",");
	while (token != NULL) {
		arr[col] = (short) atoi(token);
		token = strtok(NULL, ",");
		col++;
	}
	return col;
}
void printArrayElements(short *resultsArr, int resultsArrLength) {
	int index;
	for(index = 0; index < resultsArrLength - 1; index++) {
		printf("%d,", resultsArr[index]);
 	}
	printf("%d\n", resultsArr[index]);
}

int main(int argc, char *argv[]) {
	short list1[strlen(argv[1])];
	short list2[strlen(argv[2])];
	int list1Len = readShortArray(argv[1], list1);
	int list2Len = readShortArray(argv[2], list2);
	short resultsArr[MaxArrSize];
	int resultsArrLength = mergeTwoSLL(list1, list1Len, list2, list2Len, resultsArr);
	printArrayElements(resultsArr, resultsArrLength);
	return 0;
}