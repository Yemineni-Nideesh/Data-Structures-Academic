#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct treeNode{
	int data;
	struct treeNode *firstChild;
	struct treeNode *nextSibling;
};
struct treeNode* createNode(int value) {
	struct treeNode* newNode = malloc(sizeof(struct treeNode));
	newNode->data = value;
	newNode->firstChild = NULL;
	newNode->nextSibling= NULL;
	return newNode;
}


int fun(struct treeNode* node){
        if(node->firstChild==NULL && node->nextSibling==NULL){
        printf("No Children\n");
        }
	int sum=0;
	node=node->firstChild;
	while (node){
		sum=sum+node->data;
		node=node->nextSibling;
	}
	return sum;
}

int sumofChildren(struct treeNode* root,int data){
        
	if (root== NULL) return 0;
	if (root->data==data){
		return fun(root);
	}
	int j=sumofChildren(root->firstChild,data);
	int k=sumofChildren(root->nextSibling,data);
	if(j){
	return j;
	}
	else if(k){
	return k;
	}
	else {
	return INT_MIN;
	
	}
}

int main(){
	struct treeNode* root=NULL;
	root=createNode(33);
	root->firstChild=createNode(9);
	root->firstChild->nextSibling= createNode(7);
	root->firstChild->nextSibling->nextSibling=createNode(19);
	root->firstChild->firstChild=createNode(5);
	root->firstChild->firstChild->nextSibling=createNode(12);
	root->firstChild->firstChild->nextSibling->nextSibling=createNode(17);
	root->firstChild->nextSibling->nextSibling->firstChild=createNode(2);
	root->firstChild->nextSibling->nextSibling->firstChild->nextSibling=createNode(4);
	int data;
	scanf("%d",&data);
	int i=sumofChildren(root,data);
	if(i==INT_MIN){
	           printf("Not Found\n");
	           return 0;
	}
	printf("Sum of children of Node %d: %d\n",data,i);
        return 0;
}
















