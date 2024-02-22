/**
 * @file Tree_traversal.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/*Aim : Write the code to implement the tree traversal (inorder, preorder,and postorder)*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
void insert(struct TreeNode** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

// Preorder traversal: Root, Left, Right
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data); // Print the root node
    preorderTraversal(root->left); // Traverse left subtree
    preorderTraversal(root->right); // Traverse right subtree
}

// Inorder traversal: Left, Root, Right
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left); // Traverse left subtree
    printf("%d ", root->data); // Print the root node
    inorderTraversal(root->right); // Traverse right subtree
}

// Postorder traversal: Left, Right, Root
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left); // Traverse left subtree
    postorderTraversal(root->right); // Traverse right subtree
    printf("%d ", root->data); // Print the root node
}

int main() {
    struct TreeNode* root = NULL;
    int numNodes;
    int data;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);

    printf("Enter the values of each node:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        insert(&root, data);
    }

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
