#include <stdio.h>
#include <stdlib.h>
 struct Node
 { 
   int data;
   struct Node* next;    
 };

 // function add the element at head
 void print_list(struct Node* head){
    for(struct Node *h = head ; h!=NULL ; h = h->next ){
      printf("%d-> " , h->data);   // printing the node
      if(h->next==NULL) printf("NULL");

    }
 }



  struct Node* add_node_to_head(struct Node *list , int x){
    struct Node *node = malloc(sizeof(struct Node));
      if(node == NULL){
        printf("Dyanmic memory allocation failed");  
        return list;    
    }
      node->next = list;   // Adding the node 
      node->data = x;
      return node;
  }



 // Function that will add the node to the list in the last 
  void add_node_to_end(struct Node *head , int x){
    struct Node *node = malloc(sizeof(struct Node));
      if(node == NULL){
        printf("Dyanmic memory allocation failed and the head was retrned");          
    }
     for(struct Node *n = head ; n!=NULL  ; n=n->next){
      if(n->next==NULL){
        n-> next = node;
        node->data = x;
        break;
      }
     }
       
  }
 

// Main function

int main()
{
    
    struct Node *head = NULL;
 
  
    for (int i = 0; i < 5; i++) {
        int value = rand() % 100;      // random value from 0 to 99
        head = add_node_to_head(head, value);  // save the new head back
    }

    add_node_to_end(head , 878);
   

   print_list(head);
    return 0;
}