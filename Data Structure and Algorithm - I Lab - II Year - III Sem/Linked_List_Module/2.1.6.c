#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
void create(struct node** head,int value){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next =NULL;
	struct node *tmp;
	if(*head==NULL){
		*head=ptr;
	}
	else{
		tmp=*head;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=ptr;
	}
}
struct node* reverse(struct node* head){
	struct node *curr = head,*nxt=head,*pre = NULL;
	while(nxt!=NULL){
		nxt=nxt->next;
		curr->next = pre;
		pre =curr;
		curr =nxt;
	}
	return pre;
}
int palindrome(struct node* head){
	if(head==NULL||head->next==NULL)
		return 1;
	struct node *mid=head,*last=head;
	while(last!=NULL && last->next!=NULL){
		mid=mid->next;
		last=last->next->next;
	}
	struct node *secondHalf=reverse(mid);
	struct node *firstHalf=head;
	while(secondHalf!=NULL){
		if(firstHalf->data!=secondHalf->data){
			return 0;
		}
		firstHalf=firstHalf->next;
		secondHalf=secondHalf->next;
	}
	return 1;
}
int main (){
	int n,value;
	scanf("%d",&n);
	struct node **head = (struct node **)malloc(n*sizeof(struct node*));
	for(int i=0;i<n;i++){
		head[i]=NULL;
	}
	for(int i=0;i<n;i++){
		while(1){
			scanf("%d",&value);
			if(value==-1)
			break;
			create(&head[i],value);
		}
	}
	for(int i =0;i<n;i++){
		int check = palindrome(head[i]);
		if(check==1)
			printf("true\n");
		else
			printf("false\n");
	}
}