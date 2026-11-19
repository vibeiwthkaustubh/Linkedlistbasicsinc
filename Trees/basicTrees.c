#include<stdio.h>
#include<stdlib.h>

/*Binary tree is a tree where every node is will either be equal to 2 or be less that 2 (0 >=degree<=2)
Binary tree is tree which has at most 2 children for all its nodes.(It can be 1 or 0)
A tree is made up of nodes and edges    (N nodes in a tree means n-1 edges.)
*/
struct Node        // basic tree structure is made;
{
   int val ;
   struct Node* left;
   struct Node* right;
};

// prints a 3 node tree
void print(struct Node *root){
   for(int i = 0 ; i<3 ; i++){
    if(i==1){
        printf("val %d -> %d " , i , root->left->val);
    }
    else if(i==2){
        printf("val %d -> %d " , i , root->right->val);
    }
    else {
        printf("val %d -> %d " , i , root->val);
    }

   }
}

// void preorder traversal
void preorder(struct Node* root){
    if(root!=NULL){
        printf("data -> %d -> " , root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
// void postorder traversal
void postorder(struct Node* root){
    if(root!=NULL){
        
    }

}


// checks if the given node is a leaf node or not 
int ifleaf(struct Node* head)
{
   if(head->left==NULL && head->right==NULL) return 1;
   return 0;
}

// creating a node
struct Node* createnode(int x){
    struct Node *node = malloc(sizeof(struct Node));
    if(node==NULL){
        printf("Node creation failed NULL pointer is returned");
        return NULL;
    }

    node->left= NULL;
    node->right= NULL;
    node->val = x;
  return node;
}


//  Add a child node to left
// void insert_a_childInleft(struct Node *root , int x){
//     struct Node *node = malloc(sizeof(struct Node));
//     node->val = x;
//     node->right = NULL;
//     node->left  = NULL;
//     root->left = node;

// }

// Add a child node to right
// void insert_a_childInright(struct Node *root , int x){
//     struct Node *node = malloc(sizeof(struct Node));
//     node->val = x;
//     node->right = NULL;
//     node->left  = NULL;
//     root->right = node;

// }



int main(){


 struct Node *root = createnode(10);

 root->left = createnode(40);
 root->right = createnode(90);

 root->left->left = createnode(100);
 root->left->right = createnode(110);

 root->right->left = createnode(120);
 root->right->right = createnode(130);


preorder(root);

 if(ifleaf(root)) printf("yes it a leaf node");
 else printf("No it is not a leaf node");
    return 0;
}

