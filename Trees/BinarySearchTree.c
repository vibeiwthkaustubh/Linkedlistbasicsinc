#include<stdio.h>
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

 // pre order function
  void pre_order(struct Node* root){
    if(root!=NULL){
        printf("%d -> " , root->val);
        pre_order(root->left);
        pre_order(root->right);
    }
  }

 // post order function
 void post_order(struct Node* root ){
   
    if(root!=NULL){
        post_order(root->left);       
        post_order(root->right);
        printf("%d -> " , root->val);
      
    }
 }



 void in_order(struct Node* root ){
   
    if(root!=NULL){
        in_order(root->left);    
        printf("%d -> " , root->val);   
        in_order(root->right);
    }    
 }
int main(){
 struct Node* root = create_root(54);
 root->left =  add_to_left(root , 52);
 root->right = add_to_right(root,56);

 root->left->left = add_to_left(root->left , 51);
 root->left->right = add_to_right(root->left , 53);

 root->right->left = add_to_left(root->right , 55);
 root->right->right = add_to_right(root->right , 57);

//  printf("%d , %d , %d , ", root->val , root->left->val , root->right->val);
//  printf("%d , %d , %d , %d ", root->left->left->val , root->left->right->val , root->right->left->val , root->right->right->val);

pre_order(root); printf("NULL");
printf("\n");
in_order(root);printf("NULL");



}