#include <stdio.h>
#include <stdbool.h>
#define max 100
int arr[max];
int b=-1;
int f=-1;
bool isempty(){
	if(b!=max-1)
		return true;
	else
		return false;
}
void enqueue(int value){
	bool check = isempty();
	if(check== true){
		b++;
		arr[b]=value;
	}
	else
		return;
}
void dequeue(){
	if(b!=f){
		f++;
	}
	else
		return;
}
void display(){
	if(f==b){
		printf("Empty\n");
	}
	else{
		for(int i =f+1;i<=b;i++){
			if(i<b)
			printf("%d ",arr[i]);
			else
				printf("%d\n",arr[i]);
		}
	}
}
int main(){
	int n,value,task;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&task);
		if(task==1){
			scanf("%d",&value);
			enqueue(value);
		}
		else if(task==2){
			dequeue();
		}
	}
	display();
}