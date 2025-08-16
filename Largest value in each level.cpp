// User function Template for C++

class Solution {
  public:
    void largest(Node* root, vector<int>&res){
        queue<Node*>q;
        Node* temp;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int maxe = INT_MIN;
            for(int i=0; i<n; i++){
                temp = q.front();
                q.pop();
                maxe = max(maxe,temp->data);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            res.push_back(maxe);
            

        }
    }
    vector<int> largestValues(Node* root) {
        // code here
        vector<int>res;
        largest(root, res);
        return res;
    }
};



Question Link: https://practice.geeksforgeeks.org/problems/largest-value-in-each-level/1