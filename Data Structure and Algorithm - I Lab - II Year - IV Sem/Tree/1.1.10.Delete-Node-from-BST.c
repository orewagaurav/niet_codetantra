#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *create(int data){
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}

void inOrder(struct node *root){
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

struct node *insert(struct node *root,int data){
	if(root==NULL){
		return create(data);
	}
	if(root->data>data){
		root->left=insert(root->left,data);
	}
	else if(root->data<data){
		root->right=insert(root->right,data);
	}
	return root;
}
struct node *minValue(struct node *root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

struct node *delete(struct node *root,int key){
	if(root==NULL){
		return root;
	}
	if(key<root->data){
		root->left=delete(root->left,key);
	}
	else if(key>root->data){
		root->right=delete(root->right,key);
	}
	else{
		if(root->left==NULL){
			struct node *tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL){
			struct node *tmp=root->left;
			free(root);
			return tmp;
		}
		struct node *tmp;
		tmp=minValue(root->right);
		root->data=tmp->data;
		root->right=delete(root->right,tmp->data);
	}
	return root;
}

int main(){
	struct node *root=NULL;
	int n,key;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		root=insert(root,data);
	}
	scanf("%d",&key);
	delete(root,key);
	inOrder(root);
}
