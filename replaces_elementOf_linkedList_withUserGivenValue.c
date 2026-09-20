
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

void replacelnLL(struct Node* node,int tobereplaced,int toreplacewith){

while (node != NULL) { 
if(node->data==tobereplaced){
node->data=toreplacewith;
}
node = node->next; 
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
int y,z;
printf("Enter the element to be replaced: ");
scanf("%d",&y);

printf("Enter the element to replace with: ");
scanf("%d",&z);




if (!searchNode(&head, y)) { 
printf("\n%d is Not in the list!", y); 

} 
else{

printf("The elements before replacement are: ");

printList(head); 





replacelnLL(head,y,z);



printf("\nThe elements after  replacement are: ");
printList(head); 


}
}
