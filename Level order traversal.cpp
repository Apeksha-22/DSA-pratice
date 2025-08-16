/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void order(Node *root, vector<vector<int>>& res, vector<int>&temp){
        queue<Node*>q;
        Node* dum;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int i=0;
            while(i<n){
                dum = q.front();
                q.pop();
                temp.push_back(dum->data);
                if(dum->left)q.push(dum->left);
                if(dum->right)q.push(dum->right);
                i++;
            }if(i == n){
                res.push_back(temp);
                temp.clear();
            }
        }
    }
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>>res;
        vector<int>temp;
        order(root, res, temp);
        return res;
        
    }
};


//2nd method

class Solution {
public:
    void order(Node* root, int lvl, vector<vector<int>>& res) {
        if (!root) return;
        if (res.size() == lvl) {
            res.push_back({});
        }
        res[lvl].push_back(root->data);
        order(root->left, lvl + 1, res);
        order(root->right, lvl + 1, res);
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        order(root, 0, res);
        return res;
    }
};


Question Link : https://www.geeksforgeeks.org/binary-tree-level-order-traversal/