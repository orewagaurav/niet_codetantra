#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
}*head =NULL;

void insert(int value){
	struct node *ptr,*tmp;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->next =NULL;
	ptr->data=value;
	if(head ==NULL){
		head =ptr;
		head->next=head;
	}
	else{
		tmp = head;
		while(tmp->next!=head){
			tmp = tmp->next;
		}
		tmp->next=ptr;
		ptr->next=head;
	}
}

void delete(int value) {
	if (head == NULL) {
		return;
	}
	struct node *tmp = head, *prev = NULL;
	if (head->data == value) {
		while (tmp->next != head) { 
			tmp = tmp->next;
		}
		if (head->next == head) {
			head = NULL;
		} else {
			tmp->next = head->next;
			free(head);
			head = tmp->next;
		}
		return;
	}
	prev = head;
	tmp = head->next;
	while (tmp != head && tmp->data != value) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == head) {
		return;
	}
	prev->next = tmp->next;
	free(tmp);
}
void display(){
	struct node *tmp;
	if(head==NULL)
	return;
	tmp = head;
	while(1){
		printf("%d ",tmp->data);
		tmp = tmp->next;
		if(tmp==head)
		break;
	}
	printf("\n");
}
int main(){
	int n,value,task;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d %d",&task,&value);
		if(task==1)
		insert(value);
		else if(task==2)
		delete(value);
	}
	display();
}