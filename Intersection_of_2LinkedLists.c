
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


// Print the linked list main
void printList(struct Node* node) { 

	while (node != NULL) { 
		printf(" %d ", node->data); 
		node = node->next; 
	} 
}



struct Node* intersectionList(struct Node* head1,struct Node* head2){

	struct Node*node=head2;

	struct Node* head=NULL;
	while (head1!= NULL) { 
		while (head2!= NULL) { 
			if((head1->data)==(head2->data))
			{
			insertAtEnd(&head, head1->data); 
			};
		head2=head2->next;
		} 
		head2=node;
		head1=head1->next;
	} 


	printList(head);
	return head;
}



// Main Function
int main() { 

	int m,n;
	struct Node* L1 = NULL; 
	printf("Enter the number of nodes of first linked list (m): ");
	scanf("%d",&m);
	
	if(m<=0){
		printf("Not valid");
		return 0;
	}
	
	printf("Enter data for node 1: ");
	int a;
	scanf("%d",&a);
	insertAtBeginning(&L1, a); 
	
	for(int i=2;i<m+1;i++){
		int x;
		printf("Enter data for node %d: ",i);
		scanf("%d",&x);
		insertAtEnd(&L1, x); 
	}
	
	struct Node* L2 = NULL; 
	printf("Enter the number of nodes of second linked list (n): ");
	scanf("%d",&n);
	
	if(n<=0){
		printf("Not valid");
		return 0;
	}
	printf("Enter data for node 1: ");
	int b;
	scanf("%d",&b);
	insertAtBeginning(&L2, b); 
	
	for(int i=2;i<n+1;i++){
		int y;
		printf("Enter data for node %d: ",i);
		scanf("%d",&y);
		insertAtEnd(&L2, y); 
	}

	printf("The resultant linked list is: ");
	intersectionList(L1,L2);

}

