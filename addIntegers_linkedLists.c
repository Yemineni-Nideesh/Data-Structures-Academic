// Header Files
#include <stdio.h> 
#include <stdlib.h>

// Define a node 
struct Node { 
    int data; 
    struct Node* next;
}; 

// Insert at the beginning 
void insertAtBeginning(struct Node** head_ref, int new_data) { 
    // Allocate memory for a new node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    // insert the elements
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    // Move head to new node 
    (*head_ref) = new_node; 
} 

// Insert a node after a node 
void insertAfter(struct Node* prev_node, int new_data) { 
    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); new_node->data = new_data; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
}

// Insert at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) { 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* last = *head_ref;
    new_node->data = new_data; 
    new_node->next = NULL;

    if (*head_ref == NULL) { 
        *head_ref = new_node; 
        return; 
    } 
    while (last->next != NULL){
        last = last->next; 
    }
    last->next = new_node; 
    return; 
} 

// Delete a node 
void deleteNode(struct Node** head_ref, int key) { 
    struct Node *temp = *head_ref, *prev; 
    if (temp != NULL && temp->data == key) { *head_ref = temp->next; 
        free(temp); 
        return; 
    } 
    // Find the key to be deleted 
    while (temp != NULL && temp->data != key) { 
      prev = temp; 
      temp = temp->next; 
    } 
    // If the key is not present 
    if (temp == NULL) return; 
    // Remove the node 
    prev->next = temp->next; 
    free(temp); 
} 

// Print the linked list 
void printList(struct Node* node) { while (node != NULL) { 
printf(" %d ", node->data); 
node = node->next; 
} 
}

//base^exp function
int f(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

//addIntegers Function
struct Node* addIntegers(struct Node** head1,struct Node** head2){
    struct Node* head=NULL;
    struct Node* a=*head1;struct Node* b=*head2;
    int m=0;int n=0;int num1=0;int num2=0;
    do{
        m++;
        *head1=(*head1)->next;
    }while(*head1!=NULL);
    do{
        n++;
        *head2=(*head2)->next;
    }while(*head2!=NULL);
    *head1=a;*head2=b;
    do{
        num1=num1+((*head1)->data)*f(10,m-1);
        *head1=(*head1)->next;
        m--;
    }while(*head1!=NULL);
    do{
        num2=num2+((*head2)->data)*f(10,n-1);
        *head2=(*head2)->next;
        n--;
    }while(*head2!=NULL);
    int result=num1+num2;
    int k = 0;
    int temp_result = result;
    if (temp_result == 0) {
        k = 1;
    } else {
        while (temp_result > 0) {
            k++;
            temp_result /= 10;
        }
    }
    int r=0;
    for(int i=k-1;i>=0;i--){
        r=(result/f(10,i));
        result=result-r*f(10,i);
        insertAtEnd(&head,r);
    }
    return head;
}

// Main Function
int main() {
    struct Node* head1 = NULL;
    int n;
    printf("Enter the number of nodes for the first  linked list: ");
    scanf("%d",&n);
    for(int i=1;i<n+1;i++){
        int x;
        printf("Enter data for node %d: ",i);
        scanf("%d",&x);
        insertAtEnd(&head1, x); 
    }
    struct Node* head2 = NULL;
    int m;
    printf("Enter the number of nodes for the second linked list: ");
    scanf("%d",&m);
    for(int j=1;j<m+1;j++){
        int y;
        printf("Enter data for node %d: ",j);
        scanf("%d",&y);
        insertAtEnd(&head2, y); 
    }
    if(n==0 && m!=0){
        printf("Resultant Linked list is: ");
        printList(head2);
        return 0;
    }
    else if(m==0 && n!=0){
        printf("Resultant Linked list is: ");
        printList(head1);
        return 0;
    }
    else if(m==0 && n==0){
        printf("The Linked list is empty ");
        return 0;
    }
    else{
    printf("Resultant Linked list is: ");
    printList(addIntegers(&head1,&head2));
    return 0;
    }
}
