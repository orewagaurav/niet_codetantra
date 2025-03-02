#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

struct node *create(int data){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;   
}
struct node *insert(struct node *root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data>root->data){
        root->right=insert(root->right,data);
    }
    else if(data<root->data){
        root->left=insert(root->left,data);
    }
    return root;

}

int main(){
    int n;
    struct node *root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        root=insert(root,data);
    }
    inOrder(root);
}
