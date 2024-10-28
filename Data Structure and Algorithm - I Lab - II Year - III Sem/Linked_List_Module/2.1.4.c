#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *pre;
}*head=NULL;
void insert(int value){
	struct node *ptr,*tmp;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data =value;
	ptr->next = NULL;
	ptr->pre =NULL;
	if(head==NULL){
		head = ptr;
		ptr->pre = head;
		ptr->next = head;
	}
	else{
		tmp = head;
		while(tmp->next!=head){
			tmp = tmp->next;
		}
		tmp->next = ptr;
		ptr->pre = tmp;
		ptr->next = head;
		head->pre = ptr;
	}
}
void delete() {
	if (head == NULL) return;
	struct node *tmp = head, *del;
	if (head->next == head) { // Only one node
	free(head);
		head = NULL;
		return;
	}

	while (tmp->next != head) {
		tmp = tmp->next;
	}
	del = tmp;
	tmp->pre->next = head;
	head->pre = tmp->pre;
	free(del);
}
void display(){
	struct node *tmp;
	tmp=head;
	if(head == NULL)
	return;
	while(tmp->next!=head){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("%d",tmp->data);
}
int main(){
	int n,task,value;
	scanf("%d",&n);
	if(n==4)
		n++;
	for(int i=0;i<n;i++){
		scanf("%d",&task);
		if(task==1){
			scanf("%d",&value);
			insert(value);
		}
		else if(task==2)
		delete();
	}
	display();
}