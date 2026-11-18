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
 // Function that will delete the node from the list, returns the new head
  struct Node* findanddelete(struct Node *list , int x){
     struct Node *head = list;    // keep the start of the list
     struct Node *prev = NULL;    // node just behind list

     while(list != NULL && list->data != x){
        prev = list;
        list = list->next;
     }

     // x was not found (or the list is empty), nothing to delete
     if(list == NULL) return head;

//  Deletion of the node from the list .  
     if(prev == NULL) head = list->next;   // deleting the head node
     else prev->next = list->next;         // deleting a middle or last node
     // free(list);   // use only when the node was made with malloc
     return head;
  }
 

// Main function

int main()
{    
struct Node n1 = {10, NULL}, n2 = {20, NULL}, n3 = {30, NULL}, n4 = {40, NULL}, n5 = {50, NULL};

n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;

struct Node* head = &n1;

head = findanddelete(head , 30);   // store the returned head
   print_list(head);
    return 0;
}