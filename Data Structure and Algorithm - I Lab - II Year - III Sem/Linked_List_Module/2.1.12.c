#include <stdio.h>
#include <stdlib.h>
struct node {
	int coef;
	int exp;
	struct node *next;
};
struct node* create(int coef,int exp){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->next=NULL;
	ptr->coef = coef;
	ptr->exp=exp;
	return ptr;
}
void insert(struct node **poly,int coef,int exp){
	struct node* ptr = create(coef,exp);
	if(*poly==NULL || (*poly)->exp<exp){
		ptr->next = *poly;
		*poly = ptr;
	}
	else{
		struct node *tmp = *poly;
		while(tmp->next!=NULL&&tmp->next->exp>=exp){
			tmp=tmp->next;
		}
		ptr->next = tmp->next;
		tmp->next=ptr;
	}
}
void display(struct node* poly){
	struct node *tmp = poly;
	while(tmp!=NULL){
		printf("%dx^%d",tmp->coef,tmp->exp);
		tmp=tmp->next;
		if(tmp!=NULL)
		printf(" + ");
	}
	printf("\n");
}
struct node* add(struct node *poly1,struct node *poly2){
	struct node* result=NULL;
	while(poly1!=NULL&&poly2!=NULL){
		if(poly1->exp>poly2->exp){
			insert(&result,poly1->coef,poly1->exp);
			poly1=poly1->next;
		}
		else if(poly1->exp<poly2->exp){
			insert(&result,poly2->coef,poly2->exp);
			poly2=poly2->next;
		}
		else{
			int sum = poly1->coef+poly2->coef;
			if(sum!=0){
				insert(&result,sum,poly1->exp);
			}
			poly1=poly1->next;
			poly2=poly2->next;
		}
	}
	while(poly1!=NULL){
		insert(&result,poly1->coef,poly1->exp);
		poly1=poly1->next;
	}
	while(poly2!=NULL){
		insert(&result,poly2->coef,poly2->exp);
	}
	return result;
}
int main(){
	int num1,num2;
	struct node *poly1=NULL;
	struct node *poly2 =NULL;
	scanf("%d",&num1);
	int coef,exp;
	for(int i=0;i<num1;i++){
		scanf("%d %d",&coef,&exp);
		insert(&poly1,coef,exp);
	}
	scanf("%d",&num2);
	for(int i= 0;i<num2;i++){
		scanf("%d %d",&coef,&exp);
		insert(&poly2,coef,exp);
	}
	display(poly1);
	display(poly2);
	struct node* result =add(poly1,poly2);
	display(result);
}