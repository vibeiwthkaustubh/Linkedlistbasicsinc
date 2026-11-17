#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

/* helper: allocate and initialise one node */
struct Node *create_node(int x) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Dynamic memory allocation failed\n");
        return NULL;
    }
    node->val = x;
    node->next = NULL;
    return node;
}

void print_list(struct Node *head) {
    for (struct Node *h = head; h != NULL; h = h->next)
        printf("%d-> ", h->val);
    printf("NULL\n");
}

/* Every function below takes the head and RETURNS the (possibly new) head.
   Always call them like:  head = function(head, ...);                    */

/* a) add node to list (in front) */
struct Node *add_node_to_list(struct Node *list, int x) {
    struct Node *node = create_node(x);
    if (node == NULL) return list;      // list unchanged on failure
    node->next = list;
    return node;
}

/* b) insert at beginning */
struct Node *insert_at_beginning(struct Node *head, int x) {
    struct Node *node = create_node(x);
    if (node == NULL) return head;
    node->next = head;
    return node;                        // new node is the new head
}

/* c) insert at end */
struct Node *insert_at_end(struct Node *head, int x) {
    struct Node *node = create_node(x);
    if (node == NULL) return head;

    if (head == NULL)                   // empty list: node becomes the head
        return node;

    struct Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = node;
    return head;                        // head unchanged
}

/* d) insert at a position (0 = front, 1 = after first node, ...) */
struct Node *insert_at_position(struct Node *head, int pos, int x) {
    if (pos < 0) {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 0)
        return insert_at_beginning(head, x);

    struct Node *p = head;
    for (int i = 0; i < pos - 1 && p != NULL; i++)
        p = p->next;
    if (p == NULL) {
        printf("Position %d is beyond the list length\n", pos);
        return head;
    }

    struct Node *node = create_node(x);
    if (node == NULL) return head;
    node->next = p->next;
    p->next = node;
    return head;
}

/* e) find node with value x and add newval after it */
struct Node *insert_after_value(struct Node *head, int x, int newval) {
    for (struct Node *p = head; p != NULL; p = p->next) {
        if (p->val == x) {
            struct Node *node = create_node(newval);
            if (node == NULL) return head;
            node->next = p->next;
            p->next = node;
            return head;
        }
    }
    printf("%d not found\n", x);
    return head;
}

/* f) delete first node with value x */
struct Node *delete_node_from_list(struct Node *head, int x) {
    struct Node *curr = head, *prev = NULL;

    while (curr != NULL && curr->val != x) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("%d not found\n", x);
        return head;
    }

    if (prev == NULL)                   // deleting the head
        head = curr->next;
    else
        prev->next = curr->next;

    free(curr);
    return head;
}

void free_list(struct Node *head) {
    while (head != NULL) {
        struct Node *tmp = head->next;
        free(head);
        head = tmp;
    }
}

int main(void) {
    struct Node *head = NULL;

    head = add_node_to_list(head, 30);
    printf("a) add 30:               "); print_list(head);

    head = insert_at_beginning(head, 10);
    printf("b) insert 10 at start:   "); print_list(head);

    head = insert_at_end(head, 50);
    printf("c) insert 50 at end:     "); print_list(head);

    head = insert_at_position(head, 1, 20);
    printf("d) insert 20 at pos 1:   "); print_list(head);

    head = insert_after_value(head, 30, 40);
    printf("e) insert 40 after 30:   "); print_list(head);

    head = delete_node_from_list(head, 10);
    printf("f) delete 10 (head):     "); print_list(head);

    head = delete_node_from_list(head, 50);
    printf("f) delete 50 (last):     "); print_list(head);

    head = delete_node_from_list(head, 30);
    printf("g) delete 30 (form middle):    "); print_list(head);

    delete_node_from_list(head , 474);
    free_list(head);
    return 0;
}