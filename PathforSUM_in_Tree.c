#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int hasPathSum(Node* root, int SUM) {
    if (root == NULL) return 0;
    if (SUM == root->data && root->left == NULL && root->right == NULL) return 1;
    int rem = SUM - root->data;
    return hasPathSum(root->left, rem) || hasPathSum(root->right, rem);
}

int pathForSum(Node* root, int SUM) {
    if (root == NULL) return 0;

    if (hasPathSum(root, SUM)) {
        printf("%d ", root->data);
        int rem = SUM - root->data;
        if (hasPathSum(root->left, rem)) {
            pathForSum(root->left, rem);
        } else if (hasPathSum(root->right, rem)) {
            pathForSum(root->right, rem);
        }
        return 1;
    }
    return 0;
}

int main() {
    Node* root = createNode(33);
    root->left = createNode(9);
    root->right = createNode(19); 
    root->left->left = createNode(5);
    root->left->right = createNode(7);
    root->right->left = createNode(23);
    root->right->right = createNode(4);
    root->left->left->left = createNode(1);
    root->left->left->right = createNode(12);
    root->left->right->right = createNode(6);
    root->right->left->right = createNode(8);
    root->right->right->right = createNode(9);

    int SUM;
    printf("Enter SUM: ");
    if (scanf("%d", &SUM) != 1) return 1;

    int found = pathForSum(root, SUM);
    if (!found) {
        printf("No path found");
    }
    printf("\n");

    return 0;
}
