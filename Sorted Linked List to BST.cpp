/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    
    TNode *sortedListToBST(LNode *head) {
        // code here
        if(!head) return NULL;
        if(!head->next) return new TNode(head->data);
        LNode*fast=head, *slow=head, *mid=slow;
        
        while(fast && fast->next){
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        mid->next = NULL;
        TNode* node = new TNode(slow->data);
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);
        
        return node;
        
    }
};