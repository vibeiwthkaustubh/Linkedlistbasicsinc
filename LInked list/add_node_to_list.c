#include <stdio.h>
#include <stdlib.h>
 struct Node
 { 
   int data;
   struct Node* next;    
 };

 void print_list(struct Node* head){
    for(struct Node *h = head ; h!=NULL ; h = h->next ){
      printf("%d-> " , h->data);   // printing the node
      if(h->next==NULL) printf("NULL");

    }
 }

 // Function that will add the node to the list 
  struct Node* add_node_to_list(struct Node *list , int x){
    struct Node *node = malloc(sizeof(struct Node));
      if(node == NULL){
        printf("Dyanmic memory allocation failed");  
        return list;    
    }
      node->next = list;   // Adding the node 
      node->data = x;
      return node;
  }
 

// Main function

int main()
{
    
    struct Node *head = NULL;
 
    
   struct Node *newHead = add_node_to_list(head,20);
    newHead = add_node_to_list(newHead,30);
   newHead = add_node_to_list(newHead,40);

   print_list(newHead);
    return 0;
}