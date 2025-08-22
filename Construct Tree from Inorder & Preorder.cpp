// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    int find(vector<int>&inorder, int tar){
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == tar) return i;
        }
        return -1;
    }
    Node* tree(vector<int>&in, vector<int>&pre, int instrt, int inend, int idx){
        if(instrt > inend)return NULL;
        Node* root = new Node(pre[idx]);
        int pos = find(in,root->data);
        root->left = tree(in, pre, instrt, pos-1,idx+1);
        root->right = tree(in, pre, pos+1, inend, idx + (pos -instrt) + 1);
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        return tree(inorder, preorder, 0, inorder.size()-1, 0);
    }
};


Question Link : https://www.geeksforgeeks.org/problems/construct-tree-1/1