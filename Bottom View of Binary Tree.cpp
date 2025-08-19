/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    void find(Node*root, int pos, int& l, int& r){
        if(!root) return;
        
        l = min(l,pos);
        r = max(r,pos);
        find(root->left, pos-1, l, r);
        find(root->right, pos+1, l, r);
    }
    void Bview(Node* root, vector<int>&res, vector<int>&lvl, int l, int pos){
        if(!root)return;
        
        if(lvl[pos] <= l){
            lvl[pos] = l;
            res[pos] = root->data;
        }
        Bview(root->left, res, lvl, l+1, pos-1);
        Bview(root->right, res, lvl, l+1, pos+1);
    }
    vector<int> bottomView(Node *root) {
        // Your Code Here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>res(r-l+1);
        vector<int>lvl(r-l+1,INT_MIN);
        
        Bview(root,res,lvl,0, -1*l);

        return res;
    }
};


Question Link : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1