#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
}*head=NULL;

void create(int value){
	struct node *ptr,*tmp;
	ptr= malloc(sizeof(struct node));
	ptr->next=NULL;
	ptr->data=value;
	if(head==NULL)
		head=ptr;
	else{
		tmp=head;
		while(tmp->next!=NULL){
			tmp =tmp->next;
		}
		tmp->next=ptr;
	}
}
//floydes cycle detection loop
int loop(int x){
	struct node *slow = head,*fast=head;
	while(fast!=NULL &&fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast||x!=0)
			return 1;
	}
	return 0;
}
int main(){
	int n,k,value;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&value);
		create(value);
	}
	scanf("%d",&k);
	int check = loop(k);
	if(check==1)
		printf("True\n");
	else
		printf("False\n");
}