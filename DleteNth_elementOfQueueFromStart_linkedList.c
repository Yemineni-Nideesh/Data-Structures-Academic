// C program to implement queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node of the linked list
typedef struct Node {
    int data;
    struct Node* next;
} node;

// Define the structure for the queue
typedef struct Queue {
    node* front;
    node* rear;
} queue;

// Function to create a new node
node* createNode(int data)
{
    // Allocate memory for a new node
    node* newNode = (node*)malloc(sizeof(node));
    // Check if memory allocation was successful
    if (newNode == NULL)
        return NULL;
    // Initialize the node's data and next pointer
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
queue* createQueue()
{
    // Allocate memory for a new queue
    queue* newQueue = (queue*)malloc(sizeof(queue));
    // Initialize the front and rear pointers of the queue
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(queue* q)
{
    return q->front == NULL;
}

// Function to add an element to the queue
void enqueue(queue* q, int data)
{
    // Create a new node with the given data
    node* newNode = createNode(data);
    // Check if memory allocation for the new node was successful
    if (!newNode) {
        printf("Queue Overflow!\n");
        return;
    }
    // If the queue is empty, set the front and rear pointers to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    // Add the new node at the end of the queue and update the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;

}

// Function to remove an element from the queue
int dequeue(queue* q)
{
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    // Store the front node and update the front pointer
    node* temp = q->front;
    q->front = q->front->next;
    // If the queue becomes empty, update the rear pointer
    if (q->front == NULL)
        q->rear = NULL;
    // Store the data of the front node and free its memory
    int data = temp->data;
    free(temp);
    return data;
}

// Function to print elements of the queue from front End

void printQueue( queue* Q)
{
    node *temp = Q ->front;

    while(temp)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    queue* Q = createQueue();
    int n,N;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    if(n<=0){
      printf("Invalid!");
      return 0;
    }
    printf("Enter elements into the queue : ");
    for(int i=1;i<=n;i++){
	    int x;
	    scanf("%d",&x);
	    enqueue(Q, x);
    }
    printf("Enter N : ");
    scanf("%d",&N);
    if(N>n || N<=0){
	    printf("Error: Invalid position");
	    return 0;
    }
    else{
	    int count=1;
	    node *temp = Q ->front;
	    while(temp){
            if(N==1){
                    dequeue(Q);
                    break;
            }
            if(count==N-1){
                node *t = temp->next->next;
                free(temp->next);
                temp->next=t;
                break;
            }
            temp = temp->next;
            count++;
	    }
	    printf("The remaining queue elements are: ");
	    printQueue(Q);
    }
    return 0;
}
