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
    // bool fun(TreeNode *root, int tar, int sum){
    //     if(!root) return false;
    //     if(sum == tar) return true;
    //     // if(sum != tar) return false;
    //     if(root->left && sum + root->left->val < tar){
    //         sum += root->val;
    //         return fun(root->left, tar, sum);
    //         sum -= root->val;
    //     }if(root->right && sum + root->right->val < tar){
    //         sum += root->val;
    //         return fun(root->right, tar, sum);
    //         sum -= root->val;
    //     }
    //     return true;
    // }
    bool hasPathSum(TreeNode* root, int tar) {
        if(!root) return false;
        if(!root->left && !root->right && tar == root->val) return true;
        tar -= root->val;
        return hasPathSum(root->left, tar) || hasPathSum(root->right, tar);
    }
};




Question Link : https://leetcode.com/problems/binary-tree-path-sum/