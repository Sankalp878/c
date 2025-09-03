#include<stdio.h>
#include<stdlib.h>

// Define structure for Doubly Linked List node
typedef struct Node{
  int data;             // data value
  struct Node* prev;    // pointer to previous node
  struct Node* next;    // pointer to next node
}Node;

// Function to create a new node
Node* create_Node(int data){
  Node* newNode=(Node*)malloc(sizeof(Node)); // allocate memory
  newNode->data=data;   // set data
  newNode->next=NULL;   // initially no next
  newNode->prev=NULL;   // initially no prev
  return newNode;
}

// Insert a new node at the beginning
void insert_at_first(int data, Node** head){
  Node* newNode=create_Node(data);
  if (*head == NULL){         // if list is empty
    *head=newNode;            // new node becomes head
    return;
  }
  newNode->prev=NULL;         // new head has no prev
  (*head)->prev=newNode;      // old head's prev points to new node
  newNode->next=*head;        // new node's next points to old head
  *head=newNode;              // update head to new node
}

// Insert a new node at the end
void insert_at_end(int data,Node** head){
  Node* temp=*head;
  if(*head==NULL){            // if list is empty, just insert at first
    insert_at_first(data, head);
    return;
  }  
  Node* newNode=create_Node(data);
  newNode->next=NULL;         // last node's next = NULL
  while(temp->next!=NULL){    // traverse to last node
    temp=temp->next;
  }
  temp->next=newNode;         // link last node to new node
  newNode->prev=temp;         // new node's prev points to old last
}

// Insert a new node at a specific index (0-based)
void insert_at_index(int index,int data,Node** head){
  Node* newNode=create_Node(data);
  Node* temp=*head;
  if(index==0|| *head==NULL){ // if index is 0 or list is empty
    insert_at_first(data,head);
    return;
  }
  // Traverse to node just before the given index
  for(int i=0;temp!=NULL && i<index-1;i++){
    temp=temp->next;
  }
  if(temp==NULL){             // if index is out of range
    printf("index out of range");
    return;
  }
  newNode->next=temp->next;   // new node’s next = node currently at index
  if(temp->next!=NULL){       // if not inserting at end
    temp->next->prev=newNode; // fix back link
  }
  newNode->prev=temp;         // new node’s prev = node at index-1
  temp->next=newNode;         // node at index-1’s next = new node
}

// Display all nodes in the list
void Display_list(Node** head){
  if(*head==NULL){
    printf("Empty list");
    return;
  }
  Node* temp=*head;
  while(temp!=NULL){
    printf("\n%d",temp->data); // print data
    temp=temp->next;           // move forward
  }
}

// Delete a node at a given index (0-based)
void delete_node(int index, Node** head) {
    if (*head == NULL || index < 0) {   // invalid case
        printf("Index out of range\n");
        return;
    }

    Node* temp = *head;

    // Case 1: delete head node
    if (index == 0) {
        *head = temp->next;        // move head to next node
        if (*head != NULL) {
            (*head)->prev = NULL;  // remove back link of new head
        }
        free(temp);                // free old head
        return;
    }

    // Traverse to the node at given index
    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {            // index out of range
        printf("Index out of range\n");
        return;
    }

    // Case 2: delete middle or last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev; // fix next node's prev
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next; // fix prev node's next
    }

    free(temp); // free memory of deleted node
}

// Main function to test
int main(){
  Node* head=NULL;

  // Insert nodes
  insert_at_first(19,&head);
  insert_at_first(30,&head);
  insert_at_first(40, &head);
  insert_at_first(50, &head);
  insert_at_end(5,&head);
  insert_at_index(2, 70, &head);

  // Display current list
  Display_list(&head);

  printf("\nhello world\n");
  return 0;
}
