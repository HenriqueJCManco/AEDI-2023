#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* insert(TreeNode *root, int value) {
    if (!root) {
        root = (TreeNode *) malloc(sizeof(TreeNode));
        root->data = value;
        root->left = root->right = NULL;
    } else if (root->data > value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

void preorderTraversal(TreeNode *root) {
    if (root) {
        printf(" %d", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode *root) {
    if (root) {
        inorderTraversal(root->left);
        printf(" %d", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode *root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf(" %d", root->data);
    }
}

void clearTree(TreeNode *root) {
    if (root) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
        root = NULL;
    }
}

int main() {
    int value, numCases, numNodes, caseNum = 0;
    
    scanf("%d", &numCases);
    
    while (numCases--) {
        TreeNode *root = NULL;
        scanf("%d", &numNodes);
        
        for (int i = 0; i < numNodes; i++) {
            scanf("%d", &value);
            root = insert(root, value);
        }
        
        printf("Case %d:\n", ++caseNum);
        printf("Pre.:");
        preorderTraversal(root);
        printf("\n");
        printf("In..:");
        inorderTraversal(root);
        printf("\n");
        printf("Post:");
        postorderTraversal(root);
        printf("\n\n");
        
        clearTree(root);
    }
    
    return 0;
}
