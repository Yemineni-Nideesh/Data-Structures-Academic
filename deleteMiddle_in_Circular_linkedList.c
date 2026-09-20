#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};


// Insert at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) { 

  // allocate memory for a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the elements
   new_node->data = new_data;

  if (*head_ref == NULL) {
   *head_ref = new_node;
   new_node->next = *head_ref;
   return;
   }
  
  struct Node* temp = *head_ref;
  
  while (temp->next != *head_ref) {
     temp = temp->next;
  }

  temp->next = new_node;  
  new_node->next = (*head_ref);

  // head points to newNode
  (*head_ref) = new_node; 
} 


// Insert at the end of the linked list

void insertAtEnd(struct Node** head_ref, int new_data) { 

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;

  struct Node* last = *head_ref;

 if (*head_ref == NULL) {
    *head_ref = new_node;
    new_node->next= *head_ref; 
    return;
  }

 while (last->next != *head_ref){
     last = last->next;
  }
  last->next = new_node;
  new_node->next = *head_ref;  
} 

// Delete a node 
void deleteNode(struct Node** head_ref, int key) { 
 
  if (*head_ref==NULL) return;
  struct Node *temp = *head_ref;
  struct Node *prev;
  
  
  if (temp->data == key) {
  
     struct Node* temp1 = *head_ref;
  
  while (temp1->next != *head_ref) {
         temp1 = temp1->next;
     }

     temp1->next = temp->next;
     *head_ref = temp->next;
     free(temp); 
     return;
  }

  // Find the key to be deleted
  
  do{
   prev = temp;
   temp = temp->next;
  }while (temp!= *head_ref && temp->data != key); 

  // If the key is not present
  if (temp == *head_ref) return;

  // Remove the node
   prev->next = temp->next;
   free(temp);

} 



// Print the linked list
void printList(struct Node* head) { 

if (head== NULL) return;

struct Node* node = head;

do {
        printf("%d ", node->data);
        node = node->next;
    } while ( node != head);

}

//deleteMiddle function
void deleteMiddle(struct Node* head){

if (head== NULL) return;

struct Node* node = head;
int n=0;
int max=node->data;
do {
    if((node->data)>max){
            max=node->data;
        }
        n++;
        node = node->next;
    } while ( node != head);

node = head;
int c=0;
    do {c++;
    if(c==((n/2)+1)){
        node->data=max+1;
        break;
    }
    node=node->next;
    } while ( node != head);
    deleteNode(&head,max+1);
    node=head;
    n--;
    if(n%2==1){
        int d=0;
    do {d++;
    if(d==((n/2)+1)){
        node->data=max+2;
        break;
    }
    node=node->next;
    } while ( node != head);
    deleteNode(&head,max+2);
    }
        
    }
    
// Main Function

int main() {
struct Node* head = NULL;
int n;
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
printf("The elements before deletion are: ");
printList(head);
deleteMiddle(head);
printf("\nThe elements after  deletion are: ");
printList(head);


}