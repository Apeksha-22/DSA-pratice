/*
// Tree Node
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
    void left(Node*root, vector<int>&res){
        if(!root)return;
        if(!root->left && !root->right) return;
        res.push_back(root->data);
        if(root->left)
        left(root->left,res);
        else
        left(root->right,res);
    }
    
    void leaf(Node*root, vector<int>&res){
        if(!root)return;
        if(!root->left && !root->right)
        res.push_back(root->data);
        leaf(root->left,res);
        leaf(root->right,res);
    }
    
    void right(Node*root, vector<int>&tem){
        if(!root)return;
        if(!root->left && !root->right) return;
        tem.push_back(root->data);
        if(root->right)
        right(root->right,tem);
        else
        right(root->left,tem);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>res;
        vector<int>tem;
        res.push_back(root->data);
        if(!root->left && !root->right) return res;
        left(root->left,res);
        leaf(root,res);
        right(root->right,tem);
        reverse(tem.begin(),tem.end());
        for(int i=0; i<tem.size(); i++)
        res.push_back(tem[i]);
        return res;
    }
};


Question Link : https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1