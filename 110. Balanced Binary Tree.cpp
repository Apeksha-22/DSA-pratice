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
    int fun(TreeNode *root){
        if(!root)return 0;
        int l = fun(root->left);
        if(l == -1) return -1;
        int r = fun(root->right);
        if(r == -1) return -1;
        // int res = ;
        if(abs(l-r) > 1)return -1;
        return 1 + max(l,r);
        // return res;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return 1;
        return fun(root) != -1; 
    }
};



Question Link : https://leetcode.com/problems/balanced-binary-tree/