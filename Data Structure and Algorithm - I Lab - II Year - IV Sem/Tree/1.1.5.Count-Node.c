#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node *create(){
	int data;
	struct node * new;
	new=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&data);
	if(data==-1){
		return 0;
	}
	new->data=data;
	new->left=create();
	new->right=create();
	return new;
}
int count(struct node *root){
	if(root==NULL){
		return 0;
	}
	return count(root->left)+count(root->right)+1;
}
int main(){
	struct node *root;
	root =create();
	printf("%d",count(root));
}