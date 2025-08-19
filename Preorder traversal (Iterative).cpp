// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        stack<Node*>st;
        vector<int>res;
        st.push(root);
        while(!st.empty()){
            Node* temp= st.top();
            st.pop();
            res.push_back(temp->data);
            if(temp->right)
            st.push(temp->right);
            if(temp->left)
            st.push(temp->left);
        }
        return res;
    }
};

Question Link : https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/1