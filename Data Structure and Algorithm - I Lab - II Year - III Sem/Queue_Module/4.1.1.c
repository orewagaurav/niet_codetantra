#include <stdio.h>
#include <stdbool.h>
#define MAX 1000
int arr[MAX];
int backInd = -1;
int frontInd = -1;
bool isEmpty(){
	if(backInd!=MAX-1)
		return true;
	else
		return false;
}
void enQueue(int value){
	bool check = isEmpty();
	if(check==true){
		backInd++;
		arr[backInd]=value;
	}
	else
		return;
}
void deQueue(){
	if(backInd!=frontInd){
		frontInd++;
	}
	else
		return;
}
void display(){
	if(frontInd==backInd){
		printf("Empty\n");
	}
	else{
		for(int i= frontInd+1;i<=backInd;i++){
			if(i<backInd)
			printf("%d ",arr[i]);
			else
			printf("%d\n",arr[i]);
		}
	}
}
int main(){
	int n,value,task;
	scanf("%d",&n);
	for(int i= 0;i<n;i++){
		scanf("%d",&task);
		if(task==1){
			scanf("%d",&value);
			enQueue(value);
		}
		else if(task==2){
			deQueue();
		}
	}
	display();
}