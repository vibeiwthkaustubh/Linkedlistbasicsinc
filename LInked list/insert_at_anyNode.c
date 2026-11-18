#include <stdio.h>
#include <stdlib.h>

struct Node { 
    int data;
    struct Node* next;    
};

// Function to print the linked list
void print_list(struct Node* head) {
    for (struct Node *h = head; h != NULL; h = h->next) {
        printf("%d-> ", h->data);   // printing the node
        if (h->next == NULL) printf("NULL");
    }
}

// Function to add a node at any given position (using a double pointer)
void add_node_at_anynode(struct Node **head_ref, int x, int position) {
    // 1. Allocate memory and check for failure
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Dynamic memory allocation failed\n");
        return; 
    }
    node->data = x;
    node->next = NULL;

    // 2. Handle insertion at the very beginning (Head)
    if (position == 1) {
        node->next = *head_ref;
        *head_ref = node;
        return;
    }

    // 3. Traverse to the desired position
    struct Node *ptr = *head_ref;
    struct Node *prev = NULL;

    for (int i = 1; i < position && ptr != NULL; i++) {
        prev = ptr;
        ptr = ptr->next;
    }

    // 4. Check bounds and insert
    if (ptr == NULL && prev != NULL) {
        prev->next = node; // Appends at the end
    } else if (ptr == NULL) {
        printf("Position out of bounds\n");
        free(node); 
    } else {
        prev->next = node;
        node->next = ptr;
    }
}

// Function that will add the node to the end of the list
void add_node_to_end(struct Node *head, int x) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Dynamic memory allocation failed\n");
        return;          
    }
    node->data = x;
    node->next = NULL;

    if (head == NULL) {
        return; // Handled if list is empty
    }

    for (struct Node *n = head; n != NULL; n = n->next) {
        if (n->next == NULL) {
            n->next = node;
            break;
        }
    }
}

// Function that will add the node to the head
struct Node* add_node_to_head(struct Node *list, int x) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Dynamic memory allocation failed\n");
        return list;    
    }
    node->next = list;   // Adding the node 
    node->data = x;
    return node;
}

// Main function
int main() {
    struct Node *head = NULL;
 
    // Populate the list with 5 random nodes at the head
    for (int i = 0; i < 5; i++) {
        int value = rand() % 100;     // random value from 0 to 99
        head = add_node_to_head(head, value);  // save the new head back
    }

    // Add 878 to the end of the list
    add_node_to_end(head, 878);
   
    // Add 500 at position 3 using the double pointer reference (&head)
    add_node_at_anynode(&head, 500, 3);

    // Print the final list
    print_list(head);
    
    return 0;
}