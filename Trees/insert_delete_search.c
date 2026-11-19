#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// creates a new node
struct Node* createNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insertion 
struct Node* insert(struct Node *root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

// Searching
int search(struct Node *root, int key) {
    if (root == NULL) return 0;
    if (key == root->data) return 1;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

// Deletion
struct Node* delete(struct Node *root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = delete(root->left, key);
    } else if (key > root->data) {
        root->right = delete(root->right, key);
    } else {
        // returning the number of child and freeing the node
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // 2 children: copy the smallest value of the right side, then delete it
        struct Node *min = root->right;
        while (min->left != NULL) min = min->left;
        root->data = min->data;
        root->right = delete(root->right, min->data);
    }
    return root;
}

// Prints the tree inorder (left, root, right)
void print(struct Node *root) {
    if (root == NULL) return;
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

int main() {
    struct Node *root = NULL;

    // Insert
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    printf("After insert: ");
    print(root);

    // Search
    printf("\nSearch 40: %s\n", search(root, 40) ? "true" : "false");
    printf("Search 90: %s\n", search(root, 90) ? "true" : "false");

    // Delete
    root = delete(root, 20);   // leaf
    printf("Delete 20 (no child): ");
    print(root);

    root = delete(root, 30);   // one child
    printf("\nDelete 30 (one child): ");
    print(root);

    root = delete(root, 50);   // two children
    printf("\nDelete 50 (two children): ");
    print(root);
    printf("\n");

    return 0;
}
