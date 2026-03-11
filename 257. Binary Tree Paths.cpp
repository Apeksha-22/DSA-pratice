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
    void path(TreeNode *root, vector<int>&temp, vector<string>&res){
        temp.push_back(root->val);
        if(!root->left && !root->right){
            string s="";
            for(int i=0; i<temp.size(); i++){
                s += to_string(temp[i]);
                if(i != temp.size()-1)
                s += "->";
            }
            res.push_back(s);
            // temp.clear();
            return;
        }
        if(root->left && !root->right){
        path(root->left, temp, res);
        temp.pop_back();
        }
        if(root->right && !root->left){
        path(root->right, temp, res);
        temp.pop_back();
        }
        if(root->left && root->right){
           path(root->left, temp, res);
           temp.pop_back();
           path(root->right, temp, res);
           temp.pop_back();
        }
        // temp.pop_back();
        // temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        vector<int>temp;
        path(root, temp, res);
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<"  ";
        }
        return res;
    }
};


Question Link : https://leetcode.com/problems/binary-tree-paths/