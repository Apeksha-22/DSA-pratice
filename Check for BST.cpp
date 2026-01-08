/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool check(Node*root, int& prev){
        if(!root) return 1;
        if(!check(root->left,prev))return false;
        if(prev >= root->data)
        return 0;
        prev = root->data;
        return check(root->right,prev);
    }
    bool isBST(Node* root) {
        // code here
        int  prev = INT_MIN;
        return check(root,prev);
    }
};



Question Link : https://www.geeksforgeeks.org/problems/check-for-bst/1