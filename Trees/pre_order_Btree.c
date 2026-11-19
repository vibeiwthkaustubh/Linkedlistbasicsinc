#include <stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;

};


struct Node* add_to_left(struct Node* root , int val){
   struct Node* node = malloc(sizeof(struct Node));
   if(node==NULL){
    printf("Dynamic memory allocation failed");
    return NULL;
   }
   root->left = node;
   node->val = val;
   node->left = NULL;
   node->right = NULL;
   return node;
   
}

struct Node* add_to_right(struct Node* root , int val){
    struct Node* node = malloc(sizeof(struct Node));
    if(node==NULL){
        printf("Dynamic memory allocation failed");
        return NULL;
    }
    root->right = node;
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    return node;
}


 struct Node* create_root(int val){
    struct Node* node = malloc(sizeof(struct Node));
    if(node==NULL){
        printf("Dynamic memory allocation failed");
        return NULL;
    }
     node->left = NULL;
     node->right = NULL;
     node->val = val;
     return node;
 }

 // post order function
 void post_order(struct Node* root ){
   
    if(root!=NULL){
        post_order(root->left);       
        post_order(root->right);
        printf("%d -> " , root->val);
      
    }
 }

 void 

 void in_order(struct Node* root ){
   
    if(root!=NULL){
        in_order(root->left);    
        printf("%d -> " , root->val);   
        in_order(root->right);
    }    
 }
int main(){
 struct Node* root = create_root(10);
 root->left =  add_to_left(root , 20);
 root->right = add_to_right(root,30);

 root->left->left = add_to_left(root->left , 40);
 root->left->right = add_to_right(root->left , 50);

 root->right->left = add_to_left(root->right , 60);
 root->right->right = add_to_right(root->right , 70);

//  printf("%d , %d , %d , ", root->val , root->left->val , root->right->val);
//  printf("%d , %d , %d , %d ", root->left->left->val , root->left->right->val , root->right->left->val , root->right->right->val);

pre_order(root);
printf("\n");
in_order(root);



}