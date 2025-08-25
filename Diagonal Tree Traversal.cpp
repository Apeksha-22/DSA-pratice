/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void find(Node*root, int&l, int pos){
        if(!root)return;
        l=max(pos,l);
        find(root->left,l,pos+1);
        find(root->right,l,pos+1);
    }
    void dig(Node*root, int pos, vector<vector<int>>&temp){
        if(!root)return;
        
        temp[pos].push_back(root->data);
        dig(root->left, pos+1, temp);
        dig(root->right, pos, temp);
    }
    vector<int> diagonal(Node *root) {
        // code here
        int l=0;
        find(root,l,0);
        vector<int>res;
        vector<vector<int>>temp(l+1);
        dig(root,0,temp);
        
        for(int i=0; i<temp.size(); i++)
        for(int j=0; j<temp[i].size(); j++)
        res.push_back(temp[i][j]);
        
        return res;
    }
};




Question Link : https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1