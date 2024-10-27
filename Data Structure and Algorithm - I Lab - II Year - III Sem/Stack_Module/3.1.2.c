#include <stdio.h>
#include <stdlib.h>
int peekval =0;
struct stack{
	int data;
	struct stack *next;
}*top =NULL;

void push (int value){
	struct stack *ptr=malloc(sizeof(struct stack));
	ptr->data=value;
	ptr->next = top;
	top =ptr;
}
void pop(){
	if(top==NULL)
		return;
	struct stack *tmp=top;
	top = top->next;
	free(tmp);
}
void peek(){
	if(top==NULL){
		return;
	}
	peekval=top->data;
}

void display(){
	struct stack *tmp=top;
	if(top==NULL){
		printf("Empty\n");
	}
	else{
		while(tmp->next!=NULL){
			printf("%d->",tmp->data);
			tmp=tmp->next;
		}
		printf("%d\n",tmp->data);
	}
}
int main(){
	int n,task,value,flag=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&task);
		if(task==1){
			scanf("%d",&value);
			push(value);
		}
		else if(task==2)
		pop();
		else if(task==3)
		if(top!=NULL){
		peek();
		flag++;
		}
	}
	if(flag>0){
	printf("%d\n",peekval);
	}
	display();
}