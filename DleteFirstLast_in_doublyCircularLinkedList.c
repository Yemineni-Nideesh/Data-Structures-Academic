#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// INSERT AT END
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;

  if (*head_ref == NULL) {
    new_node->next = new_node;
    new_node->prev = new_node;
    *head_ref = new_node;
    return;
  }

  // The last node is always directly accessible via (*head_ref)->prev
  struct Node* last = (*head_ref)->prev;

  new_node->next = *head_ref;
  new_node->prev = last;
  
  last->next = new_node;
  (*head_ref)->prev = new_node;
}


// PRINT LIST 
void printList(struct Node* head) {
  if (head == NULL) {
    printf("List is empty");
    return;
  }

  struct Node* temp = head;
  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != head);
}

// deleteFirstLast function
void deleteFirstLast(struct Node** head_ref){
 if (*head_ref == NULL) return;
  struct Node* a = *head_ref;
  struct Node* b= (*head_ref)->prev;
  (*head_ref)->prev->prev->next=(*head_ref)->next;
  (*head_ref)->next->prev=(*head_ref)->prev->prev;
  *head_ref = (*head_ref)->next;
  free(a);
  free(b);
  printList(*head_ref);
}

// MAIN FUNCTION
int main() {
    struct Node* head = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<n+1;i++){
      int x;
      printf("Enter data for node %d: ",i);
      scanf("%d",&x);
      insertAtEnd(&head, x); 
    }
    printf("The elements before deletion are: ");
    printList(head);
    printf("\n");
    printf("The elements after  deletion are: ");
    if(n<3){
      printf("List is empty");
      return 0;
    }
    deleteFirstLast(&head);
  return 0;
}
