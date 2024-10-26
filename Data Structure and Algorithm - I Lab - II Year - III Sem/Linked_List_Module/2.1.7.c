#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *pre;
}*head =NULL;

void insert(int value){
	struct node *ptr,*tmp;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->next = NULL;
	ptr->data = value;
	ptr->pre = NULL;
	if(head == NULL)
	head = ptr;
	else{
		tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = ptr;
		ptr->pre = tmp;	
	}
}
void display(){
	struct node *tmp,*rev;
	tmp =head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	rev=tmp;
	while(rev != NULL){
		printf("%d ",rev->data);
		rev=rev->pre;
	}
	printf("\n");
}
int main(){
	int n,value;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&value);
		insert(value);
	}
	display();
	return 0;
}