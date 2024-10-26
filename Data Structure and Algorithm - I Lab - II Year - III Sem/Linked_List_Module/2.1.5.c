#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL;
void insert(int value){
	struct node *ptr,*tmp;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next =NULL;
	if(head==NULL)
	head=ptr;
	else{
		tmp= head;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=ptr;
	}
}
void reverse(){
	struct node *pre,*curr,*nxt;
	pre =NULL;
	curr=head;
	nxt=head;
	while(nxt!=NULL){
		nxt=nxt->next;
		curr->next = pre;
		pre = curr;
		curr = nxt;
	}
	head=pre;
}
void display(){
	struct node *tmp;
	tmp = head;
	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}
int main (){
	int n,value;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&value);
		insert(value);
	}
	reverse();
	display();
}