//write a program to find out bst from inorder and preorder.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

struct node* buildTreeFromPreorderAndInorder(int preorder[], int inorder[], int* preorderIndex, int inorderStart, int inorderEnd, int n) {
    if (*preorderIndex >= n || inorderStart > inorderEnd) {
        return NULL;
    }

    int rootValue = preorder[*preorderIndex];
    (*preorderIndex)++;

    struct node* rootNode = createNode(rootValue);

    if (inorderStart == inorderEnd) {
        return rootNode;
    }

    int rootIndexInInorder = findIndex(inorder, inorderStart, inorderEnd, rootValue);

    rootNode->left = buildTreeFromPreorderAndInorder(preorder, inorder, preorderIndex, inorderStart, rootIndexInInorder - 1, n);
    rootNode->right = buildTreeFromPreorderAndInorder(preorder, inorder, preorderIndex, rootIndexInInorder + 1, inorderEnd, n);

    return rootNode;
}

void inorderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter the preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter the inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preorderIndex = 0;
    struct node* root = buildTreeFromPreorderAndInorder(preorder, inorder, &preorderIndex, 0, n - 1, n);

    printf("\nInorder traversal of the constructed BST:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
