#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int data;
	struct node *next;
}*head = NULL;

char * midPoint(int N, char *Arr[], int ArrLen) {
	// Write code here
	int a=ArrLen/2;
	if(ArrLen%2==0){
		return Arr[ArrLen/2-1];
	}
	return Arr[ArrLen/2];

}

int readStringArray(char *argsArray, char *arr[]) {
	int col = 0;
	char *token = strtok(argsArray, ",");
	while (token != NULL) {
		arr[col] = token;
		token = strtok(NULL, ",");
		col++;
	}
	return col;
}
int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	char *Arr[strlen(argv[2])];
	int ArrLen = readStringArray(argv[2], Arr);
	printf("%s\n", midPoint(N, Arr, ArrLen));
	return 0;
}