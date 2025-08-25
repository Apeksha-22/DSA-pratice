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
    vector<vector<int>> verticalOrder(Node *root) {
        queue<pair<Node*,int>>q;
        vector<vector<int>>res;
        map<int,vector<int>>mp;
        
        q.push({root,0});
        while(!q.empty()){
            Node*temp = q.front().first;
            int idx = q.front().second;
            q.pop();
            mp[idx].push_back(temp->data);
            if(temp->left)
            q.push({temp->left, idx-1});
            if(temp->right)
            q.push({temp->right, idx+1});
        }
        
        for (auto& x : mp)
        res.push_back(x.second);
        
        return res;
    }
};




Question Link : https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1