#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform preorder traversal of the BST
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, data;

    // Input the number of nodes in the BST
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);

    // Input the values of the nodes
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    // Perform preorder traversal and print the result
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
