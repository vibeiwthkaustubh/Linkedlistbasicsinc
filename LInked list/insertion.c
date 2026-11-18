
    #include <stdio.h>
    #include <stdlib.h>
    struct ListNode {
        int val;
        struct ListNode *next;
    };
    
void print_list(struct ListNode* head){
        for(struct ListNode *h = head ; h!=NULL ; h = h->next ){
        printf("%d-> " , h->val);   // printing the node
        if(h->next==NULL) printf("NULL");

        }
    }

    struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        
        if(list1 == NULL) return list2;
        if(list2 ==NULL) return list1;
        
        struct ListNode* tail2 = NULL;
    struct ListNode* head = NULL;
    if(list1->val < list2->val  ){
        head = list1;
        tail2 = list2;
    }
    else{
        head = list2;
        tail2 = list1;
    }

    struct ListNode* tail = head;

    while(tail->next!=NULL && tail2!= NULL){
        
        if(tail2->val<tail->next->val){
            struct ListNode* temp = tail2->next;
            tail2->next = tail->next;

            tail->next = tail2;
            tail = tail->next;
            tail2 = temp;      
        }
        else{
            tail = tail->next;
        }
        
    
    }
    if (tail2 != NULL) tail->next = tail2;
    return head;

    }


    int main(){

        struct ListNode n1 = {1, NULL}, n2 = {3, NULL}, n3 = {5, NULL}, n4 = {7, NULL};
    struct ListNode m1 = {2, NULL}, m2 = {4, NULL}, m3 = {6, NULL};

    n1.next = &n2; n2.next = &n3; n3.next = &n4;
    m1.next = &m2; m2.next = &m3;

    struct ListNode* list1 = &n1;
    struct ListNode* list2 = &m1;
    
    struct ListNode* head = mergeTwoLists(list1 ,list2);

    print_list(head);

        return 0;
    }
    