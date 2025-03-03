#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	int height;
	struct node *left,*right;
};

struct node *createNode(int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->height=1;
	newnode->left=newnode->right=NULL;
	return newnode;
}

int getMax(int a,int b){
	return a>b ? a:b;
}

int getHeight(struct node *root){
	if(root==NULL)return 0;
	return root->height;
}

struct node *insert(struct node *root,int data){
	if(root==NULL)return createNode(data);
	if(data<root->data){
		root->left=insert(root->left,data);
	}else{
		root->right=insert(root->right,data);
	}
	root->height=1+getMax(getHeight(root->left),getHeight(root->right));
	return root;
}

void preorder(struct node *root){
	if(!root)return;
	printf("%d %d\n",root->data,getHeight(root->left)-getHeight(root->right));
	preorder(root->left);
	preorder(root->right);
}

int main(){
	struct node *root=NULL;
	int option;
	while(1){
		scanf("%d",&option);
		if(option==1){
			int data;
			scanf("%d",&data);
			root=insert(root,data);
		}else{
			break;
		}
	}
	if(option==2){
		if(root){
			preorder(root);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
