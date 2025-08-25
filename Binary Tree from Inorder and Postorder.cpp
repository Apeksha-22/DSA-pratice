/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int find(vector<int>& in, int tar){
        for(int i=0; i<in.size(); i++){
            if(in[i] == tar)
            return i;
        }
        return -1;
    }
    
    Node *tree(vector<int>&in, vector<int>&post, int instrt, int inend, int idx){
        if(instrt > inend) return NULL;
        Node *root = new Node(post[idx]);
        int pos = find(in, root->data);
        
        root->right = tree(in, post, pos + 1, inend, idx - 1);
        root->left = tree(in, post, instrt, pos - 1, idx - (inend - pos)-1);
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        return tree(inorder, postorder, 0, inorder.size()-1, postorder.size()-1);
    }
};


Question Link : https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1