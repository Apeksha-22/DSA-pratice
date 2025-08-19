// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        stack<Node*>st;
        vector<int>res;
        st.push(root);
        while(!st.empty()){
            Node* temp= st.top();
            st.pop();
            res.push_back(temp->data);
            if(temp->left)
            st.push(temp->left);
            if(temp->right)
            st.push(temp->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


Question Link : https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/