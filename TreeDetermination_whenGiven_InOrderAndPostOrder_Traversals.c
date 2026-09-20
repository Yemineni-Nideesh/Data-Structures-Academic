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

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

Node* buildTreeUtil(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    int currValue = postorder[*postIndex];
    Node* currNode = createNode(currValue);
    (*postIndex)--;

    if (inStart == inEnd) {
        return currNode;
    }

    int inIndex = search(inorder, inStart, inEnd, currValue);

    currNode->right = buildTreeUtil(inorder, postorder, inIndex + 1, inEnd, postIndex);
    currNode->left = buildTreeUtil(inorder, postorder, inStart, inIndex - 1, postIndex);

    return currNode;
}

Node* buildTree(int inorder[], int postorder[], int size) {
    int postIndex = size - 1;
    return buildTreeUtil(inorder, postorder, 0, size - 1, &postIndex);
}

void printPreorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    int size ;
    printf("Number of elements: ");
    if (scanf("%d",&size) != 1) return 1;
    int *arrInorder = malloc(size * sizeof(int));
    int *arrPostorder = malloc(size * sizeof(int));

    if (arrInorder == NULL || arrPostorder== NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Inorder Traversal: ");
    for(int i=0;i<size;i++){
        if (scanf("%d",&arrInorder[i]) != 1) return 1;
    }
    printf("Postorder Traversal: ");
    for(int j=0;j<size;j++){
        if (scanf("%d",&arrPostorder[j]) != 1) return 1;
    }

    Node* root = buildTree(arrInorder, arrPostorder, size);

    printf("Preorder Traversal: ");
    printPreorder(root);
    printf("\n");

    freeTree(root);
    free(arrInorder);free(arrPostorder);
    arrInorder = NULL; arrPostorder= NULL;
    return 0;
}
