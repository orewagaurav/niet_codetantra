#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    TreeNode *root;
    char **operations;
    int operation_count;
    int operation_capacity;
} BinaryTree;

TreeNode *create_node(int value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void init_binary_tree(BinaryTree *tree) {
    tree->root = NULL;
    tree->operation_count = 0;
    tree->operation_capacity = 10;
    tree->operations = (char **)malloc(tree->operation_capacity * sizeof(char *));
}

void add_operation(BinaryTree *tree, const char *operation) {
    if (tree->operation_count >= tree->operation_capacity) {
        tree->operation_capacity *= 2;
        tree->operations = (char **)realloc(tree->operations, tree->operation_capacity * sizeof(char *));
    }
    tree->operations[tree->operation_count] = strdup(operation);
    tree->operation_count++;
}

void insert(BinaryTree *tree, int value) {
    if (value == -1) {
        return;
    }

    TreeNode *new_node = create_node(value);
    if (!tree->root) {
        tree->root = new_node;
        return;
    }

    TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = tree->root;

    while (front < rear) {
        TreeNode *node = queue[front++];

        if (!node->left) {
            node->left = new_node;
            return;
        } else {
            queue[rear++] = node->left;
        }

        if (!node->right) {
            node->right = new_node;
            return;
        } else {
            queue[rear++] = node->right;
        }
    }
}

void in_order(TreeNode *node, char *result) {
    if (node) {
        in_order(node->left, result);
        char temp[20];
        sprintf(temp, "%d ", node->value);
        strcat(result, temp);
        in_order(node->right, result);
    }
}

void pre_order(TreeNode *node, char *result) {
    if (node) {
        char temp[20];
        sprintf(temp, "%d ", node->value);
        strcat(result, temp);
        pre_order(node->left, result);
        pre_order(node->right, result);
    }
}

void post_order(TreeNode *node, char *result) {
    if (node) {
        post_order(node->left, result);
        post_order(node->right, result);
        char temp[20];
        sprintf(temp, "%d ", node->value);
        strcat(result, temp);
    }
}

int search(TreeNode *node, int value) {
    if (!node) {
        return 0;
    }
    if (node->value == value) {
        return 1;
    }
    return search(node->left, value) || search(node->right, value);
}

void process_traversal(BinaryTree *tree, const char *order_type) {
    if (!tree->root) {
        add_operation(tree, "-1");
    } else {
        char result[1000] = "";
        if (strcmp(order_type, "in_order") == 0) {
            in_order(tree->root, result);
        } else if (strcmp(order_type, "pre_order") == 0) {
            pre_order(tree->root, result);
        } else if (strcmp(order_type, "post_order") == 0) {
            post_order(tree->root, result);
        }
        add_operation(tree, result);
    }
}

void process_search(BinaryTree *tree, int value) {
    if (search(tree->root, value)) {
        add_operation(tree, "found");
    } else {
        add_operation(tree, "not found");
    }
}

void print_operations(BinaryTree *tree) {
    for (int i = 0; i < tree->operation_count; i++) {
        printf("%s\n", tree->operations[i]);
        free(tree->operations[i]);
    }
    free(tree->operations);
}

void free_tree(TreeNode *node) {
    if (node) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

int main() {
    BinaryTree tree;
    init_binary_tree(&tree);

    char command[100];
    while (fgets(command, sizeof(command), stdin)) {
        if (command[0] == '\n') {
            continue;
        }

        int cmd, value;
        if (sscanf(command, "%d %d", &cmd, &value) == 2) {
            if (cmd == 1) {
                insert(&tree, value);
            } else if (cmd == 5) {
                process_search(&tree, value);
            }
        } else if (sscanf(command, "%d", &cmd) == 1) {
            if (cmd == 2) {
                process_traversal(&tree, "in_order");
            } else if (cmd == 3) {
                process_traversal(&tree, "pre_order");
            } else if (cmd == 4) {
                process_traversal(&tree, "post_order");
            } else if (cmd == 6) {
                break;
            }
        }
    }

    print_operations(&tree);
    free_tree(tree.root);

    return 0;
}