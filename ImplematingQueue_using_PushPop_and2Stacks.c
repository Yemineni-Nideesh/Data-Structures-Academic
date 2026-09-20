#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};


void push(struct node **head, int val)
{
    //create new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    //make the new node points to the head node
    newNode->next = *head;

    //make the new node as head nodevso that head will always point the last inserted data
    *head = newNode;
}

int pop(struct node **head)
{
    //temp is used to free the head node
    struct node *temp;
    int data;

    if(*head == NULL){
        printf("Stack is Empty\n");
	return INT_MIN;
    }
    else
    {
        data= (*head) -> data;

        //backup the head node
        temp = *head;

        //make the head node points to the next node.
        *head = (*head) -> next;

        //free the poped element's memory
        free(temp);
	return data;
    }
}


//Print the stack
int printStack(struct node* node){
    int count=0;
    if(node==NULL){
        printf("Empty !");
        return 0;
    }
    while(node!=NULL){
        printf("%d ",node->data);
        count++;
        node=node->next;
    }
    return count;
}

int main(){
    struct node *S1=NULL;
    struct node *S2=NULL;
    int n=1;
    while(1){
        printf("Enter your choice (1 for Enqueue, 2 for Dequeue, 3 for Exit): ");
        int z;
        scanf("%d",&z);
        if(z==1){ 

            printf("Enter the number of elements to be Enqueued: ");
            scanf("%d",&n);
            if(n<=0){
                printf("Invalid !");
                return 0;
            }
            printf("Enter data: ");
            while(S2!=NULL){
                push(&S1,pop(&S2));
            }
            for(int i=1;i<=n;i++){
                int x;
                scanf("%d",&x);
                push(&S1,x);
            }
            while(S1!=NULL){
                push(&S2,pop(&S1));
            }
            printf("Queue now  : ");
            printf("\nQueue size : %d",printStack(S2));
            printf("\n");
        }
        else if(z==2){
            if(S2==NULL){
                printf("There is nothing to dequeue,so bye!...");
                break;
            }
            printf("The dequeued element is: %d\n",pop(&S2));
            printf("Queue now  : ");
            printf("\nQueue size : %d",printStack(S2));
            printf("\n");

        }
        else{
            printf("Queue operations completed, Bye!...");
            break;
        }
    }
    return 0;
}