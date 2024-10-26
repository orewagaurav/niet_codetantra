#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
struct node *pre;
}*head= NULL;

void insert(int value){
	struct node *ptr,*tmp;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->next =NULL;
	ptr->pre=NULL;
	ptr->data =value;
	if(head ==NULL)
	head =ptr;
	else{
		tmp =head;
		while(tmp->next !=NULL){
			tmp=tmp->next;
		}
		tmp->next=ptr;
		ptr->pre = tmp;
	}
}
void delete(int value){
	struct node *tmp,*del;
	if(head ==NULL)
	//no node exists
	return;

	//first node delete case 
	tmp = head;
	if(tmp->data == value){
		head = tmp->next;
		if(head !=NULL)
		head->pre=NULL;//q ki ye abb first node hogya to es se phle abb kuch nai hoga
		free(tmp);
		return;
	}
	while(tmp->next!=NULL && tmp->next->data != value){
		tmp = tmp->next;
	}
	if(tmp->next == NULL)
	//entered value does not exists
	return;

	del = tmp->next;//jo node ko delete krna hai wo del hai
	tmp->next=del->next;//tmp del se ek phle wla node hai
	if(del->next!=NULL)
	del->next->pre=tmp;
	free(del);
}
void traverse(){
	struct node *tmp;
	tmp =head;
	if(head==NULL)
	return;
	else{
		while(tmp != NULL){
			printf("%d ",tmp->data);
			tmp=tmp->next;
		}
		printf("\n");
	}
}

int main(){
	int n,task,value;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&task,&value);
		if(task ==1)
		insert(value);
		else if(task == 2)
		delete(value);
	}
	traverse();
	return 0;
}