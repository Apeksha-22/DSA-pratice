/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/


//1st Method

class Solution {
  public:
    void find(Node*root, int pos, int& l, int& r){
        if(!root) return;
        
        l = min(l,pos);
        r = max(r,pos);
        find(root->left, pos-1, l, r);
        find(root->right, pos+1, l, r);
    }
    void Tview(Node* root, vector<int>&res, vector<int>&lvl, int l, int pos){
        if(!root)return;
        
        if(lvl[pos] > l){
            lvl[pos] = l;
            res[pos] = root->data;
        }
        Tview(root->left, res, lvl, l+1, pos-1);
        Tview(root->right, res, lvl, l+1, pos+1);
    }
    vector<int> topView(Node *root) {
        // code here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>res(r-l+1);
        vector<int>lvl(r-l+1,INT_MAX);
        
        Tview(root,res,lvl,0, -1*l);

        return res;
    }
};


//2nd Method

class Solution {
  public:
    void find(Node*root, int pos, int& l, int& r){
        if(!root) return;
        
        l = min(l,pos);
        r = max(r,pos);
        find(root->left, pos-1, l, r);
        find(root->right, pos+1, l, r);
    }
    vector<int> topView(Node *root) {
        // code here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>res(r-l+1);
        vector<bool>fill(r-l+1,0);
        queue<Node*>q;
        queue<int>idx;
        
        q.push(root);
        idx.push(-1*l);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            int pos = idx.front();
            idx.pop();
            if(!fill[pos]){
                res[pos] = temp->data;
                fill[pos] = 1;
            }
            if(temp->left){
                q.push(temp->left);
                idx.push(pos-1);
            }
            if(temp->right){
                q.push(temp->right);
                idx.push(pos+1);
            }
        }
        return res;
    }
};



Question Link : https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/