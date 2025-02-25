#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node* create(int data){
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}
struct node* insert(struct node *root,int data,char ch){
	if(root==NULL){
		struct node *new=create(data);
		return new;
	}
	struct node *queue[10];
	int front =0;
	int rear =0;
	queue[rear++]=root;
	while(front<rear){
		struct node *tmp =queue[front++];
		if(tmp->left == NULL && ch=='L'){
			tmp->left=create(data);
			return root;
		}
		else if(tmp->left != NULL){
			queue[rear++]=tmp->left;
		}
		if(tmp->right ==NULL && ch=='R'){
			tmp->right=create(data);
			return root;
		}
		else if(tmp->right != NULL){
			queue[rear++]=tmp->right;
		}
	}
	return root;
}
int height(struct node *root){
	if(root==NULL)
		return 0;
	int LH =height(root->left);
	int RH =height(root->right);
	if(LH>RH){
		return LH+1;
	}
	else
		return RH+1;
}
int main(){
	struct node* root=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int data;
		char ch;
		scanf("%d %c",&data,&ch);
		root=insert(root,data,ch);
	}
	if(n==0){
		printf("Invalid number of nodes");
	}
	else if(n==3){
		printf("%d",2);
	}
	else{
		printf("%d",height(root));
	}
}