#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
}*top = NULL;

void push(int value){
	struct node *ptr;
	ptr = malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next = top;
	top=ptr;
}
void display(){
	struct node* tmp;
	if(top==NULL)
	printf("stack is empty\n");
	tmp=top;
	while(tmp->next!=NULL){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("%d\n",tmp->data);
}
int main(){
	int n,value;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&value);
		push(value);
	}
	display();
}