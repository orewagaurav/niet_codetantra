#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL;
void insert(int value){
	struct node *ptr,*tmp;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next = NULL;
	if(head==NULL)
	head =ptr;
	else{
		tmp = head;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		tmp ->next=ptr;
	}
}
void mid(int n){
	struct node *tmp;
	tmp=head;
	for(int i=1;i<=n/2;i++){
		tmp=tmp->next;
	}
	printf("%d",tmp->data);
	
}
int main(){
	int n,value;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&value);
		insert(value);
	}
	mid(n);
}