/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes


//1st Method

class Solution {
  public:
     void func(Node* root, int& cnt){
        if(!root)return;
        if(root->left || root->right)cnt++;
        func(root->left,cnt);
        func(root->right,cnt);
    }
    int countNonLeafNodes(Node* root) {
        // Code here
        int cnt=0;
        func(root,cnt);
        return cnt;
    }
};



//2nd Method

class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        if(!root) return 0;
        
        if(root->left || root->right) 
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
        
        return 0;
    }
};


Question Link: https://practice.geeksforgeeks.org/problems/count-non-leaf-nodes-in-binary-tree/1
// This code counts the non-leaf nodes in a binary tree by checking if a node has at least one child.