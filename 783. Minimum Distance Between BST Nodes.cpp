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
    void find(TreeNode*root, int& prev, int& diff){
        if(!root) return;
        find(root->left, prev, diff);
        if(prev != -1)
        diff = min(diff, abs(prev - root->val));
        prev = root->val;
        find(root->right, prev, diff);
    }
    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int diff = INT_MAX;
        find(root, prev, diff);
        return diff;

    }
};



Question Link : https://leetcode.com/problems/minimum-distance-between-bst-nodes/