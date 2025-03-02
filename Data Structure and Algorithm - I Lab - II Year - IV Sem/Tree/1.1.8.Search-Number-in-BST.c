#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

int search(struct node *root,int key){
    while(root!=NULL){
        if(key==root->data){
            return 1;
        }
        if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return 0;
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
    int n,key;
    struct node *root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        root=insert(root,data);
    }
    scanf("%d",&key);
    if(search(root,key)){
        printf("Found");
    }
    else{
        printf("Not found");
    }
}
