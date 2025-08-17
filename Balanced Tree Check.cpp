/*

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
    int fun(Node* root, bool& valid){
        if(!root) return 0;
        int l=fun(root->left, valid);
        int r=fun(root->right, valid);
        if(abs(l-r) > 1)valid = 0;
        return 1 + max(l,r);
    }
    bool isBalanced(Node* root) {
        if(!root)return true;
        bool valid = true;
        fun(root,valid);
        return valid;
    }
};



Question Link: https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1