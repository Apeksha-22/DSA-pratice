/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */


//1st Method

class Solution {
  public:
    void rview(Node* root, vector<int>& res, int lvl){
        if(!root)return;
        
        if(lvl == res.size()){
            res.push_back(root->data);
        }
        
        rview(root->right, res, lvl+1);
        rview(root->left, res, lvl+1);
        
    }
    vector<int> rightView(Node *root) {
        vector<int>res;
        rview(root, res, 0);
        return res;
    }
};



//2nd Method

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  Code here
        if(!root)return{};
        queue<Node*>q;
        vector<int>res;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            res.push_back(q.front()->data);
            while(n--){
                Node* temp = q.front();
                q.pop();
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return res;
    }
};


Question Link : https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1