

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *bfrHd = new ListNode(0);
        ListNode *aftrHd = new ListNode(0);
        ListNode *bfr = bfrHd;
        ListNode *aftr = aftrHd;
        ListNode *curr = head;
        while(curr){
            if(curr->val < x){
                bfr->next = curr;
                bfr = bfr->next;
            }else{
                aftr->next = curr;
                aftr = aftr->next;
            }
            curr = curr->next;
        }
        aftr->next=NULL;
        bfr->next=aftrHd->next;
        return bfrHd->next;
    }
};

link of question : https://leetcode.com/problems/partition-list/
