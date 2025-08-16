/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution

//1st Method

class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    void func(Node* root, int& cnt){
        if(!root)return;
        if(!root->left && !root->right) cnt++;
        func(root->left,cnt);
        func(root->right,cnt);
    }
    int countLeaves(Node* root) {
        // write code here
        int cnt=0;
        func(root,cnt);
        return cnt;
    }
};



//2nd Method

class Solution {
  public:
    int countLeaves(Node* root) {
        if(!root)return 0;
        
        if(!root->left && !root->right) return 1;
        
        return countLeaves(root->left) + countLeaves(root->right);
    }
};


Question Link: https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1