/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSym(TreeNode* p, TreeNode* q){
        if(!p && q || p && !q)return false;
        if(!p && !q) return true;
        if(p->val != q->val)return false;

        return isSym(p->left, q->right) && isSym(p->right, q->left);
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSym(root->left,root->right);
    }
};



Question Link : https://leetcode.com/problems/symmetric-tree/