#include <stdio.h>
#include <stdlib.h>
 struct Node
 { 
   int data;
   struct Node* next;    
 };
 // Function to print the list.
 void print_list(struct Node* head){
    for(struct Node *h = head ; h!=NULL ; h = h->next ){
      printf("%d-> " , h->data);   // printing the node
      if(h->next==NULL) printf("NULL");
    }
 }
 // Function that will add the node to the list 
  void findandinsert(struct Node *list , int x , int newval){
    struct Node *node = malloc(sizeof(struct Node));
      if(node == NULL){
        printf("Dyanmic memory allocation failed");  
        return;   // stop here, do not use a NULL node
    }
     while(list != NULL && list->data!= x){
        list = list->next;
     }

     // x was not found (or the list is empty), so nothing to insert after
     if(list == NULL){
        free(node);
        return;
     }

//  Addition of the node in the list .  
     node->next = list->next;
     list->next = node;
     node->data = newval;
  }
 

// Main function

int main()
{    
struct Node n1 = {10, NULL}, n2 = {20, NULL}, n3 = {30, NULL}, n4 = {40, NULL}, n5 = {50, NULL};

n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;

struct Node* head = &n1;

findandinsert(head , 30 , 35);
   print_list(head);
    return 0;
}