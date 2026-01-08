class Solution {
  public:
    void print(Node*root, vector<int>&res, int l, int h){
        if(!root) return;
        print(root->left, res, l, h);
        if(root->data >= l && root->data <= h)
        res.push_back(root->data);
        print(root->right, res, l, h);
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        // code here
        vector<int>res;
        print(root, res, low, high);
        return res;
    }
};



Question Link : https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range/