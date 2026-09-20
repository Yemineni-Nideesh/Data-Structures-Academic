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

void inorder(struct BSTnode *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


int search(struct BSTnode *root,int key){
    if(root==NULL) return 0;
    if(key==root->data) return 1;
    else if(key<(root->data)) return search(root->left,key);
    else if(key>(root->data)) return search(root->right,key);
    else return 0;

}
int c=0;
void findAllPairs(struct BSTnode *root,struct BSTnode *x, int SUM){
    if(x==NULL) return;
    int S=SUM;
    int complement=S-(x->data);
    if(x->data < complement){
        if(search(root,complement)){
            printf(" %d-%d ",x->data,complement);
            c=1;
        }
    }
    findAllPairs(root,x->left,S);
    findAllPairs(root,x->right,S);
}

int main()
{
    struct BSTnode *root = NULL;
    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    printf("Enter the data for nodes: ");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root = insert(root,x);
    }
    int SUM;
    printf("Enter SUM: ");
    scanf("%d",&SUM);
    printf("Pairs: ");
    findAllPairs(root , root, SUM);
    if(!c){
        printf("There are no such pairs in your tree which add up to your specific SUM, sorry :(");
        return 0;
    }
    printf("\nOVER!\n");
    return 0;
}