#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left,*right;
};

struct node *createNode(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

struct node *insert(struct node *root,int data){
	if(root==NULL)return createNode(data);
	if(data<root->data){
		root->left=insert(root->left,data);
	}else{
		root->right=insert(root->right,data);
	}
	return root;
}

int search(struct node *root,int target){
	if(root==NULL)return 0;
	if(target<root->data){
		return search(root->left,target);
	}else if(target>root->data){
		return search(root->right,target);
	}else{
		return 1;
	}
}

void inorder(struct node *root){
	if(root==NULL)return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int main(){
	struct node *root=NULL;
	int arr[10],length1=0,newarr[10],length2=0,option;
	do{
		scanf("%d",&option);
		if(option==1){
			int data;
			scanf("%d",&data);
			root=insert(root,data);
		}else if(option==2){
			arr[length1++]=option;
			int value;
			scanf("%d",&value);
			newarr[length2++]=value;
		}
		else if(option==3){
			arr[length1++]=option;
		}
	}while(option!=4);
	
	for(int i=0,j=0;i<length1;i++){
		if(arr[i]==2){
			printf("%d\n",search(root,newarr[j++]));
		}else{
			inorder(root);
			printf("\n");
		}
	}
	
	return 0;
}