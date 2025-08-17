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
};
 */

//!st Method

class Solution {
  public:
    void lview(Node* root, vector<int>& res, int lvl){
        if(!root)return;
        
        if(lvl == res.size()){
            res.push_back(root->data);
        }
        
        lview(root->left, res, lvl+1);
        lview(root->right, res, lvl+1);
        
    }
    vector<int> leftView(Node *root) {
        vector<int>res;
        lview(root, res, 0);
        return res;
    }
};


//2nd Method

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
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
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return res;
    }
};


Question Link : https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/