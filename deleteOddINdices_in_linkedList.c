#include <stdio.h> 
#include <stdlib.h> 

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

// Insert at the end of the linked list

void insertAtEnd(struct Node** head_ref, int new_data) { struct 

Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
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

// Search a node 
int searchNode(struct Node** head_ref, int key) { struct Node* current = *head_ref; 
while (current != NULL) { 
if (current->data == key) return 1; 
current = current->next; 
} 
return 0;
} 


// Print the linked list 
void printList(struct Node* node) { while (node != NULL) { 
printf(" %d ", node->data); 
node = node->next; 
} 
}

void deleteOddIndices(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* curr = *head_ref;
    struct Node* to_delete;

    *head_ref = curr->next; 
    free(curr);
    
    curr = *head_ref;
    while (curr != NULL && curr->next != NULL) {
        to_delete = curr->next;        
        curr->next = to_delete->next; 
        free(to_delete);               
        curr = curr->next;             
    }
}



// Main Function
int main() { 
int n;
struct Node* head = NULL; 
printf("Enter the number of nodes: ");
scanf("%d",&n);
printf("Enter data for node 1: ");
int a;
scanf("%d",&a);
insertAtBeginning(&head, a); 



for(int i=2;i<n+1;i++){
int x;
printf("Enter data for node %d: ",i);
scanf("%d",&x);
insertAtEnd(&head, x); 

}


printf("The elements of the linked list before deletion are: ");

printList(head); 



deleteOddIndices(&head);





printf("\nThe elements of the linked list after  deletion are: ");
printList(head); 


}

