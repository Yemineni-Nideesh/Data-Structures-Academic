#include<stdio.h>
#include<stdlib.h>

struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
};

struct BSTnode *createNode(int val)
{
    struct BSTnode *newNode = malloc(sizeof(struct BSTnode));
    newNode->data   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct BSTnode *insert(struct BSTnode *root, int val)
{
    if(root == NULL)
        return createNode(val);
    if(root->data < val)
        root->right = insert(root->right,val);
    else if(root->data > val)
        root->left = insert(root->left,val);

    return root;
}

int getRightMin(struct BSTnode *root)
{
    struct BSTnode *temp = root;

    //min value should be present in the left most BSTnode.
    while(temp->left != NULL){ temp = temp->left;}

    return temp->data;
}

int k=0;

void elementsInRange(struct BSTnode *root, int M, int N){
    if(root==NULL) return ;
    if(root->data >M ){
    elementsInRange(root->left,M,N);
    }
    if(root->data >=M && root->data <=N){
        k=1;
        printf("%d ",root->data);
    }
    if(root->data <N){
    elementsInRange(root->right,M,N);
    }
}

int main()
{
    struct BSTnode *root = NULL;
    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Enter atleast one node, try again");
        return 0;
    }
    printf("Enter the data for nodes: ");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root = insert(root,x);
    }
    int M,N;
    printf("M: ");
    scanf("%d",&M);
    printf("N: ");
    scanf("%d",&N);
    if(M>N){
        printf("M should be smaller than N");
        return 0;
    }
    k=0;
    elementsInRange(root ,M,N);
    if(k==0){
        printf("No elements found in this range\n");
    }

    return 0;
}