#include <stdio.h>
#define MAX 100
int arr[MAX];
int front =-1;
int rear = -1;
void enQueue(int value){
	if((rear+1)%MAX==front)
		return;
	if(front==-1)front++;
	rear = (rear+1)%MAX;
	arr[rear]=value;
}
void deQueue(){
	if(front ==-1)
	return;
	if(front ==rear)front=rear=-1;
	else{
		front = (front+1)%MAX;
	}
}
void display(){
	if(front==-1){
		printf("Empty\n");
		return;
	}
	for(int i=front;;i=(i+1)%MAX){
		if(i!=rear)
		printf("%d ",arr[i]);
		if(i==rear){
			printf("%d\n",arr[i]);
			break;
		}
	}
}
int main(){
	int n,value,task;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&task);
		if(task==1){
			scanf("%d",&value);
			enQueue(value);
		}
		if(task==2)
		deQueue();
	}
	display();
}
