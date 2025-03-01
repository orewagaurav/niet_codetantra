#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data, char side) {
    if (root == NULL) return createNode(data);

    struct node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node *temp = queue[front++];
        if (side == 'L') {
            if (temp->left == NULL) {
                temp->left = createNode(data);
                return root;
            } else {
                queue[rear++] = temp->left;
            }
        } else if (side == 'R') {
            if (temp->right == NULL) {
                temp->right = createNode(data);
                return root;
            } else {
                queue[rear++] = temp->right;
            }
        }
    }
    return root;
}

int checkBalanced(struct node *root, int *height) {
    if (root == NULL) {
        *height = 0;
        return 1;
    }

    int leftHeight = 0, rightHeight = 0;
    int isLeftBalanced = checkBalanced(root->left, &leftHeight);
    int isRightBalanced = checkBalanced(root->right, &rightHeight);

    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    if (abs(leftHeight - rightHeight) > 1) return 0;
    return isLeftBalanced && isRightBalanced;
}

int main() {
    int n, rootValue;
    scanf("%d %d", &n, &rootValue);

    struct node *root = createNode(rootValue);
    for (int i = 1; i < n; i++) {
        int data;
        char side;
        scanf("%d %c", &data, &side);
        root = insert(root, data, side);
    }

    int height = 0;
    printf(checkBalanced(root, &height) ? "Balanced" : "Not balanced");

    return 0;
}