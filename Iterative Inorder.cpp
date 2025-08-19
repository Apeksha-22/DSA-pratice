// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        //ismein hum yeh dekhege ki node kitni baar vis hua 
        //agar wo dusri baar visit kar rha hai toh data ko print kra de
        stack<Node*>st;
        stack<bool>s;
        vector<int>res;
        st.push(root);
        s.push(0);
        
        while(!st.empty()){
            Node* temp=st.top();
            st.pop();
            bool flg = s.top();
            s.pop();
            if(flg == 0){
                if(temp->right){
                    st.push(temp->right);
                    s.push(0);
                }
                st.push(temp);
                s.push(1);
                
                if(temp->left){
                    st.push(temp->left);
                    s.push(0);
                }
            }else{
                res.push_back(temp->data);
            }
        }
        return res;
    }
};



Question Link : https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/